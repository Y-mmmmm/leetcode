#include <stdio.h>

/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:
输入: [1,3,5,6], 5
输出: 2

示例 2:
输入: [1,3,5,6], 2
输出: 1

示例 3:
输入: [1,3,5,6], 7
输出: 4

示例 4:
输入: [1,3,5,6], 0
输出: 0

*/

/*
思路：二分查找
*/

int searchInsert(int* nums, int numsSize, int target){
    if(nums == NULL || numsSize <= 0)   return -1;

    int left = 0;
    int right = numsSize-1;

    while(left <= right)
    {
        int mid = left + (right-left)/2;
        if(nums[mid] > target)
            right = mid-1;
        else if(nums[mid] < target)
            left = mid +1;
        else 
            return mid;    
    }

    return left;//直接就返回left

}


//我用的二分，在结尾做了一些判断
int searchInsert(int* nums, int numsSize, int target){
    if(nums == NULL || numsSize <= 0)   return -1;

    int left = 0;
    int right = numsSize-1;

    while(left <= right)
    {
        int mid = left + (right-left)/2;
        if(nums[mid] > target)
            right = mid-1;
        else if(nums[mid] < target)
            left = mid +1;
        else 
            return mid;    
    }
    //left溢出检测，例如[1,3,5,6], 7--数组中没有目标值break时left=4，下面数组会越界访问
    left = (left > numsSize-1 )? (numsSize-1):left;
    //溢出位置的值比target小，就插入到溢出位置+1的地方，比target大，就直接插入当前溢出位置
    return (nums[left] < target)?(left+1):(left);

}




