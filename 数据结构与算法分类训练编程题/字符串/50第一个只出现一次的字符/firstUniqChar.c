/**
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

示例:
s = "abaccdeff"
返回 "b"
s = "" 
返回 " "
限制：
0 <= s 的长度 <= 50000
**/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char firstUniqChar(char* s){
    if(s == NULL)
        return ' ';

    int size = strlen(s);
    //开辟26个小写字母的哈希表，注意当前是小写字母，如果有其他字符，则需要扩大，否则会溢出
    int *hashmap = (int *)calloc(26,sizeof(int));
    
    //遍历字符串，哈希表+1，相同出现的会多次+1，出现一次的只+1
    for(int i=0;i<size;i++)
    {
        hashmap[s[i] - 'a'] += 1;  //巧妙的减去a得到对应的十进制    
    }
    //遍历哈希表中第一个为1的，返回其对应的字符
    for(int i=0;i<size;i++)
    {
        if(hashmap[s[i] - 'a'] == 1)
            return s[i];
    }
    
    return ' '; 
}





