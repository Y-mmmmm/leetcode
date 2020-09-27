#include <stdio.h>

/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]

*/

/*
思路：
划分上下左右边界；
1.先从左到右打印，直到最后一列，然后下移一行；
2.然后从最后一列开始，从新行往下打印，然后左移一列；
3.接着从右边新列开始，向左打印，然后上移一行
4.最后从下边新行开始，从下往上打印，然后右移一列
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrix == NULL || matrixSize <=0)
    {
        *returnSize = 0;
        return NULL;
    }
    int up = 0;
    int down = matrixSize - 1;
    int left = 0;
    int right = *matrixColSize - 1;

    *returnSize = matrixSize * (*matrixColSize);
    int *ret = (int *)calloc(*returnSize,sizeof(int));

    int index = 0;

    while(1)
    {
        for(int i=left;i <= right;i++)
        {
            ret[index++] = matrix[up][i];
        }
        if(++up > down) break;
        /*++up i下移一行*/
        
        for(int i=up;i<=down;i++)
        {
            ret[index++] = matrix[i][right];
        }
        if(--right < left)  break;
        /*--right i左移一列*/
        
        for(int i=right;i>=left;i--)
        {
            ret[index++] = matrix[down][i];
        }
        if(--down < up) break;
        /*--down i上移一行*/
        
        for(int i=down;i>=up;i--)
        {
            ret[index++] = matrix[i][left];
        }
        if(++left > right)  break;
        /*++left i右移一列*/
    } 

    return ret;
}



