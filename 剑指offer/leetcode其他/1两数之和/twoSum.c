/*
题目：给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//暴力法
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int *result = (int *)malloc(sizeof(int)*2);
    for(int i = 0;i < numsSize-1;i++) //i < numsSize-1
    {
        for(int j = i+1;j < numsSize;j++) //j = i+1;j < numsSize
        {
            if(nums[i]+nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;

            }
        }
    }

 //   return result;
    return NULL;

}


void main()
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int size;
    int *result = twoSum(nums,4,9,&size);

    for(int i=0;i<size;i++)
    {
        printf("%d ",result[i]);
    }

}
