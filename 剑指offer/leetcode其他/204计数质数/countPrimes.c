#include <stdio.h>

/*
统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

*/

/*
思路：
1.暴力法，遍历素数，计数1——超时
2.厄拉多塞筛法

*/

//厄拉多塞筛法：类似于哈希，以空间换时间；2，3，5，7是素数，那么他们的倍数都不是素数
int countPrimes(int n){
    int a[n+1];
    int cnt = 0;
    for(int i=2;i<n;i++)
    {
        a[i] = 1;//初始将表格从2开始全部填为1
    }

    for(int i=2; i < n;i++)
    {
        if(a[i]) //被下面改为0的，不会再进入
        {
            for(int j=2*i; j<n; j += i)
            {
                a[j] = 0;//依次把2，3，5，7的倍数全部填为0
            }
        }
    }

    for(int i=2;i<n;i++)
    {
        if(a[i])    cnt++;//剩下的就是素数
    }

    return cnt;
}


//优化一下
int countPrimes(int n){
    int a[n+1];
    int cnt = 0;
    for(int i=2;i<n;i++)
    {
        a[i] = 1;
    }

    for(int i=2; i*i < n;i++) //计数不需要到n，后面是重复的
    {
        if(a[i])
        {
            for(int j=i*i; j<n; j += i) //j从i^2开始
            {
                a[j] = 0;
            }
        }
    }

    for(int i=2;i<n;i++)
    {
        if(a[i])    cnt++;
    }

    return cnt;
}


//
int countPrimes(int n)
{
    int a[n+1]; 
    int count = 0;
    for(int i = 2; i < n; i++)
        a[i] = 1;
    
    for(int i = 2; i < n; i++)
        if(a[i])
        {
            count++;//把计数放进来，因为只要在 i 为素数时，才会把 i 的倍数置 0
            for(int j = 2 * i; j < n; j += i)
                a[j] = 0;
        }
    
    return count;
}