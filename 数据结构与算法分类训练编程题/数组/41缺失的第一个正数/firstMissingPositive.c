#include <stdio.h>

/*
给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。

示例 1:
输入: [1,2,0]
输出: 3

示例 2:
输入: [3,4,-1,1]
输出: 2

示例 3:
输入: [7,8,9,11,12]
输出: 1

提示：

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。
*/

/*
题目的意思就是找出数组中没有的正数中的第一个最小的正数，题目限制空间，所以只能原地哈希

思路：
1.哈希
2.二分查找：可以将数组先排序，再使用二分查找法从最小的正整数 1开始查找，找不到就返回这个正整数
3.原地哈希：在原始数组上动手脚

设计原地哈希函数：f(nums[i]) = nums[i] - 1
*/

int firstMissingPositive(int* nums, int numsSize){

    for(int i=0;i<numsSize;i++)
    {
        while(nums[i] != i+1)
        {
            //数组元素小于等于0、超限、不用换，则退出
            if(nums[i]<=0 || nums[i]>numsSize || nums[i] == nums[nums[i] - 1] )
                break;
            //原地哈希：将下标 i 的元素放到 i-1 的位置上去，也就是0的位置放1，1的位置放2，以此类推...
            int tmp = nums[i]-1;
            nums[i] = nums[tmp];
            nums[tmp] = tmp + 1;
        }
    }
        
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i] != (i+1)) //找到元素值 != i+1，就是数组中缺失的
            return (i+1);
    }
    return (numsSize+1);//都在自己位置上，就只能是长度+1的那个最小值
}