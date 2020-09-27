#include <stdio.h>


/*
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

示例1:

输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

*/

/*
思路：这道题和[礼物的最大价值]很像
同样采用动态规划做 
dp[i]表示当前最大值，如果前一次的值大于0，那么可以继续加当前值，否则重新开始

如果dp[i-1]>0   dp[i] = dp[i-1] + num[i]
否则 dp[i] = num[i]


如果 我 + 你 还小于我 ，那分手，我重新开始

*/

int maxSubArray(int *nums，int numsSize) 
{
	int dp[numsSize];
	dp[0] = nums[0];
	int max = nums[0];
	for (int i = 1; i < numsSize; i++) 
	{
		dp[i] = fmax(dp[i- 1] + nums[i], nums[i]);
	
		if (max < dp[i]) 	max = dp[i];
	}
	return max;
}


#define myMax(a,b)  (a)>(b)?(a):(b)

int maxSubArray(int* nums, int numsSize){
    if(nums == NULL || numsSize <= 0)   return 0;

    int dp_cur = 0;
    int dp_pre = 0;
    int res = nums[0]; //初始化为最大值，例如测试用例[-1]

    for(int i=0;i<numsSize;i++)
    {        
        if(dp_pre > 0)
            dp_cur = dp_pre + nums[i];
        else
            dp_cur = nums[i];

        dp_pre = dp_cur;//更新前一次的值
        res = myMax(res,dp_cur); //取最大的和
    }

    return res;
}

//换个简便点的
int maxSubArray(int* nums, int numsSize){
    if(nums == NULL || numsSize <= 0)   return 0;

    int res = nums[0];
    int sum = nums[0];

    for(int i=1;i<numsSize;i++)
    {
        if(nums[i] + sum < nums[i]) //我 + 你 还小于我 ，那分手，我重新开始
            sum = nums[i];
        else 
            sum += nums[i];

        if(res < sum)   res = sum;           
    }
    return res;
}

//贪心
int maxSubArray(int* nums, int numsSize){
    if(nums == NULL || numsSize <= 0)   return 0;

    int res = nums[0];
    int sum = nums[0];

    for(int i=1;i<numsSize;i++)
    {
        if(sum <= 0) 
            sum = nums[i];
        else 
            sum += nums[i];

        if(res < sum)   res = sum;           
    }
    return res;
}
