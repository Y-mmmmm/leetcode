#include <stdio.h>
#include <stdlib.h>

/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：
输入：n = 2
输出：2
示例 2：
输入：n = 7
输出：21
提示：
    0 <= n <= 100
*/

//注意青蛙跳台阶问题： f(0)=1, f(1)=1 , f(2)=2 ；
//斐波那契数列问题： f(0)=0 , f(1)=1 , f(2)=1 


int numWays(int n){
    if(n == 0)
        return 1;
    if(n>0 && n<=3)
        return n;

    long Fn = 0;
    long Fn_1 = 3;
    long Fn_2 = 2;

    for(int i=4;i<=n;i++)
    {
        Fn = (Fn_1 + Fn_2)%1000000007;
        Fn_2 = Fn_1;
        Fn_1 = Fn;
    }
    return Fn;
}

