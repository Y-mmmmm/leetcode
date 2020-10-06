/*
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:
输入: haystack = "hello", needle = "ll"
输出: 2

示例 2:
输入: haystack = "aaaaa", needle = "bba"
输出: -1

说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

*/

/*
严格来讲这道题应该用KMP算法
*/

// Linux string.c strstr()函数源码修改，测试用例通过但代码超时
int strStr(char * haystack, char * needle){

    char *s1 = haystack;
    char *s2 = needle;

    int n;
    if(*s2 != '\0')
    {
        while(*s1 != '\0')
        {
            for(n = 0; *(s1+n) == *(s2+n); n++)
            {
                if(*(s2+n+1) == '\0') //到达s2末尾了,判断结束
                    return s1 - haystack;
            }
            s1++;
        }
        return -1;
    }
    else
        return 0;

}
