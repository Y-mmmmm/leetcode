#include <stdio.h>

/*
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

示例 1
输入: [0,1,3]
输出: 2

示例 2:
输入: [0,1,2,3,4,5,6,7,9]
输出: 8

*/

/*
注意：排序数组查找，优先考虑二分，因为考题的目的就是考二分

思路：
    本题二分的关键在于找到target，
    首先划分区间 [0  左子区间  mid-1][mid][mid+1  右子区间   n-1]
    因为数组有序且递增，所以 数组元素=下标 ，缺失的元素 ！= 下标
    如果 a[mid] == mid ，说明缺失的元素在右子区间，否则在左子区间
    缩小边界直到left > right ，此时left收缩到了右子区间左边界 = 缺失的位置，返回这个下标


    1.排序数组中的搜索问题，首先想到 二分法 解决。
    2.根据题意，数组可以按照以下规则划分为两部分。

    左子数组： nums[i] = i ；
    右子数组： nums[i] ≠ i；

缺失的数字等于 “右子数组的首位元素” 对应的索引；因此考虑使用二分法查找 “右子数组的首位元素” 。

*/


//二分
int missingNumber(int* nums, int numsSize){

    int left = 0;
    int right = numsSize - 1;

    while(left <= right)
    {
        int mid = left + (right - left)/2;

        if(nums[mid] == mid)   left = mid + 1;        
        else right = mid - 1; 
    }

    return left;
}



//我自己写的简单哈希
int missingNumber(int* nums, int numsSize){
    int haspmap[numsSize+1];
    memset(haspmap,-1,sizeof(int));

    for(int i=0;i<numsSize;i++)
    {
        haspmap[nums[i]] = nums[i];
    }

    for(int i=0;i<=numsSize;i++)
    {
        if(haspmap[i] != i)    return i;
    }

    return -1;
}

//很具题目的意思，直接用数组元素与其下标比较
int missingNumber(int* nums, int numsSize){

    for(int i=0;i<numsSize;i++)
    {
        if(nums[i] != i)    return i;
    }

    return numsSize;
}



