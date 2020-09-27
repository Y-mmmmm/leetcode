#include <stdio.h>

/*
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

示例 1:
输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。

示例 2:
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

限制：

0 <= 数组长度 <= 10^5
*/

/*
思路：一开始我以为是窗口题，但实际上是动态规划

前 i 日的最大利润 = max(前 i-1 日最大利润，当日价格 - 最低价格)
动态规划 前i天的最大收益 = max{前i-1天的最大收益，第i天的价格-前i-1天中的最小价格}

dp[i] = max(dp[i-1],prices[i] - minPrice[0;i]);

使用迭代优化空间

*/


int maxProfit(int* prices, int pricesSize){

    if(prices == NULL || pricesSize <= 0)   return 0;

    int minPrice = prices[0];/*初始化*/
    int maxProfit = 0;

    for(int i=1;i<pricesSize;i++)
    {
        minPrice = fmin(minPrice,prices[i]);/*找到最低价格，以最低价格买入*/
        maxProfit = fmax(maxProfit,prices[i]-minPrice);/*根据 当前价格-最低价 选取最大利润*/
    }

    return maxProfit;
}



