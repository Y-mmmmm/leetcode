#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
题目描述
给定n个字符串，请对n个字符串按照字典序排列。

输入描述:
输入第一行为一个正整数n(1≤n≤1000),下面n行为n个字符串(字符串长度≤100),字符串中只含有大小写字母。

输出描述:
数据输出n行，输出结果为按照字典序排列的字符串。

示例1
输入

9
cap
to
cat
card
two
too
up
boat
boot

输出

boat
boot
cap
card
cat
to
too
two
up

*/



int main()
{
    int n;
    scanf("%d",&n);
    
    char s[n][100];//字符串数组，n是字符串的个数，100是开辟的每个字符串的缓冲区
    char tmp[100]; //排序用的缓冲区
    for(int i = 0;i<n;i++)
    {
        scanf("%s",s[i]);//获取每个字符串
    }
    //冒泡排序
    for(int i = n-1;i>0;i--)
    {
        for(int j = 0;j<i;j++)
        {
            if(strcmp(s[j],s[j+1])>0)//注意，字符串不能直接比较，要使用strcmp函数
            {
                //swap
                strcpy(tmp,s[j]);
                strcpy(s[j],s[j+1]);
                strcpy(s[j+1],tmp);
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        printf("%s\n",s[i]);
    }
    
    return 0;
}






