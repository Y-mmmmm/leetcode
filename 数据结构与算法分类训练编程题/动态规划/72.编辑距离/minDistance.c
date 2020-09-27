#include <stdio.h>
#include <string.h>


/*
dp[i][j] 代表 word1 中前 i 个字符，变换到 word2 中前 j 个字符，最短需要操作的次数

伪代码：
if s1[i] == s2[j]:
    啥都别做（skip）dp[i-1][j-1]
    i, j 同时向后移动
else:
    三选一：
        插入（insert）dp[i][j-1] + 1
        删除（delete）dp[i-1][j] + 1
        替换（replace）dp[i-1][j-1] + 1

*/


#define min2(a,b)   ((a)<(b)?(a):(b))
#define min3(a,b,c) min2(a,min2(b,c))

int minDistance(char * word1, char * word2){
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    int dp[len1+1][len2+1];
    dp[0][0] = 0;

    for(int i=1;i<=len1;i++)
        dp[i][0] = i;//s2为空，那么弥补的代价就是i

    for(int i=1;i<=len2;i++)
        dp[0][i] = i;//s1为空，那么弥补的代价就是i

    int case1,case2,case3;

    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            if(word1[i-1] == word2[j-1])
                case1 = dp[i-1][j-1];//跳过
            else
                case1 = dp[i-1][j-1]+1;//替换
            
            case2 = dp[i-1][j]+1;//删除
            case3 = dp[i][j-1]+1;//插入

            dp[i][j] = min3(case1,case2,case3);
        }
    }

    return dp[len1][len2];

}


/*
int minDistance(String s1, String s2) {
    int m = s1.length(), n = s2.length();

    int[][] dp = new int[m + 1][n + 1];

    // base case 
    for (int i = 1; i <= m; i++)
        dp[i][0] = i;
    for (int j = 1; j <= n; j++)
        dp[0][j] = j;

    // 自底向上求解
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (s1.charAt(i-1) == s2.charAt(j-1))
                dp[i][j] = dp[i - 1][j - 1];
            else               
                dp[i][j] = min(
                    dp[i - 1][j] + 1, //删除
                    dp[i][j - 1] + 1, //插入
                    dp[i-1][j-1] + 1  //替换
                );
    // 储存着整个 s1 和 s2 的最小编辑距离
    return dp[m][n];
}

int min(int a, int b, int c) {
    return Math.min(a, Math.min(b, c));
}

*/
