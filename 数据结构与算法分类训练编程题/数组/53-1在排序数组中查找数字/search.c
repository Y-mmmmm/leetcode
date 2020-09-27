#include <stdio.h>

/*
统计一个数字在排序数组中出现的次数。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2

示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0

限制：

0 <= 数组长度 <= 50000
*/

int findFirstPosition(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] < target)
            left = mid + 1;
        else if(nums[mid] > target)
            right = mid - 1;
        else if(nums[mid] == target)
            right = mid - 1; 
    }
    if(left >= numsSize || nums[left] != target)
    {
        return -1;
    }

    return left;
}

int findLastPosition(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] < target)
            left = mid + 1;
        else if(nums[mid] > target)
            right = mid - 1;
        else if(nums[mid] == target)
            left = mid + 1; 
    }
    if(right < 0 || nums[right] != target)
    {
        return -1;
    }

    return right;
    
}



int search(int* nums, int numsSize, int target){

    if(nums == NULL || numsSize <=0)
        return 0;

    int start = findFirstPosition(nums,numsSize,target);
    if(start == -1)
        return 0;

    int end = findLastPosition(nums,numsSize,target);

    int res = end - start;

    return res+1;

}

