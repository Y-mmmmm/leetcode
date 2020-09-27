/*
实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。


示例 1:
输入: 2.00000, 10
输出: 1024.00000

示例 2:
输入: 2.10000, 3
输出: 9.26100

示例 3:
输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25

说明:
    -100.0 < x < 100.0
    n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。

*/


#include <stdio.h>
#include <stdlib.h>

double myPow(double x, int n){
    if(x == 0)
        return 0;
    if(x == 1 || n == 0)
        return 1;
   
    //虽然题目中告诉我们不需要考虑大数问题，但是给出的n可以取到 −2147483648（整型负数的最小值），
    //n的最大正数为2147483647，负取正溢出，因此，需要将n转换成long 类型。
    long N = n; 
    if(N < 0)
    {
        N = -N;
        x = 1/x;        
    }

    double res = 1;
    while(N)
    {
        if(N & 1 == 1)
        {
            res *= x; //N的二进制bit位为1才可以乘进结果
        }
        x *= x; //N的二进制bit位为0，则进行x的累乘；注意！x=x*x，每循环一次以幂指数级更新的
        N = N>>1; 
    }
    return res;
}







