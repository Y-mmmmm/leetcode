#include <iostream>
#include <vector>

using namespace std;


/*
思路：
方法1：回溯法  

    本质就是穷举所有可能，构建N叉树，进行N叉树的遍历

    皇后问题就是每行每列只能放一个，皇后的这一列只能有一个，左上方右上方，左下方右下方都不能。

    首先从第一行第一个格子开始，先放一个皇后，然后去第二行找可以放第二个皇后的位置，如果第二行
    都不能放，那么组要回溯到第一行，将第一行第一个格子的皇后撤销，再在第一行第二个格子放皇后，再去第二行
    找可以防止的位置，依次类推

    N叉树的遍历体现在选定第一个格子后，依次递归去下一行找。回溯体现在穷举，先放，再递归，不符合要回溯撤销

方法2：约束编程

    在放一个皇后后，棋盘上它的上下左右对角线的位置都不能放了。然后找到第二个皇后的位置，再约束上下左右对角线，依次类推，最后约束会越来愈大

*/


class Solution {
public:
    vector<vector<string>> res;//返回结果
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));//创建棋盘并初始化
        backtrack(board,0);//从第0行开始找
        return res;
        
    }

/*
    1.第一行每一格都要试
    2.第一行的基础上每一格试一遍，符合要求进下一行，不符合不管
    3.第二行的基础上每一格试一遍，符合要求进下一行，不符合不管
    4.类同上
    。。。。
    n.第n格满足了，存进结果里。
*/
    void backtrack(vector<string>&board,int row)
    {
        //一行试结束了，存结果
        if(row == board.size()) //注意：board.size()
        {
            res.push_back(board);
            return;
        }

        //从每行开始试每个格子
        int n = board[row].size(); //注意：board[row].size()
        for(int col = 0; col<n; col++)
        {
            //检测当前位置放皇后会不会和之前放的皇后冲突
            if(!isValid(board,row,col))
                continue;
            
            //当前格子先放一个皇后试试
            board[row][col] = 'Q';
            //再去下一行放皇后试试
            backtrack(board,row+1);
            //下一行放不了皇后，回溯，当前位置撤销放的皇后，到下一个格子放一下再试试
            board[row][col] = '.';
        }
    }
/*
    bool isValid(vector<string>&board,int row,int col)
    {
        int n = board.size();

        //检测正上方
        for(int i=0;i<n;i++)
        {
            if(board[i][col] == 'Q')
                return false;
        }
        //检测右上方,行变小列变大的
        for(int i=row-1,j = col+1;i>=0&&j<n;i--,j++)
        {
            if(board[i][j] == 'Q')
                return false;
        }
        //检测左上方，行列都变小
        for(int i=row-1,j = col-1;i>=0&&j>=0;i--,j--)
        {
            if(board[i][j] == 'Q')
                return false;
        }
        return true;
    }
*/    
    //修改
    bool isValid(vector<string>&board,int row,int col)
    {
        int n = board.size();

        for(int i = 1; i <= row ; ++i) //注意：i <= row 检测到当前行位置
        {
            //检测正上方
            if(board[row - i][col] == 'Q')  return false;
                
            //检测左上方
            if(col - i >= 0 && board[row - i][col - i] == 'Q')  return false;
                
            //检测右上方
            if(col + i < n && board[row - i][col + i] == 'Q')   return false;
                  
        }
        return true;
    }

};





