#include <stdio.h>
#include <stdlib.h>


/*
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。
要求时间复杂度是O(n)，空间复杂度是O(1)。

示例 1：
输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]

示例 2：
输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]

*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 /*
 思路：不用哈希的话，只有位运算

 1.异或满足交换律，第一步异或，相同的数其实都抵消了，剩下两个不同的数。
 2.这两个数异或结果肯定有某一位为1，不然都是0的话就是相同数。
 3.找到这个位，不同的两个数一个在此位为0，另一个为1。
 4.按此位将所有数分成两组，分开后各自异或，相同的两个数异或肯定为0（而且分开的时候，两个数必为一组）。
 
 */

/*
    1.异或操作，相同的抵消，不同的留下
    2.先全部异或，把重复的都抵消，留下两个不同的值的异或结果
    3.两个数不同，在二进制位上相同的为0，不同的为1，找到这个1，然后根据这个1区分出原数组的自己
    4.关键在于如何找出这个1，a&(-a) 就是这个最低不同的1所在位的值，负数以补码存储
    5.分开两个不同的数后，分别进行异或即可
 */

int* singleNumbers(int* nums, int numsSize, int* returnSize){
    if(nums == NULL)
    {
        *returnSize = 0;
        return NULL;
    }    
    
    int tmp = 0;
    for(int i=0;i<numsSize;i++)
    {
        tmp ^= nums[i];
    }

    int bit = tmp & ((-1)*tmp);//负数以补码存储，自己异或自己的补码 = 最低的某个不同位 的值

    int a = 0 ,b = 0;
    for(int i=0;i<numsSize;i++)
    {
        if((bit & nums[i]) == 0)  //根据这个位把数组中与自己相同的放到另一半去
            a ^= nums[i]; //重新异或，消消乐得出单身狗
        else    
            b ^= nums[i]; 
    }

    *returnSize = 2;
    int *res = (int *)calloc(2,sizeof(int));

    res[0] = a;
    res[1] = b;
   
    return res;
}



