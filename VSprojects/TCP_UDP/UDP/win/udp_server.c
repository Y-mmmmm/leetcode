#include <stdio.h>
#include <winsock2.h>

#define BUF_LEN  100

int main(void)
{
    WSADATA wd;
    SOCKET ServerSock;
    char Buf[BUF_LEN] = {0};
    SOCKADDR ClientAddr;
    SOCKADDR_IN ServerSockAddr;
    int addr_size = 0;


    /* 初始化操作sock需要的DLL */
    WSAStartup(MAKEWORD(2,2),&wd);  

    /* 创建服务端socket */
    if(-1 == (ServerSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)))
    {
        printf("socket error!\n");
        exit(1);
    }

    /* 设置服务端信息 */
    memset(&ServerSockAddr, 0, sizeof(ServerSockAddr));     // 给结构体ServerSockAddr清零
    ServerSockAddr.sin_family = AF_INET;                      // 使用IPv4地址
    ServerSockAddr.sin_addr.s_addr = htonl(INADDR_ANY);     // 自动获取IP地址
    ServerSockAddr.sin_port = htons(1314);                  // 端口

    /* 绑定套接字 */

    if (-1 == (bind(ServerSock, (SOCKADDR*)&ServerSockAddr, sizeof(SOCKADDR))))
    {
        printf("bind error!\n");
        exit(1);
    }

    addr_size = sizeof(SOCKADDR);

    while (1)
    {
        /* 接受客户端的返回数据 */
        int str_len = recvfrom(ServerSock, Buf, BUF_LEN, 0, &ClientAddr, &addr_size);

        printf("客户端发送过来的数据为：%s\n", Buf);

        /* 发送数据到客户端 */
        sendto(ServerSock, Buf, str_len, 0, &ClientAddr, addr_size);

        /* 清空缓冲区 */
        memset(Buf, 0, BUF_LEN);  
    }

    /*如果有退出循环的条件，这里还需要清除对socket库的使用*/
    /* 关闭服务端套接字 */
    //closesocket(ServerSock);
    /* WSACleanup();*/

    return 0;
}
