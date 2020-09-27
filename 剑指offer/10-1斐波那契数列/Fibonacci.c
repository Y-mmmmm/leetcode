/*
1.斐波那契数列数列公式
    F(0) = 0;
    F(1) = F(2) = 1;
    F(n) = F(n-1)+F(n-2);

2.需要考虑F(n)溢出的问题
3.综合时间复杂度和空间复杂度
*/

#include <stdio.h>
#include <stdlib.h>

//时间复杂度 O(2^n)
//空间复杂度 O(1)
size_t Fibonacci_1(int n)
{
    if(n <= 0)
        return 0;
    if(n == 1||n==2)
        return 1;
    if(n >= 3)
        return Fibonacci_1(n-1)+Fibonacci_1(n-2);

}

//时间复杂度 O(n)
//空间复杂度 O(n)
size_t Fibonacci_2(int n)
{
    if(n < 0)
        return 0;

    size_t a[40];
    a[0]=0;
    a[1]=a[2] = 1;
    for(int i=3;i<40;i++)
    {
        a[i] = a[i-1]+a[i-2];
    }
    return a[n];

}

//时间复杂度 O(n)
//空间复杂度 O(1)
//答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
//0 <= n <= 100
size_t Fibonacci_3(int n)
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




void main()
{
    printf("%d\n",Fibonacci_1(10));

    printf("%d\n",Fibonacci_2(10));

    printf("%d\n",Fibonacci_3(10));
}
