/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

示例 1:

输入: [2,3,2]
输出: 3
解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。

示例 2:

输入: [1,2,3,1]
输出: 4
解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。

*/


/*
在I中，dp[i] = max(dp[i-1],dp[i-2]+nums[i-1])

其实就是把环拆成两个队列，一个是从0到n-2，另一个是从1到n-1，然后返回两个结果最大的
考虑三种情况,取最大值即可
1.头尾都不抢 --因为都是正值，取最大值的话这个情况可以不用算
2.头抢尾不抢 dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]); 0<=i<=n-2
3.头不抢尾抢 dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]); 1<=i<=n-1
*/

int myRob(int* nums,int start,int end)
{
    int fn = 0;
    int fn_1 = 0;
    int fn_2 = 0;

    for(int i=start;i<=end;i++)
    {
        fn = fmax(fn_1,fn_2 + nums[i]);
        fn_2 = fn_1;
        fn_1 = fn;
    }
    return fn;
}

int rob(int* nums, int numsSize){
    if(nums == NULL || numsSize <1) return 0;
    if(numsSize == 1)   return nums[0];

    return fmax(myRob(nums,0,numsSize-2),myRob(nums,1,numsSize-1));
}
