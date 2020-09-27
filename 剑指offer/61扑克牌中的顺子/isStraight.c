#include <stdio.h>
#include <stdlib.h>


/*
从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，
而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

示例 1:
输入: [1,2,3,4,5]
输出: True

示例 2:
输入: [0,0,1,2,5]
输出: True

限制：
数组长度为 5 
数组的数取值为 [0, 13] .

*/

/*
思路：题目中的大小王=0，也就是癞子

方法1：排序

这道题本质就是数组判断是否连续

1.首先数组长度已经定死 = 5，如果数组连续， 5 = nums[4] - nums[0] + 1
2.癞子是 0 ，最多两张，那么 只要排序好，找到 第一个非0位置，nums[4] - nums[joker] < 5 ,长度在5以内必然连续，否则不连续

先对数组执行排序。
判别重复： 排序数组中的相同元素位置相邻，因此可通过遍历数组，判断 nums[i]=nums[i+1] 是否成立来判重。
获取最大/最小的牌： 排序后，数组末位元素 nums[4] 为最大牌；元素 nums[joker]为最小牌，其中 joker 为大小王的数量。

方法2：不排序，跳过大小王找出最大最小值，做差小于5就是顺子

*/



int cmp(void *a,void *b)
{
    return *(int *)a - *(int *)b;
}


bool isStraight(int* nums, int numsSize){

    qsort(nums,numsSize,sizeof(int),cmp);

    int joker = 0;
    for(int i=0;i<numsSize-1;i++)
    {
        if(nums[i] == 0)    joker++;
        else if(nums[i] == nums[i+1])   return false;   
    }

    return (nums[4]-nums[joker])<5;
}

