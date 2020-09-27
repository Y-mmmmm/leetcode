#include <stdio.h>
#include <stdlib.h>

//时间复杂度 O(n)
//空间复杂度 O(1)
//答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
//0 <= n <= 100
size_t Fibonacci(int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;

    size_t Fn = 0;
    size_t Fn_1 = 1;
    size_t Fn_2 = 0;

    for(int i = 2; i <= n; i++)
    {
        Fn = (Fn_1 + Fn_2)%1000000007;//防止溢出
        Fn_2 = Fn_1; //先赋值
        Fn_1 = Fn;   //后     
    }
    
    return Fn;
}

