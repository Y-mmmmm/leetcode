#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


/*
DFS算法先判断该位置是否越界，同时该位置是否满足在指定路径的条件，满足则继续判断，不满足返回false，
将该位置置为非字母后，递归四个方向的情况，再将该位置还原并返回结果
*/

bool dfs(char** board, int boardSize, int* boardColSize, char* word,int row,int col,int len)
{
    //边界判断，以及判断该位置是否在指定路径上
    if(row >= boardSize || row < 0 || col >= *boardColSize || col < 0 || board[row][col] != word[len])
    {
        return false;
    }
    //判断是否以及完成了路径，完成路径说明矩阵中存在满足条件的路径，返回true
    if(len == strlen(word) - 1)
    {
        return true;
    }

    //将该位置置为非字母，目的是递归的时候不会出现再次进入该位置的情况
    char temp = board[row][col];
    board[row][col] = '/';

    //DFS向[下、上、右、左]四个方向分别进行递归判断，判断四个方向是否存在满足指定路径的下一个节点的位置
    //下上右左应该比上下左右快
    bool res = dfs(board,boardSize,boardColSize,word,row+1,col,len+1) || dfs(board,boardSize,boardColSize,word,row-1,col,len+1) || 
              dfs(board,boardSize,boardColSize,word,row,col+1,len+1) || dfs(board,boardSize,boardColSize,word,row,col-1,len+1);
    //将该位置还原
    board[row][col] = temp;

    return res; //返回四个方向的可行性
}

bool exist(char** board, int boardSize, int* boardColSize, char* word)
{
    for(int i=0;i<boardSize;i++)
    {
        for(int j=0;j<*boardColSize;j++)
        {
            //两个for循环的目的：从某一位置开始，一直往下找，找不到就换个位置继续找
            //对每一个位置进行判断，只要出现一次路径成功遍历的情况，则直接返回true
            if(dfs(board,boardSize,boardColSize,word,i,j,0))
            {
                return true;
            }
        }
    }

    //如果遍历整个矩阵都不存在能完成指定路径的方法，返回false
    return false;
}



