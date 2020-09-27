#include <stdio.h>
#include <stdlib.h>


/*

给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。

找到所有出现两次的元素。

你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？

示例：

输入:
[4,3,2,7,8,2,3,1]

输出:
[2,3]

*/


/*
注意：要求不使用额外空间
和找到消失的数类似

将 i-1 下标位置取反，如果再次遇到已经取反的，该数就是重复数



    找到数字i时，将位置i-1处的数字翻转为负数。
    如果位置i-1 上的数字已经为负，则i是出现两次的数字。

这个题目开头暗示了n的范围，所以可以加以利用，将元素转换成数组的索引并对应的将该处的元素乘以-1；

若数组索引对应元素的位置本身就是负数，则表示已经对应过一次；在结果列表里增加该索引的正数就行；


*/


int* findDuplicates(int* nums, int numsSize, int* returnSize){
    if(nums == NULL || numsSize<=0)
    {
        *returnSize = 0;
        return NULL;
    }
    int *res =(int *)calloc(numsSize,sizeof(int));
    int cnt = 0;

    for(int i=0;i<numsSize;i++)
    {
        int index = labs(nums[i]);//取绝对值

        if(nums[index-1]<0)
            res[cnt++] = index; //再次遇到取反过的，将该数 取绝对值 存储
        else
            nums[index-1] *= (-1);
    } 

    *returnSize = cnt;
    return res;

}








