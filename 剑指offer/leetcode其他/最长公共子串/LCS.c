#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*

两个字符串的最长公共子串与最长公共子序列的区别：
最长公共子串要求在原字符串中是连续的，而子序列只需要保持相对顺序一致，并不要求连续。


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
int getCommonStrLength(char *s1, char *s2){

    int m = strlen(s1);
    int n = strlen(s2);
    int max = -1;

    int dp[m+1][n+1];

    int size = (m+1)*(n+1);

    memset(dp,0,size*sizeof(int));

    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];

	max = myMax(max, dp[i][j]);
        }
    }
 /*   
    for(int i=0;i<m+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            max = myMax(max, dp[i][j]);
        }
    }
  */  
    
    return max;
}

int main()
{
    char s1[100];
    char s2[100];
    
    gets(s1);
    gets(s2);
    
    printf("%d\n",getCommonStrLength(s1,s2));
    return 0;
}
