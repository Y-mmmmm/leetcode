/*
找出数组中重复的数字。

在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
请找出数组中任意一个重复的数字。

示例 1：
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 

限制：
2 <= n <= 100000
*/


#include <stdio.h>
#include <stdlib.h>


//哈希法
//若当前值的hash值已经加过1了，则直接返回当前值。
int findRepeatNumber(int* nums, int numsSize)
{
    int *hashmap = (int *)calloc(numsSize, sizeof(int));//hashmap默认全0
    for(int i = 0; i < numsSize; i++)
    {
        if(hashmap[nums[i]] == 1)
        {
            return nums[i];//遇到加过1的就返回当前的值
        } 
        else 
        {
            hashmap[nums[i]]++; //没有重复的就+1
        }
    }
    return -1;
}


//原地哈希
int findRepeatNumber(int* nums, int numsSize){

    for(int i=0;i<numsSize;i++)
    {
        while(nums[i] != i) //如果数组元素不等于下标，则交换到它的下标位置
        {
            if(nums[i] == nums[nums[i]]) //遇到交换过的说明重复，直接返回
                return nums[i];

            int tmp = nums[i];
            nums[i] = nums[tmp];
            nums[tmp] = tmp;  
        }       
    }
    return -1;
}

