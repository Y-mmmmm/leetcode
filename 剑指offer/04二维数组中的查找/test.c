//同样使用左下角查找方式

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//amn
//行排序，aij = a00 +(i*n+j)*size

//注意，这里是变长数组声明方式，行列参数必须在前面
bool Find(int target,int rows,int columns,int array[rows][columns]) 
{
    if(array != NULL && rows > 0 && columns >0)
    {
        int i = rows-1;
        int j = 0;
        while(i>=0 && j<columns)
        {
            if(target == array[i][j]) 
            {
                return true;
            }
            if(target > array[i][j])
            {
                j++;

            }
            if(target < array[i][j])
            {
                i--;
            }
        }      

    }
    return false;
}


int main()
{
    int matrix1[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};

    int matrix2[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};

    bool result = Find(7,4,4,matrix2);

    if(result == true)
        printf("Passed.\n");
    else
        printf("Failed.\n");
    return 1;    
    
}
