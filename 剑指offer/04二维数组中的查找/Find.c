/*
在一个二维数组中（每个一维数组的长度相同），
每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//amn
//行排序，aij = a00 +(i*n+j)*size
//列排序，aij = a00 +(i*m+j)*size

bool Find(int target,int *array,int rows,int columns)
{
    if(array != NULL && rows > 0 && columns >0)
    {
        int i = rows-1;
        int j = 0;
        while(i>=0 && j<columns)
        {
            if(target == array[i*columns+j]) 
            {
                return true;
            }
            if(target > array[i*columns+j])
            {
                j++;

            }
            if(target < array[i*columns+j])
            {
                i--;
            }
        }      

    }
    return false;
}

void Test(char* testName, int* matrix, int rows, int columns, int number, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    bool result = Find(number,matrix, rows, columns);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
void Test1()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test1", (int*)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15

void Test2()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test2", (int*)matrix, 4, 4, 5, false); //(int*)matrix 强制转换成指针
}


int main()
{
    //Test1();
    //Test2();

    //以下是将二维数组强制转换成指针传值的例子
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};

    int *p=(int *)matrix;
        
    if(Find(12,p,4,4))
    {
        printf("Pass\n");
    }else
    {
        printf("Failed\n");
    }
    

    return 1;    
    
}

