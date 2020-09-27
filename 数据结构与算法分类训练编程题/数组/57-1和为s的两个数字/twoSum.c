#include <stdio.h>

/*
输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[2,7] 或者 [7,2]

示例 2：

输入：nums = [10,26,30,31,47,60], target = 40
输出：[10,30] 或者 [30,10]

*/


/*
思路：
1.暴力法 遍历--会超时
2.建立哈希表，然后再查找
3.二分法，限定一个数，再去二分找它对象
4. 双指针 注意题目给出的条件 递增排序的数组 --故效率最高
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    *returnSize = 2;

    int *res = (int *)calloc(2,sizeof(int));

    int i = 0;
    int j = numsSize - 1;

    while(i < j)
    {
        int sum = nums[i] + nums[j];
        if(sum > target)    
            j--;
        else if(sum < target) 
            i++;
        else
        {
            res[0] = nums[i];
            res[1] = nums[j];
            return res;
        }
    }

    return NULL;
}

