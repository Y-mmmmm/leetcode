/*

给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。

找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:

X X X X
X O O X
X X O X
X O X X

运行你的函数后，矩阵变为：

X X X X
X X X X
X X X X
X O X X

解释:

被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

*/

/*
这道题不能简单的用岛屿问题来做，因为边界上的不好处理，而且必须被包围才可以；

如 
O O O
O O O
O O O

X O X
X O X
X O X

X X X X
X O O X
X X O X
X O O X


题目中解释说被包围的区间不会存在于边界上，所以我们会想到边界上的 O 要特殊处理，只要把边界上的 O 特殊处理了，
那么剩下的 O 替换成 X 就可以了。问题转化为，如何寻找和边界联通的 O

上面例子就是，如果单纯的用感染来做，中间的O会被修改，但实际上不行，因为没有被完全包围
所以反其道而行之，对边界进行感染，将边界上与O相连的全部改成别的，然后再遍历数组修改与还原即可
*/

void infect(char** board, int row, int col,int i,int j)
{
    if(i<0||i>=row || j<0||j>=col || board[i][j] != 'O')   return;

    board[i][j] = '#';

    infect(board,row,col,i+1,j);
    infect(board,row,col,i-1,j);
    infect(board,row,col,i,j+1);
    infect(board,row,col,i,j-1);

}

void solve(char** board, int boardSize, int* boardColSize){
    if(board == NULL || boardSize <1 || boardColSize == NULL)   return;

    int row = boardSize;
    int col = *boardColSize;

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            //只有被'X'包围的才有资格改,先将边界上与O相连的全部改掉
            if(i == 0 || j == 0 || i== row-1 || j == col-1)
            {
                if(board[i][j] == 'O')
                    infect(board,row,col,i,j);
            }
        }
    }

    //修改剩下的并还原
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(board[i][j]=='O')    board[i][j]='X';
                    
            if(board[i][j]=='#')    board[i][j]='O';
                    
        }
    }

}

