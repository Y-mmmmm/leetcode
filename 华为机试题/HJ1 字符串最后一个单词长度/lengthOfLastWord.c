/*
题目描述

计算字符串最后一个单词的长度，单词以空格隔开。
输入描述:

输入一行，代表要计算的字符串，非空，长度小于5000。

输出描述:

输出一个整数，表示输入字符串最后一个单词的长度。

示例1
输入

hello nowcoder

输出

8


*/

#include <stdio.h>
#include <string.h>

int main()
{
    char s[5000];
    int cnt = 0;
    int idx = 0;
    while(~scanf("%c",&s[idx]))
    {
        if(s[idx] == ' ')
            cnt = 0;//遇到空格就重新计数，一直遍历到最后一个单词前的空格，开始统计最后一个单词个数
        else
            cnt++;
        
        idx++;
    }
    printf("%d\n",cnt-1);//一个字符串输入结束
    return 0;
}


