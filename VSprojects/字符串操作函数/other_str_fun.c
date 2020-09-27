#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *funname[5] = {"music", "play", "A_led1", "led2", "led"};//自定义的函数名称列表
    char str[] = "led,100,0,80,15";//一个字符串，第一个逗号前的字符串设定为某个命令，后面的是参数
    char *cmd;//表示命令
    char *paras;//表示命令后的参数
    printf("str = %s\r\n", str);

    //strtok_r==================================
    /*
    char *strtok_r(char * __restrict__ _Str, const char * __restrict__ _Delim, char ** __restrict__ __last);
    参数：原始字符串，分隔符，切分后剩余的字符串
    返回值：切分掉的字符串
    */
    printf("\r\ntest [strtok_r] --------------------->\r\n");

    cmd = strtok_r(str, ",", &paras);

    printf("cmd:%s\r\n", cmd);      //获得字符串的第一串字符
    printf("paras:%s\r\n", paras);  //获取后续字符串
    printf("str:%s\r\n",str);       //------原str已经被破坏了！！！

    //strstr=====================================
    /*
    char *strstr(const char *_Str,const char *_SubStr);
    参数：原始字符串，要查找的子字符串
    返回值：子字符串在源字符串中首次出现的地址，无则返回NULL
    */
    printf("\r\ntest [strstr] --------------------->\r\n");
    char *ret;
    int i;
    for (i = 0; i < 5;i++)
    {
        ret = strstr(funname[i], cmd);
        if(ret!=NULL)
        {
            printf("find cmd in funname[%d]\r\n", i);
            printf("ret:%s\r\n", ret);
            break;
        }
    }
    if(i==5)
    {
        printf("can't find cmd in funname[]");
    }

    //strtok====================================
    /*
    char *strtok(char * __restrict__ _Str,const char * __restrict__ _Delim)
    参数：原始字符串，分隔符
    返回值：切分掉的字符串
    */
    printf("\r\ntest [strtok] --------------------->\r\n");
    char* para[4];
    para[0] = strtok(paras, ",");
    int j= 1;
    while(paras != NULL)
    {
        para[j++] = strtok(NULL, ",");
        if(j == 4)
            break;
    }
    printf("para[0]:%s\r\n", para[0]);
    printf("para[1]:%s\r\n", para[1]);
    printf("para[2]:%s\r\n", para[2]);
    printf("para[3]:%s\r\n", para[3]);

    //字符串转数字================================
    /*
    int atoi(const char *_Str);
    参数：字符串
    返回值：字符串对应的数字值
    */
    printf("\r\ntest [atoi] --------------------->\r\n");
    int p1,p2,p3,p4;
    p1= atoi(para[0]);
    p2= atoi(para[1]);
    p3= atoi(para[2]);
    p4= atoi(para[3]);
    printf("%d,%d,%d,%d\r\n",p1,p2,p3,p4);

    //测试不能转化为数字的字符串
    printf("atoi(hello): %d\r\n", atoi("hello"));

    //测试浮点型字符串
    printf("atoi(3.14): %d\r\n", atoi("3.14"));

    return 0;
}