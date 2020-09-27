#include <stdio.h>
#include <stdlib.h>

/*
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

示例 1:
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5

示例 2:
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4

说明:
你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

*/

/*
TopK问题
1.快速排序后取a[len-k] -- 面试不推荐
2.优化快速排序 -- 以 第 len - K 元素 作为基准数切分，若切分返回系数恰好=len - K，此时左边都是a[K]小，右边都比a[K]大，
                直接返回a[K]，否则根据返回系数与K的大小关系重新切分
                注意：基准数的选择最好随机，否则在排序数组这个极端情况下，时间复杂度最大O(N^2)！
3.最大堆、最小堆问题

*/


//方法1 
int cmp(void *a,void *b)
{
    return *(int *)a - *(int *)b;
}

int findKthLargest(int* nums, int numsSize, int k){
    if(nums == NULL || numsSize <= 0 || k < 1)  return -1;

    qsort(nums,numsSize,sizeof(int),cmp);

    return nums[numsSize - k];

}

//方法2
#define swap1(a,b)   do{a ^= b;b ^= a;a ^= b;}while(0)

int partition(int *nums,int left,int right)
{
    
    if(right > left)
    {
        //int index = rand()%(right - left + 1) + left; //用这个，控制台对，提交错，搞不懂
        int index = (right + left)/2 + 1;
        swap1(nums[left],nums[index]);
    }
    
    int x = nums[left]; //挖坑
    int i = left;
    int j = right;

    while(i<j)
    {
        while(nums[j] >= x && i < j)    j--; //找右边第一个比基准数小的数，找不到会跳出
        if(i < j)   nums[i++] = nums[j]; //填坑，再得出新坑nums[j]，i坑填完往后移一位，也可以不i++，添加的目的是减少比较次数

        while(nums[i] < x && i < j) i++; //找左边第一个比基准数大的数，找不到也会跳出
        if(i < j)   nums[j--] = nums[i]; //填坑，再得出新坑num[i]，j填坑完前移一位
    }
    nums[i] = x; //i=j时跳出循环，把剩下这个坑填上
    return i;
}


int findKthLargest(int* nums, int numsSize, int k){
    if(nums == NULL || numsSize <= 0 || k < 1)   return -1;
    int left = 0;
    int right = numsSize -1;
    int target = numsSize - k;
    
    while(1)
    {
        int pviot = partition(nums,left,right); //采用迭代方式比使用递归方式可以缩减堆栈深度，从而提高整体性能
        if(target == pviot) return nums[target];
        else if(pviot < target) left = pviot+1;
        else right = pviot-1;
    }
    
}




