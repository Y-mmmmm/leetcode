#include <stdio.h>
#include <stdlib.h>

/*
C语言版本
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    if(target < 1)
    {
        *returnSize = 0;
        return NULL;
    }

    int l = 1;
    int r = 1;

    int **res = (int **)calloc(target,sizeof(int *));
    *returnColumnSizes = (int *)calloc(target,sizeof(int *));

    int t = target/2 + 1; //越往右越接近target，因此后半部之和不可能=target，故取一半
    int sum = 0;

    int len = 0;

    while(l < t)
    {
        if(sum < target)
        {
            sum += r;
            r++;
        }
        else if(sum > target)
        {
            sum -= l;
            l++;
        }
        else
        {
            int size = r - l;  //记录当前左闭右开区间窗口内的个数
            returnColumnSizes[0][len] = size;  //存储每个窗口的长度

            res[len] = (int *)calloc(size,sizeof(int));  //根据窗口长度分配空间

            for(int i=0;i<size;i++)
            {
                res[len][i] = l+i;   //塞入数据，注意此处使用 l+i 的形式
            }
            len++;  //长度+1
            sum -= l; //注意：去掉左值，移动左指针，继续下一步
            l++;           
        }

    }
    *returnSize = len;
    return res;
}


