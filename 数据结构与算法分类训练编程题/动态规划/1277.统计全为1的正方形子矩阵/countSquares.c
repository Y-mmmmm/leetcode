/*
给你一个 m * n 的矩阵，矩阵中的元素不是 0 就是 1，请你统计并返回其中完全由 1 组成的 正方形 子矩阵的个数。

 

示例 1：

输入：matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
输出：15
解释： 
边长为 1 的正方形有 10 个。
边长为 2 的正方形有 4 个。
边长为 3 的正方形有 1 个。
正方形的总数 = 10 + 4 + 1 = 15.

示例 2：

输入：matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
输出：7
解释：
边长为 1 的正方形有 6 个。 
边长为 2 的正方形有 1 个。
正方形的总数 = 6 + 1 = 7.

*/

int countSquares(int** matrix, int matrixSize, int* matrixColSize){
    if(matrix == NULL || matrixSize < 1 || matrixColSize == NULL)   return 0;

    int cnt = 0;
    int row = matrixSize + 1;
    int col = *matrixColSize + 1;

    int dp[row][col];//以i,j为右下角的最大正方形边长
    memset(dp,0,sizeof(dp));

    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            if(matrix[i-1][j-1] == 1)
            {       
                dp[i][j] = fmin(dp[i-1][j-1],fmin(dp[i-1][j],dp[i][j-1])) + 1;
                cnt += dp[i][j];//沿着正方形对角线从右下角往左上推(dp[i][j]-->dp[i-1][j-1])，可以得出dp[i][j]个正方形(例如边长为3，表示左上有一个1,1个2,还有自己1个3)，所以累加每个位置的正方形边长即可
            }    
        }
    }
   
    return cnt;
}

