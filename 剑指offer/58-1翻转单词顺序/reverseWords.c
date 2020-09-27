#include <stdio.h>
#include <stdlib.h>

/*
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。
例如输入字符串"I am a student. "，则输出"student. a am I"。

示例 1：
输入: "the sky is blue"
输出: "blue is sky the"

示例 2：
输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

示例 3：
输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

说明：

    无空格字符构成一个单词。
    输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
    如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

*/

/*
思路:双指针从尾到头遍历

倒序遍历字符串 sss ，记录单词左右索引边界 i , j ；
每确定一个单词的边界，则将其添加至单词列表 res；
最终，将单词列表拼接为字符串，并返回即可。

*/





char* reverseWords(char* s){

    int len = strlen(s);
    
    if(s == NULL || len <= 0) return "";

    int l = 0;
    int r = len - 1;

    while(s[l] == ' ' && l <= r)  l++; //去除左边空格
    while(s[r] == ' ' && r >= l)  r--; //去除右边空格

    if(r < l) return ""; //全是空格就返回

    int real_len = r - l + 1;//去除左右空格后的长度

    char *str = (char *)calloc((real_len+1),sizeof(char));

    int i = r;
    int j = r;//从尾到头遍历
    int length = 0;
    // 注意：新字符串的边界[l,r]
    while(i >= l)
    {
        while(i>= l && s[i] != ' ')  i--;//从右到左找到第一个空格
        for(int k = i+1; k < j+1; k++)
        {
            str[length++] = s[k];  //将字符[i+1,j]正序放进str          
        }
        //注意：只有i>=l 才可以跟在单词后添加空格，否则到最后一次i溢出边界，这里又添加一次导致分配的空间溢出
        if(i>=l)    str[length++] = ' '; 
        while(i>= l && s[i] == ' ')  i--;//去除中间的空格
        j = i; //将右指针置为新单词的结尾      
    }

    str[length] = '\0';//最后加上，也可以不加，因为初始化数组使用的calloc

    return str;
}


