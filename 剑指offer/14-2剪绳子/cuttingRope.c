#include <stdio.h>
#include <stdlib.h>
/*
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

2<= n <=1000
*/

/*由于n的范围变大，结果会以指数倍增长，造成int溢出，采用动态规划求余难度大，故优先考虑贪心算法*/

int cuttingRope(int n){
    if(n < 2) return 0;
    if(n == 2)  return 1;
    if(n == 3)  return 2;

    long ans = 1; //long
    while(n>4)
    {
        ans = (ans * 3)%1000000007; //第一次求余
        n -= 3; 
    }

    ans = (ans * n)%1000000007; //结果还要求余

    return ans;

}

