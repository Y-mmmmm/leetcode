#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。

 
示例 1:
输入：text1 = "abcde", text2 = "ace" 
输出：3  
解释：最长公共子序列是 "ace"，它的长度为 3。

示例 2:
输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc"，它的长度为 3。

示例 3:
输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0。

 
提示:

    1 <= text1.length <= 1000
    1 <= text2.length <= 1000
    输入的字符串只含有小写英文字符。

*/

/*
注意：最长公共子序列和最长子串的区别
str1="123ABCD456"  str2 = "ABE12345D"
最长公共子串是：123
最长公共子序列是：12345

*/

//思路：动态规划 dp[i][j] 表示长度为 i的s1 与 长度为 j的s2 的子序列长度 ；
//dp[i][j] 的含义是：对于 s1[1..i] 和 s2[1..j]，它们的 LCS 长度是 dp[i][j]


/*
最长公共子序列是：
dp[i][j] -- 表示子串str1[0...i]和子串str[0...j]的最长公共子序列
当str1[i] == str2[j]时，dp[i][j] = dp[i-1][j-1] + 1;
否则，dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
最优解为dp[len1-1][len2-1];
 
最长公共子串是： 
dp[i][j] -- 表示以str1[i]和str2[j]为结尾的最长公共子串 
当str1[i] == str2[j]时，dp[i][j] = dp[i-1][j-1] + 1; 
否则，dp[i][j] = 0;
最优解为max(dp[i][j]),其中0<=i<len1, 0<=j<len2;
*/

#define myMax(a,b)  ((a)>(b)?(a):(b))

int longestCommonSubsequence(char * text1, char * text2){

    int m = strlen(text1);
    int n = strlen(text2);

    int dp[m+1][n+1];//第0行0列不处理，方便下标计算

    int size = (m+1)*(n+1);

    memset(dp,0,size*sizeof(int));

    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(text1[i-1] == text2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1]; //字符相等，+1，然后两个字符串同时移动1
            else
                dp[i][j] = myMax(dp[i-1][j],dp[i][j-1]);//不相等，移动其中一个，并选择最大值
        }
    }
   
    return dp[m][n];
}

