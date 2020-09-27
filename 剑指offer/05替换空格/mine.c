#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//主要思路：先计算传进来的字符串的长度和空格长度，再开辟扩大后的内存空间
//然后逐个将原字符串塞进新开辟的空间，同时判断空格，有空格就替换，没空格就继续塞
//最后在字符串末尾加上'\0'
char* replaceSpace(char* s){
    int oglen = 0;
    int space_cnt = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    while(s[k] != '\0')
    {
        oglen++;
        if(s[k] == ' ')
        {
            space_cnt++;
        }
        k++;
    }
    
    int newlen = oglen + space_cnt*2 + 1;

    char *str = (char *)calloc(newlen,sizeof(char));
    if(str == NULL)
        return NULL;

    while(s[i] != '\0')
    {       
        if(s[i] == ' ')
        {
            str[j++] = '%';
            str[j++] = '2';
            str[j++] = '0';
        }
        else
        {
            str[j++] = s[i];           
        }
        i++;
    }
    str[j] = '\0';
    return str;

}

void main()
{
    char *ss = "we are happy.";
    printf("%s",replaceSpace(ss));

}
