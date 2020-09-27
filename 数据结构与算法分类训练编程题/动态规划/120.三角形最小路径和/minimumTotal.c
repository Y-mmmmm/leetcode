
/*
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
*/

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){

    int m = triangleSize; //左对齐后这是一个等腰直角三角形，行列相同，第0行1个，第1行2个，。。。，第i行i+1个

    int dp[m][m];//表示从三角形顶部走到i,j位置的最小路径和
    memset(dp,0,sizeof(dp));
    dp[0][0] = triangle[0][0];

    for(int i=1;i<m;i++)
    {
        dp[i][0] = dp[i-1][0] + triangle[i][0]; //每行第一个只与上一行第一个有关，j=0时第一列的路径和只能从头顶往下加
        for(int j=1;j<i;j++)//每行的长度是小于i的
        {
            //其余的看头顶两个位置
            dp[i][j] = fmin(dp[i-1][j-1],dp[i-1][j])+triangle[i][j]; //只能从头顶两个位置走到当前i，j
        }
        dp[i][i] = dp[i-1][i-1] + triangle[i][i];//每行最后一个只与上一行最后一个有关，j=i时，只能从上个边长往下加
    }

    int res = dp[m-1][0];

    for(int i=0;i<m;i++)
    {
        res = fmin(res,dp[m-1][i]);//只要在最后一行找即可
    }
    return res;

}

