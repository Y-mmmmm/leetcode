#include <stdio.h>
#include <stdlib.h>
/*
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

示例 1:

输入: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物
*/

/*
思路：就是m*n数组求路径最大值，注意题目说到达右下角，也就是此时右下角就是最大值，直接返回右下角值；
    关键在于，如何让它最大。因为只能向下或向右走，那么只要比较这两个位置大小即可，往大的地方走，累加即可。

    采用动态规划dp：动态规划根据转移方程将大问题分解为小问题
    dp[i][j] = max(dp[i-1][j],dp[i][j-1]) + grid[i][j];
*/


//方法1，在原数组上累加
int maxValue(int** grid, int gridSize, int* gridColSize){
    if(grid == NULL)    return 0;
    int m = gridSize;
    int n = *gridColSize;

    for(int i=1;i<m;i++)
        grid[i][0] += grid[i-1][0]; //先计算一行

    for(int j=1;j<n;j++)
        grid[0][j] += grid[0][j-1]; //计算一列

    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            grid[i][j] += fmax(grid[i-1][j],grid[i][j-1]); //与左边和上边的最大值进行累加
        }
    }

    return grid[m-1][n-1]; //返回此时右下角最大值
}

//方法2 直接开辟dp数组
int maxValue(int** grid, int gridSize, int* gridColSize){
    if(grid == NULL)    return 0;
    int m = gridSize;
    int n = *gridColSize;

    int dp[m+1][n+1];//数组扩大一行一列，就不需要先计算单行、单列了
    memset(dp,0,sizeof(int)*((m+1)*(n+1))); //动态规划数组必须清零，否则下面比大小的初值不定直接错误

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j] = fmax(dp[i-1][j],dp[i][j-1]) + grid[i-1][j-1];
        }
    }

    return dp[m][n];

}

