#include <stdio.h>
#include <string.h>

/*
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

示例 1：
输入: s = "abcdefg", k = 2
输出: "cdefgab"

示例 2：
输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"

限制：
    1 <= k < s.length <= 10000
*/


/*
思路：
1.s+s，然后取 [n,len+n-1]
2.C++ 切片，将[0,n-1] [n,len-1]分别切下来，再[n,len-1] + [0,n-1]拼起来
3.求余，开辟一个len+1的空间，从n开始遍历，将字符串放入空间，最后再把开头放进去

*/




//拼接
char* reverseLeftWords(char* s, int n){

    int len = strlen(s);
    if(s == NULL || len <= 0) return "";

    if(n >= len)  return s;

    int doublelen = 2*len;

    char *str = (char *)calloc(doublelen+1,sizeof(char));

    strcpy(str,s);
    char *ss = strcat(str,s); //把相同的两个字符串拼接到一起
    int j = 0;

    for(int i=n;i<len+n;i++) 
    {
        str[j++] = ss[i];//截取n ~ len+n-1
    }
    str[j] = '\0';

    return str;
}

//求余
char* reverseLeftWords(char* s, int n){

    int len = strlen(s);
    
    char *str = (char *)calloc(len+1,sizeof(char));

    for(int i=0;i<len;i++) 
    {
        str[i] = s[(n + i)%len];
    }
    str[len] = '\0';
    return str;
}