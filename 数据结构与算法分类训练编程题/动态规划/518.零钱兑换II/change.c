/*
给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币 【组合数】。假设每一种面额的硬币有无限个。 

 

示例 1:

输入: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种方式可以凑成总金额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

示例 2:

输入: amount = 3, coins = [2]
输出: 0
解释: 只用面额2的硬币不能凑成总金额3。

示例 3:

输入: amount = 10, coins = [10] 
输出: 1


注意:

你可以假设：

    0 <= amount (总金额) <= 5000
    1 <= coin (硬币面额) <= 5000
    硬币种类不超过 500 种
    结果符合 32 位符号整数

*/

//这道题和面试题08.11一模一样，是个完全背包问题

int change(int amount, int* coins, int coinsSize){

    int dp[amount+1];

    for(int i=1;i<amount+1;i++)
        dp[i] = 0;

    dp[0] = 1;  //0元也是一种方案

    for(int i=0;i<coinsSize;i++) //固定硬币
    {
        for(int j=coins[i];j<=amount;j++)//根据金额一直累加当前硬币的方案
        {
            dp[j] = dp[j] + dp[j-coins[i]];
        }
    }

    return dp[amount];

}