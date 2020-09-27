#include <stdio.h>
#include <string.h>


int main()
{
    char s1[1000] = {'\0'};
    char s2[1000] = {'\0'};
    while(gets(s1))
    {
        gets(s2);
        
        int m = strlen(s1);
        int n = strlen(s2);

        //将短的放s1
        if(m > n)
        {
            char tmp[1000] = {'\0'};
            strcpy(tmp,s1);
            memset(s1,'\0',m*sizeof(char));
            strcpy(s1,s2);
            strcpy(s2,tmp);
        }
        
        //重新计算长度
        int len1 = strlen(s1);
        int len2 = strlen(s2);

        int dp[len1+1][len2+1];
        
        memset(dp,0,sizeof(dp));
        dp[0][0] = 0;
        int maxlen = -1;
        int maxStartIdx = 0;
        
        for(int i=1;i<=len1;i++) //注意 <=
        {
            for(int j=1;j<=len2;j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    if(dp[i][j] > maxlen)
                    {
                        maxlen = dp[i][j]; //更新最大长度
                        maxStartIdx = i - maxlen;//记录第一个子串在短串 s1的下标
                    }
                }
            }
        }
    
        for(int i = maxStartIdx;i< maxlen + maxStartIdx;i++)
        {
            printf("%c",s1[i]);
        }
        printf("\n");
    }
    return 0;
}
