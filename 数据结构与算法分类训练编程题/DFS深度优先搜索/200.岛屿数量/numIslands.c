/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。

示例 1:
输入:
[
['1','1','1','1','0'],
['1','1','0','1','0'],
['1','1','0','0','0'],
['0','0','0','0','0']
]
输出: 1

示例 2:
输入:
[
['1','1','0','0','0'],
['1','1','0','0','0'],
['0','0','1','0','0'],
['0','0','0','1','1']
]
输出: 3
解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
*/

/*
思路：先感染后治理

本题的岛屿是所有的1连在一起就是一个岛

遍历岛这个二维数组，如果当前数为1，则进入感染函数并将岛个数+1

感染函数：其实就是一个递归标注的过程，它会将所有相连的1都标注成2。为什么要标注？
这样就避免了遍历过程中的重复计数的情况，一个岛所有的1都变成了2后，遍历的时候就不会重复遍历了。
*/

void infect(char **grid,int row,int col,int i,int j )
{
    if(i < 0 || i >= row || j < 0 || j >= col || grid[i][j] != '1')  return;
    
    grid[i][j] = '2';
    infect(grid,row,col,i+1,j);
    infect(grid,row,col,i-1,j);
    infect(grid,row,col,i,j+1);
    infect(grid,row,col,i,j-1);
}


int numIslands(char** grid, int gridSize, int* gridColSize){
    if(grid == NULL || gridSize < 1 || *gridColSize < 1)    return 0;

    int landNum = 0;
    int row = gridSize;
    int col = *gridColSize;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(grid[i][j] == '1')
            {
                infect(grid,row,col, i,j);
                landNum++;
            }
        }
    }
    return landNum;
}
