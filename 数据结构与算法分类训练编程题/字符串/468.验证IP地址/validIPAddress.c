#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *validIPAddress(char * IP)
{
    if(IP == NULL)  return NULL;
    char *ipv4 = "IPv4";
    char *ipv6 = "IPv6";
    char *neither = "Neither"; 

    int len = strlen(IP);

    int cnt4 = 0;
    int cnt6 = 0;
    for(int i=0;i<len;i++)
    {
        if(IP[i] == ':') cnt6++;
        else if(IP[i] == '.') cnt4++;       
    }

    if(cnt4 == 3)
    {
        char *p[4];
        p[0] = strtok(IP,".");
        int j=1;
        while(IP != NULL)
        {
            p[j] = strtok(NULL,".");
            j++;
            if(j == 4)  break;
        }

        int ip4[4];
        int flag4 = 0;
        int sublen4 = 0;
        for(int i=0;i<4;i++)
        {
            if(p[i] == ""|| p[i] == NULL || (p[i][0] == '0'&&p[i][1]!='\0'))  return neither; //(p[i][0] == '0'&&p[i][1]!='\0') 坑1单个为0是对的，只有01这种才是错的 如192.01.0.1

            ip4[i] = atoi(p[i]);
            if(ip4[i]<0 || ip4[i] >255)
                return neither;
            
            sublen4 = strlen(p[i]);
            if(sublen4 > 3 || sublen4 <1)
                return neither;
            for(int j=0;j<sublen4;j++)
            {
                if(p[i][j]>'9'|| p[i][j]<'0') //坑2 用例出现1e1.0.0.1
                   return neither;
            }
        }
        return ipv4;
    }   
    else if(cnt6 == 7)
    {
        char *q[8];
        q[0] = strtok(IP,":");
        int k = 1;
        while(IP!=NULL)
        {
            q[k] = strtok(NULL,":");
            k++;
            if(k == 8)  break;
        }

        int sublen;
        for(int i=0;i<8;i++)
        {
            if(q[i] == "" || q[i] == NULL)
                return neither;

            sublen = strlen(q[i]);
            if(sublen > 4 || sublen <1) //长度不能超过4
                return neither;

            for(int j=0;j<sublen;j++)
            {
                if((q[i][j]<'0'|| q[i][j]>'9')&&(q[i][j]<'a'||q[i][j]>'f')&&(q[i][j]<'A'||q[i][j]>'F')) //坑3 出现不该出现的
                    return neither;
            }
        }           
        return ipv6;
    }
    else 
        return neither;
}