#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_LEN  100

int main(void)
{
    
    char Buf[BUF_LEN] = {0}; //接收数据缓冲区
    int recv_len = 0;        //接收数据的长度

    
    struct sockaddr ClientAddr; //接收客户端的地址信息结构体;可以为空，有内核分配
    int addr_len = 0;           //接收地址的长度

    int listenfd;                       //listen socket 监听用的套接字
    int connectfd;                      //accept socket 连接用的套接字
    struct sockaddr_in ServerSockAddr;  //服务端地址信息结构体

    int optval = 1; 

    /* 创建服务端文件描述符 */
    /* 协议族：AF_INET ：IPV4 ；socket类型：SOCK_STREAM ：字节流 ；IP协议：IPPROTO_TCP ：TCP方式 */
    if (-1 == (listenfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)))
    {
        printf("socket error!\n");
        exit(1);
    }

    /* 设置服务端信息 */
    memset(&ServerSockAddr, 0, sizeof(ServerSockAddr));     // 给结构体ServerSockAddr清零
    ServerSockAddr.sin_family = AF_INET;                    // 使用IPv4地址
    ServerSockAddr.sin_addr.s_addr = htonl(INADDR_ANY);     // 自动获取IP地址
    ServerSockAddr.sin_port = htons(6666);                  // 端口


    // 设置地址和端口号可以重复使用  
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
    {
        printf("setsockopt error!\n");
        exit(1);
    }

    /* 绑定操作，绑定前加上上面的socket属性可重复使用地址 */
    //if (-1 == bind(listenfd, (struct sockaddr*)&ServerSockAddr, sizeof(struct sockaddr)))
    if (-1 == bind(listenfd, (struct sockaddr*)&ServerSockAddr, sizeof(ServerSockAddr)))
    {
        printf("bind error!\n");
        exit(1);
    }

    /* 进入监听状态，监听客户端的connect请求 */
    /* 参数：要监听的socket描述符；socket可以排队的最大连接个数 */
    if (-1 == (listen(listenfd, 10)))
    {
        printf("listen error!\n");
        exit(1);
    }

    addr_len = sizeof(struct sockaddr);

    //printf("------waiting for client's request------\n");

    while (1)
    {
        /* 监听客户端请求，accept函数返回一个新的套接字，发送和接收都是用这个套接字 */
        /* 输入参数：服务端listen socket描述符；客户端套接字地址结构体指针，用于返回客户端的协议地址；客户端套接字地址长度 
           返回参数：accept socket已连接的socket描述符
        */
        if (-1 == (connectfd = accept(listenfd, (struct sockaddr*)&ClientAddr, &addr_len)))
        {
            printf("accept error!\n");
            exit(1);
        }

        /* 接受客户端的返回数据 */
        if ((recv_len = recv(connectfd, Buf, BUF_LEN, 0)) < 0)
        {
            printf("recv error!\n");
            exit(1);
        }

        printf("客户端发送过来的数据为：%s\n", Buf);

        /* 发送数据到客户端 */
        send(connectfd, Buf, recv_len, 0);

        /* 关闭客户端套接字 */
        close(connectfd);

        /* 清空缓冲区 */
        memset(Buf, 0, BUF_LEN);  
    }

    return 0;
}

