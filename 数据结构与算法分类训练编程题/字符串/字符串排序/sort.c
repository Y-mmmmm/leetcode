#include <stdio.h>
#include <string.h>

/*
题目描述

Lily上课时使用字母数字图片教小朋友们学习英语单词，每次都需要把这些图片按照大小（ASCII码值从小到大）排列收好。请大家给Lily帮忙，通过C语言解决。

输入描述:

Lily使用的图片包括"A"到"Z"、"a"到"z"、"0"到"9"。输入字母或数字个数不超过1024。

输出描述:

Lily的所有图片按照从小到大的顺序输出

示例1
输入

Ihave1nose2hands10fingers

输出

0112Iaadeeefghhinnnorsssv

*/


/*
思路：和数组一样，就是简单排序
1.快速排序 O(NlogN) O(N)
2.哈希统计每个字符的个数，然后依次输出
*/

//快速排序
void qsort_char(char *s,int l,int r)
{
    if(l<r)
    {
        int idx = (r+l)/2;
        char tmp = s[l];
        s[l] = s[idx];
        s[idx] = tmp;
        
        int i = l;
        int j = r;
        char x = s[l];
        
        while(i<j)
        {
            while(i<j && s[j]>=x)    j--;
            if(i<j)    s[i++] = s[j];
            
            while(i<j&& s[i]<x)    i++;
            if(i<j)    s[j--] = s[i];
        }
        s[i] = x;
        qsort_char(s,l,i-1);
        qsort_char(s,i+1,r);
    }
}


int main()
{
    char s[1025];
    while(gets(s))
    {
        int len = strlen(s);
        int l = 0;
        int r = len-1;
        qsort_char(s,l,r);
        printf("%s\n",s);
    }
    
    return 0;
}


//哈希
int main()
{
    char s[1025];
    while(gets(s))
    {
        int len = strlen(s);
        
        int hashmap[256]={0};
        
        for(int i=0;i<len;i++)
        {
            hashmap[s[i]]++;
        }
        
        for(int i=0;i<256;i++)
        {
            while(hashmap[i]!=0) //注意：是 hashmap[i]!=0，此时只看哈希表了
            {
                printf("%c",i); //输出下标 i 就是对应的 字符
                hashmap[i]--; //把字符个数 -1
            }
        }
        printf("\n");
    }
    
    return 0;
}


