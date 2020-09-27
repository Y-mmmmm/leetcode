/*
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大【正方形】，并返回其面积。

示例:

输入: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

输出: 4

*/

/*
1.定义dp[i][j] : 以i,j为右下角的最大正方形边长
2.状态 ：当前位置是否为 ‘1’
3.base case : dp[i][0]=dp[0][j] = 0
4.转移方程：
    当我们判断以某个点为正方形右下角时最大的正方形时，那它的上方，左方和左上方三个点也一定是某个正方形的右下角，
    否则该点为右下角的正方形最大就是它自己了。这是定性的判断，那具体的最大正方形边长呢？我们知道，该点为右下角的正方形的最大边长，
    最多比它的上方，左方和左上方为右下角的正方形的边长多1，最好的情况是是它的上方，左方和左上方为右下角的正方形的大小都一样的，
    这样加上该点就可以构成一个更大的正方形。 但如果它的上方，左方和左上方为右下角的正方形的大小不一样，合起来就会缺了某个角落，
    这时候只能取那三个正方形中最小的正方形的边长加1了。假设dp[i][j]表示以i,j为右下角的正方形的最大边长，
    则有 dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1 
    当然，如果这个点在原矩阵中本身就是0的话，那dp[i]肯定就是0了。

*/


int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){

    if(matrix == NULL || matrixSize < 1 || matrixColSize == NULL)   return 0;
    int row = matrixSize + 1;
    int col = *matrixColSize + 1;

    int dp[row][col];//以i,j为右下角的最大正方形边长
    memset(dp,0,sizeof(dp));

    int sideLen = 0;

    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
            if(matrix[i-1][j-1] == '1')
                dp[i][j] = fmin(dp[i-1][j-1],fmin(dp[i-1][j],dp[i][j-1])) + 1;//当前位置是1，则以当前位置为右下角的最大正方形边长就是左上、左边、上边的最小值+自己的1

            sideLen = fmax(sideLen,dp[i][j]);
        }
    }

    return sideLen*sideLen;
}