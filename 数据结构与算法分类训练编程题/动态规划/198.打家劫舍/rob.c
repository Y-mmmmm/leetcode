
/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

 

示例 1：

输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。

示例 2：

输入：[2,7,9,3,1]
输出：12
解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。

*/

//还可以降低数组，dp[i]只与dp[i-1]和dp[i-2]有关

#define max2(a,b)   ((a)>(b)?(a):(b))

int rob(int* nums, int numsSize){
    if(nums == NULL || numsSize < 1)    return 0;

    int dp[numsSize + 1];//偷前i家的最大值， f[i] 表示前 i 间房屋能偷窃到的最高金额
    dp[0] = 0;
    dp[1] = nums[0];

    for(int i=2;i <= numsSize;i++)
    {
        dp[i] = max2(dp[i-1],dp[i-2] + nums[i-1]); //第i家不偷，就与前i-1家有关；偷第i家，就与前i-2家有关      
    }
    return dp[numsSize];
}


#define max2(a,b)   ((a)>(b)?(a):(b))

int rob(int* nums, int numsSize){
    if(nums == NULL || numsSize < 1)    return 0;

    int fn = 0;
    int fn_1 = 0;
    int fn_2 = 0;

    for(int i=0;i < numsSize;i++)
    {
        fn = max2(fn_1,fn_2 + nums[i]); //第i家不偷，就与前i-1家有关；偷第i家，就与前i-2家有关
        fn_2 = fn_1;
        fn_1 = fn;      
    }
    return fn_1;
}
