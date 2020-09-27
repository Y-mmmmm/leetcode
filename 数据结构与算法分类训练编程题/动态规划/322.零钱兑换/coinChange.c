#include <stdio.h>

/*
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

示例 1:
输入: coins = [1, 2, 5], amount = 11
输出: 3 
解释: 11 = 5 + 5 + 1

示例 2:
输入: coins = [2], amount = 3
输出: -1

说明:
你可以认为每种硬币的数量是无限的。

*/

/*

思路：动态规划
1.确定 base case 初值  ：金额为0时返回0
2.确定状态             ：只有金额的状态的会改变，每选择一次硬币，金额就会减少
3.确定状态转移方程      ：dp[n]表示金额为n时的最少硬币选择数
                        dp[i] = min(dp[i],1 + dp[i-coin])


明确 base case -> 明确「状态」-> 明确「选择」 -> 定义 dp 数组/函数的含义。

# 初始化 base case
dp[0][0][...] = base
# 进行状态转移
for 状态1 in 状态1的所有取值：
    for 状态2 in 状态2的所有取值：
        for ...
            dp[状态1][状态2][...] = 求最值(选择1，选择2...)



*/



int coinChange(int* coins, int coinsSize, int amount){
    if(coins == NULL || coinsSize <= 0) return -1;

    int n = amount + 1;
    int dp[n];
    for(int i=0;i<n;i++)
        dp[i] = n; //初始化 = 金额加1，因为全用1块的，最多只有amount个，求最小值初始化为最大值，所以多加一个相当于初始化为最大值

    dp[0] = 0;

    for(int i=0;i<n;i++)//固定金额
    {
        for(int j=0;j<coinsSize;j++)//在金币中找
        {
            if(i-coins[j] < 0)  continue;//金额 - 币值 < 0 说明不需要这么大的币值，直接跳过

            dp[i] = fmin(dp[i],1+dp[i-coins[j]]); //选择一个 (+1)币值coins[j]后，再根据剩下的金额i-coins[j]选择最小的硬币数dp[i-coins[j]]
        }
    }

    return dp[amount] == amount+1 ? -1:dp[amount];//如果所需的硬币数为初值，说明没有进行改变，返回-1，否则返回最小值

}










