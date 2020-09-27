#include <stdio.h>
#include <string.h>

/**
 * strlen - Find the length of a string
 * @s: The string to be sized
 */
size_t myStrlen(const char *s)
{
    const char *sc;
    for(sc = s; *sc != '\0'; ++sc);

    return sc-s;//让sc移动到字符串结尾，最后直接相减得出内存长度
}


int myMemCmp(const void *cs,const void *ct,size_t count)
{
    const unsigned char *su1,*su2;
    int res = 0;
    for(su1 = cs,su2 = ct;count > 0;++su1,++su2,count--)
        if((res = *su1 - *su2) != 0) //就是比值的大小，如果不同就是非0，直接break，相同的话继续循环，直到结束，最后返回res=0
            break;

    return res;
}


/**
 * strstr - Find the first substring in a %NUL terminated string
 * @s1: The string to be searched；主串
 * @s2: The string to search for；子串
 */
char *myStrStr(const char *s1,const char *s2)
{
    int l1,l2;
    l2 = myStrlen(s2);
    if(!l2)
        return (char *)s1;
    l1 = myStrlen(s1);

    while(l1>=l2)
    {
        l1--;
        if(!myMemCmp(s1,s2,l2)) //逐位比较模式串与子串的长度，如果匹配，返回成功；否则把主串指针移动1位继续循环比较
            return (char *)s1;
        s1++;
    }

    return NULL;
}


char* myStrStr2(const char *s1,const char *s2)
 {
    int n;
    if(*s2 != '\0')
    {
        while(*s1 != '\0')
        {
            for(n = 0; *(s1+n) == *(s2+n); n++)
            {
                if(!*(s2+n+1)) // *(s2+n+1) == '\0' ，到达末尾了
                    return(char*)s1;
            }
            s1++;
        }
        return NULL;
    }
    else
        return (char*)s1;
}

int main()
{
    char* pChild = "123";
    char* pParent = "456789123789456123" ;

    
    puts(myStrStr(pParent,pChild));//返回匹配到的位置后面所有的字符串
    printf("\n");

    printf("  %d\n",myStrStr(pParent,pChild) - pParent);//返回匹配到的第一个子串位置,采用的是首地址偏移相减
    printf("\n");
    
    return 0;
}
