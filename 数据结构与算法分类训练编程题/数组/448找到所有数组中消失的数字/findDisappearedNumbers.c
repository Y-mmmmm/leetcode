#include <stdio.h>
#include <stdlib.h>


/*
给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

找到所有在 [1, n] 范围之间没有出现在数组中的数字。

您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。

示例:

输入:
[4,3,2,7,8,2,3,1]

输出:
[5,6]
*/

/*

注意：题目要求不使用额外空间，那就得原地哈希

思路：标记法
*/


//原地哈希：标记法：将下标 i-1 的位置 取反 ，这样在缺失的数字下标地方还是正数
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    if(nums == NULL || numsSize <= 0)
    {
        *returnSize = 0;
        return NULL;
    }

    int *res = (int *)calloc(numsSize,sizeof(int));
    int cnt = 0;
    for(int i=0;i<numsSize;i++)
    {
        int index = labs(nums[i]);//注意：一定要先对该数取绝对值，因为后面操作会取反，造成下标为负越界
        if(nums[index-1] > 0)
            nums[index-1] *=(-1);       
    }
    
    for(int i=1;i<=numsSize;i++)
    {
        if(nums[i-1]>0)
        {
            res[cnt++] = i;
        }
    }
    
    *returnSize = cnt;
    return res;

}






//普通哈希
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    if(nums == NULL || numsSize <= 0)
    {
        *returnSize = 0;
        return NULL;
    }
    int *hashmap = (int *)calloc(numsSize+1,sizeof(int));
    int *res = (int *)calloc(numsSize,sizeof(int));

    int len = 0;
    for(int i=0;i<numsSize;i++)
    {
        hashmap[nums[i]]++;
    }
    for(int i=1;i<=numsSize;i++)
    {
        if(hashmap[i] == 0)
        {
            res[len++] = i;
        }
    }
    *returnSize = len;
    return res;

}
