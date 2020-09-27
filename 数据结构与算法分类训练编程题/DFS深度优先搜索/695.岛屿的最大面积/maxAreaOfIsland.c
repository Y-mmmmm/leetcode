#include <stdio.h>



/*
给定一个包含了一些 0 和 1 的非空二维数组 grid 。
一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)

示例 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]

对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。

示例 2:
[[0,0,0,0,0,0,0,0]]

对于上面这个给定的矩阵, 返回 0。

*/

/*
本题实际就是网格中的DFS

*/
#define myMax(a,b)  ((a)>(b)?(a):(b))

int dfs(int** grid, int r, int c,int m,int n)
{
    if(r>=m || r<0 || c>=n || c<0)  return 0;//越界情况

    if(grid[r][c] != 1) return 0; //不是岛屿1不访问

    grid[r][c] = 2;//打标记，防止重复访问

    return 1 + dfs(grid,r-1,c,m,n)+dfs(grid,r+1,c,m,n)+dfs(grid,r,c-1,m,n)+dfs(grid,r,c+1,m,n);//上下左右四个方向
}


int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int res = 0;
    int area = 0;
    int m = gridSize;
    int n = *gridColSize;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j] == 1)
                area = dfs(grid,i,j,m,n);
            res = myMax(res,area);//取最大值
        }
    }
    return res;
}
