/*
题目描述
Redraiment是走梅花桩的高手。Redraiment可以选择任意一个起点，从前到后，但只能从低处往高处的桩子走。他希望走的步数最多，你能替Redraiment研究他最多走的步数吗？

本题含有多组样例输入

输入描述:
输入多行，先输入数组的个数，再输入相应个数的整数

输出描述:
输出结果

示例1
输入

6
2 5 1 5 4 5 
3
3 2 1

输出

3
1

说明

6个点的高度各为 2 5 1 5 4 5
如从第1格开始走,最多为3步, 2 4 5
从第2格开始走,最多只有1步,5
而从第3格开始走最多有3步,1 4 5
从第5格开始走最多有2步,4 5
所以这个结果是3。  


*/


#include <stdio.h>
#include <stdlib.h>

#define myMax(a,b)    ((a)>(b)?(a):(b))

/*
求最长上升子序列
动态规划：
定义：dp[i]表示以a[i]为结尾的最长上升子序列的长度
base case ：dp[i] = 1；以自己结尾的都是1

转移方程：
if(a[j]<a[i])    前i个中存在一个以j结尾的元素严格小于a[i],那么a[i]可以接在后面
    dp[i] = max(dp[i],dp[j]+1); 0<= j <i;dp[j]表示前i个中第j个元素结尾的最长上升子序列的长度

*/

int main()
{
    int n;
    
    while(scanf("%d",&n)!=EOF)
    {
        int dp[n];
        int a[100];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            dp[i] = 1;//初始化
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(a[j] < a[i])
                    dp[i] = myMax(dp[i],dp[j]+1);
            }
        }
        
        int max = 0;
        for(int i=0;i<n;i++)
        {
            max = myMax(max,dp[i]);
        }
        printf("%d\n",max);
    }
    return 0;
}

