#include <stdio.h>

/*
42. 最大子数组 II

给定一个整数数组，找出两个 不重叠 子数组使得它们的和最大。
每个子数组的数字在数组中的位置应该是连续的。
返回最大的和。

例1:

输入:
[1, 3, -1, 2, -1, 2]
输出:
7
解释:
最大的子数组为 [1, 3] 和 [2, -1, 2] 或者 [1, 3, -1, 2] 和 [2].

例2:

输入:
[5,4]
输出:
9
解释:
最大的子数组为 [5] 和 [4].

挑战

要求时间复杂度为 O(n)
注意事项

子数组最少包含一个数

*/

/*
求一维数组中不重叠的两个子数组的最大和

给定一个长度为N的整数数组a，求不重叠的两个子数组的和的最大值。

如a[6]={1, 2, -4, 3, 2, -5}。所取的子数组分别为{1，2}{3, 2}时，两个子数组的和最大，为3+5=8。

这个题目是数组的子数组最大和（即最大连续和）的变形（后面附上了求解子数组最大和的程序）。

一种方法是把数组分成两部分（[0~i]和[i+1~len-1]），分别求两部分的最大连续和相加，再从中选出最大的。时间复杂度是O(N*N)。这种方法在求解最大连续和时会有冗余的计算，需要优化。

第二种方法申请两个独立数组，用sum1[i]记录数组[0~i]的最大连续和，sum2[i]记录数组[i, len-1]的最大连续和。那么max(sum1[i]+sum2[i+1]) for every 0<=i<len-1 就是所求的最大值。时间复杂度O(N)。

*/


int max2Sum(int* arr, int len)
{
    if (arr == NULL || len <= 1)
        return 0;

    
    int sum1[len];// sum1[i]，从0到i的最大连续和
    
    int sum2[len];// sum2[i]，从i到len-1的最大连续和

    int sum = arr[0];
    sum1[0] = sum;

    for (int i = 1; i < len - 1; i++)
    {
        if (sum <= 0)
            sum = arr[i];
        else
            sum += arr[i];
            
        if (sum1[i-1] < sum)
            sum1[i] = sum;
        else
            sum1[i] = sum1[i-1];
    }

    sum = arr[len-1];
    sum2[len-1] = sum;

    for (int i = len - 2; i > 0; i--)
    {
        if (sum <= 0)
            sum = arr[i];
        else
            sum += arr[i];
        if (sum2[i+1] < sum)
            sum2[i] = sum;
        else
            sum2[i] = sum2[i+1];
    }

    int max = sum1[0] + sum2[1];
    for (int i = 1; i < len - 1; i++)
    {
        if (max < sum1[i] + sum2[i+1])
            max = sum1[i] + sum2[i+1];
    }

    return max;
}

//求单个子数组最大和
int maxSum(int* arr, int len)
{
    if (arr == NULL || len <= 0)
        return 0;

    int sum = arr[0];
    int max = sum;
    for (int i = 1; i < len; i++)
    {
        if (sum <= 0)
            sum = arr[i];
        else
            sum += arr[i];
        if (sum > max)
            max = sum;
    }
    return max;
}
//单个子数组最大和 方法2
int maxSubArray(int* nums, int numsSize){
    if(nums == NULL || numsSize <= 0)   return 0;

    int max = nums[0];
    int sum = nums[0];

    for(int i=1;i<numsSize;i++)
    {
        if(nums[i]+sum < nums[i])
            sum = nums[i];
        else
            sum += nums[i];


        if(max < sum)   max = sum;
    }
    return max;
}


int main()
{
    int a[10] = {1,-1,2,2,3,-3,4,-4,5,-4};

    int b[5] = {-1,-1,2,4,5};

    int max1;
    int max2;
    max1 = maxSum(a,10);
    max2 = max2Sum(b,6);
    printf("max1 = %d  max2 = %d\n",max1,max2);

    return 0;

}


