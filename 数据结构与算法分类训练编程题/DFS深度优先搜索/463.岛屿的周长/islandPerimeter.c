#include <stdio.h>


/*
给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。

网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

示例 :

输入:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

输出: 16
*/

int dfs(int** grid,int r,int c,int m,int n)
{
    if(r>=m || r<0 || c>=n||c<0)    return 1;//遇到边界，存在一条边界边
    
    if(grid[r][c] == 0) return 1; //遇到海洋，存在一条海洋边

    if(grid[r][c] != 1) return 0; //遇到岛屿不算
    
    grid[r][c] = 2;//将访问过的陆地格子打标记

    return dfs(grid,r-1,c,m,n)+dfs(grid,r+1,c,m,n)+dfs(grid,r,c-1,m,n)+dfs(grid,r,c+1,m,n);

}


int islandPerimeter(int** grid, int gridSize, int* gridColSize){

    int m = gridSize;
    int n = *gridColSize;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(grid[i][j] == 1)
                return dfs(grid,i,j,m,n); 
        }
    }
    return 0;
}






