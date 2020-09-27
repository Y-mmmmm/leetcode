#include <stdio.h>
#include <stdlib.h>
/*
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

示例 1：

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1

示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36

2<= n <=58
*/

/*
动态规划：将大问题分解为小问题
贪心算法：根据数学原理先证明最优解的条件
*/

/*动态规划*/
int cuttingRope(int n){

    if(n<2) return 0;
    if(n==2) return 1;
    if(n==3) return 2;

    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i=4;i<=n;i++)
    {    
        int max =0;   
        for(int j=1;j<=i/2;j++)
        {
            int tmp = dp[j]*dp[i-j];
            if(max<tmp)   
            max = tmp;
            dp[i] = max;
        }       
    }
    
    return dp[n];

}

/*上面的变形*/
#define MY_MAX(x,y) (x)>(y)?(x):(y)

int cuttingRope(int n){

    if(n<2) return 0;
    if(n==2) return 1;
    if(n==3) return 2;

    int dp[n+1]; //动态数组无法直接初始化为0
    memset(dp,0,sizeof(int)*(n+1));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i=4;i<=n;i++)
    {           
        for(int j=1;j<=i/2;j++)
        {         
            dp[i] = MY_MAX(dp[i],dp[j]*dp[i-j]);
        }       
    }
    
    return dp[n];

}

/*贪心算法*/
int cuttingRope(int n){

    if(n < 2) return 0;
    if(n == 2) return 1;
    if(n == 3) return 2;

    //n = 3a + b
    int a = n/3;
    int b = n%3;

    if(b == 0)  
        return pow(3,a); //没有余数，则都是3
    else if(b == 1)  
        return pow(3,a-1)*4; //余数为1，3(a-1) +(3+1),把 3+1拆成2*2
    else
        return pow(3,a)*2; //余数为2，多一个2直接乘

}

/*贪心算法变形*/
//只要n超过4，那么优先切成长度=3的段。直到n <= 4，最后乘到ans里面就好。
int cuttingRope(int n){

    if(n < 2) return 0;
    if(n == 2) return 1;
    if(n == 3) return 2;

    int ans = 1;
    //本质还是n = 3a + b
    while(n>4)
    {
        ans *= 3;//先使劲乘3
        n -= 3;
    }

    ans = ans * n; //最后把剩下的乘上

    return ans;

}

