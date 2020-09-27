/*

一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？


示例 1:

输入: m = 3, n = 2
输出: 3
解释:
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向右 -> 向下
2. 向右 -> 向下 -> 向右
3. 向下 -> 向右 -> 向右

示例 2:

输入: m = 7, n = 3
输出: 28

*/


/*
1.动态规划
2.排列组合  到达终点需向下m-1次，向右n-1次，故在m+n-2次移动当中，选出m-1次存放向下，即C(m+n-2,m-1)，或C(m+n-2,n-1)，取m,n中较小的计算。
排列组合主要解决计算过程溢出问题，所以计算时能整除就先除，避免溢出。

C(n,m)  = (n!)/((m!)*((n-m)!))

本质就是一个杨辉三角形，每个位置的路径 = 该位置左边的路径 + 该位置上边的路径


优化动态规划：实际上每次计算都只用了上面一行，前面的都没用，所以可以优化成一维

*/

int uniquePaths(int m, int n){

    if(m < 1 || n < 1)  return 0;

    int dp[m][n];
    dp[0][0] = 1;

    for(int i=1;i<m;i++)
        dp[i][0] = 1;
    for(int j=1;j<n;j++)
        dp[0][j] = 1;

    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[m-1][n-1];

}

int uniquePaths(int m, int n){

    if(m < 1 || n < 1)  return 0;

    int dp[n];

    for(int i=0;i<n;i++)
        dp[i] = 1;

    for(int i=1;i<m;i++)
    {
        dp[0] = 1;
        for(int j=1;j<n;j++)
        {
            dp[j] = dp[j]+dp[j-1];
        }
    }
    return dp[n-1];

}

//C(n,m) =  (n!)/((m!)*((n-m)!))
int C(int n,int m)
{
    int res = 1,j=1;
    for(int i=0;i<m;i++)
    {
        res *= (n-i);
        while(j<=m && res%j==0) //能除先除，避免溢出
        {    
            res /= j;
            j++;
        }
    }
    return res;
}
int uniquePaths(int m, int n){
    return C( m+n-2, (m < n ? m : n)-1 );    //取较小者作为C(n,m)中的m
}

