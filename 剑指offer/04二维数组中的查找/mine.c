#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//左下查找法
bool findNumberIn2DArray(int** matrix, int matrixSize, int* matrixColSize, int target){
   if(matrix == NULL || matrixSize <=0 || *matrixColSize <= 0)
   {
       return false;
   }
    int n = matrixSize;
    int m = *matrixColSize;
    int i=n-1,j =0;

    while( i>=0 && j<m)
    {
        if(target > matrix[i][j])
        {
            j++;
        }
        else if(target < matrix[i][j])
        {
            i--;
        }
        else //注意这里，一开始将==放最前面，但是力扣总是提示溢出，改到这里就好了
        {
            return true;
        }
    }
          
    return false;

}





