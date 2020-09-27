#include <stdio.h>

/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是 O(log n) 级别。
如果数组中不存在目标值，返回 [-1, -1]。

示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]

示例 2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

*/

/*
思路：两次二分查找

*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//-------------------------------------------------------------------
int findFirstPosition(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize-1;

     while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            // 搜索区间变为 [mid+1, right]
            left = mid + 1;
        } else if (nums[mid] > target) {
            // 搜索区间变为 [left, mid-1]
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 收缩右侧边界
            right = mid - 1;
        }
    }
    // 检查出界情况
    if (left >= numsSize|| nums[left] != target)
        return -1;
    return left;
}

int findLastPosition(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize-1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 这里改成收缩左侧边界即可
            left = mid + 1;
        }
    }
    // 这里改为检查 right 越界的情况
    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}


int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *ret = (int *)malloc(sizeof(int)*2);
    memset(ret,-1,sizeof(int)*2);
    *returnSize = 2;
    if(nums == NULL || numsSize <=0)
        return ret;

    int start = findFirstPosition(nums,numsSize,target);
    if(start == -1)
        return ret;

    int end = findLastPosition(nums,numsSize,target);

    *ret = start;
    *(ret+1) = end;

    return ret;
    
}




//-------------------------------------------------------------------
int findFirstPosition(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize-1;

    while(left < right)
    {
        int mid = (right + left)>>1; /*mid下取整*/
        /*mid严格小于目标值，则下一轮查找范围[mid+1,right]*/
        if(nums[mid] < target)
        {
            left = mid + 1;
        }            
        /*反之，在[left,mid]范围只可能是开始位置*/
        else if(nums[mid] >= target)
        {
            right = mid;
        }
            
    }
    if(nums[left] != target)
        return -1;

    return left;
}

int findLastPosition(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize-1;

    while(left < right)
    {
        int mid =(right + left + 1)>>1; /*mid要上取整*/
        /*mid严格大于目标值，则下一轮查找范围[left,mid-1]*/
        if(nums[mid] > target)
        {
            right = mid - 1;
        }
        /*反之，在[mid,right]只可能是结束位置*/        
        else if(nums[mid] <= target)
        {
            left = mid;
        }
            
    }
    if(nums[left] != target)
        return -1;

    return left;

}


int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *ret = (int *)malloc(sizeof(int)*2);
    memset(ret,-1,sizeof(int)*2);
    *returnSize = 2;
    if(nums == NULL || numsSize <=0)
        return ret;

    int start = findFirstPosition(nums,numsSize,target);
    if(start == -1)
        return ret;

    int end = findLastPosition(nums,numsSize,target);

    *ret = start;
    *(ret+1) = end;

    return ret;
    
}


