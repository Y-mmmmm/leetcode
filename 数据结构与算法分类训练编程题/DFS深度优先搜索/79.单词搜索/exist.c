/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 
示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false


提示：

    board 和 word 中只包含大写和小写英文字母。
    1 <= board.length <= 200
    1 <= board[i].length <= 200
    1 <= word.length <= 10^3

*/

/*
    M,N 分别为矩阵行列大小， KKK 为字符串 word 长度。

    时间复杂度 O(3^K*MN)： 最差情况下，需要遍历矩阵中长度为 KKK 字符串的所有方案，时间复杂度为 O(3^K)；矩阵中共有 MN 个起点，时间复杂度为 O(MN) 。
        方案数计算： 设字符串长度为 KKK ，搜索中每个字符有上、下、左、右四个方向可以选择，舍弃回头（上个字符）的方向，剩下 333 种选择，因此方案数的复杂度为 O(3K) 。

    空间复杂度 O(K) ： 搜索过程中的递归深度不超过 KKK ，因此系统因函数调用累计使用的栈空间占用 O(K)（因为函数返回后，系统调用的栈空间会释放）。
    最坏情况下 K=MN ，递归深度为 MN，此时系统栈使用 O(MN)的额外空间。

*/

bool dfs(char** board, int row, int col,int i,int j, char * word,int len)
{
    if(i<0 || i>=row || j<0 || j>=col || board[i][j]!=word[len])    return false;

    if(len == strlen(word)-1)   return true;
    
    char tmp = board[i][j];
    board[i][j] = '/';

    bool res = dfs(board,row,col,i+1,j,word,len+1)||dfs(board,row,col,i-1,j,word,len+1)||dfs(board,row,col,i,j+1,word,len+1)||dfs(board,row,col,i,j-1,word,len+1);

    board[i][j] = tmp;

    return res;
}


bool exist(char** board, int boardSize, int* boardColSize, char * word){

    if(word == NULL || board == NULL || boardSize<1||boardColSize == NULL)  return false;

    int row = boardSize;
    int col = *boardColSize;
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(dfs(board,row,col,i,j,word,0))
                return true;
        }
    }

    return false;
}

