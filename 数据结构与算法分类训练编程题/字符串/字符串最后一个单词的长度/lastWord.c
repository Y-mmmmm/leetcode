#include <stdio.h>
#include <string.h>

/*
计算字符串最后一个单词的长度，单词以空格隔开。

输入描述:
一行字符串，非空，长度小于5000。

输出描述:
整数N，最后一个单词的长度。

示例1
输入
hello world

输出
5
*/


/*
如果题目中的字符串末尾不包含空格，代码就没啥问题，否则最后输出0


*/
int main()
{
    char *s[5000];
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
    printf("%d\n",cnt);//一个字符串输入结束
    return 0;

}

