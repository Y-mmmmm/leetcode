#include <stdio.h>
#include <stdlib.h>

/*
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]

说明：

    用返回一个整数列表来代替打印
    n 为正整数

*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//因为返回的是官方给的返回int，故暂时不用考虑溢出问题；但仍需要关心一下
int* printNumbers(int n, int* returnSize){
    if(n<1)
    {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = pow(10,n)-1;
    int *nums = (int *)calloc(*returnSize,sizeof(int));
    if(nums == NULL)
        return NULL;

    for(int i=0;i<*returnSize;i++)
    {
        nums[i] = i+1;
    }

    return nums;

}

