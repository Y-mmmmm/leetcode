/*
给你一个数组 nums 。数组「动态和」的计算公式为：runningSum[i] = sum(nums[0]…nums[i]) 。

请返回 nums 的动态和。

 

示例 1：

输入：nums = [1,2,3,4]
输出：[1,3,6,10]
解释：动态和计算过程为 [1, 1+2, 1+2+3, 1+2+3+4] 。

示例 2：

输入：nums = [1,1,1,1,1]
输出：[1,2,3,4,5]
解释：动态和计算过程为 [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1] 。

示例 3：

输入：nums = [3,1,2,10,1]
输出：[3,4,6,16,17]

 
提示：

    1 <= nums.length <= 1000
    -10^6 <= nums[i] <= 10^6

*/

//这道题很简单，但需要注意的是，面试时需要问面试官这道题能不能在输入数组上做修改，不能的话在设计函数签名时最好加const

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){

    if(nums == NULL || numsSize <1)
    {
        *returnSize = 0;
        return NULL;
    }
    int *res = (int *)calloc(numsSize,sizeof(int));
    if(res == NULL) return NULL;

    int sum = 0;

    for(int i=0;i<numsSize;i++)
    {
        sum += nums[i]; //也可以直接res[i] = res[i-1]+nums[i]

        res[i] = sum;
    }

    *returnSize = numsSize;
    return res;

}

