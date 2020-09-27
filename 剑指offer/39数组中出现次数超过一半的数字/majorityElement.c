#include <stdio.h>
#include <stdlib.h>


/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1:
输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2

限制：
1 <= 数组长度 <= 50000
*/

/*
思路：
1.哈希--但是存在一些问题，数组元素为负，哈希表就会访问越界；哈希的数组长度与元素值大小有关
2.排序法--数字出现超过数组长度一半，这个数即为众数。经过排序后，数组中位值一定也是众数
3.摩尔投票法：核心理念为 “正负抵消”，思路就是众数是大于一半的，那两两抵消后，一定他会多余出来；
            捉对厮杀，不同的抵消，最后剩下的是众数

*/

//排序法 O(Nlog2​N)
int cmp(void *a,void *b)
{
    return *(int *)a - *(int *)b;
}

int majorityElement(int* nums, int numsSize){
    if(nums == NULL || numsSize <= 0)   return -1;
    qsort(nums,numsSize,sizeof(int),cmp);

    return nums[numsSize/2];
}


//摩尔投票法，时间和空间复杂度分别为 O(N)和 O(1)
int majorityElement(int* nums, int numsSize){
    if(nums == NULL || numsSize <= 0)   return -1;
    int target; //目标值
    int vote = 0; //投票值
    int cnt = 0; //票数值

    for(int i=0;i<numsSize;i++)
    {
        if(vote == 0)    target = nums[i]; //票数为0，更新目标值

        if(target == nums[i])   
	cnt = 1; //目标值与当前值相等，票数记为1
        else    
	cnt = -1; //不等则为-1

        vote += cnt; //累加投票值，也就是数组元素两两不同则抵消，相同则继续往下比较
    }

    return target;

}

int majorityElement(int* nums, int numsSize){
    if(nums == NULL || numsSize <= 0)   return -1;
    int target; //目标值
    int vote = 0; //投票值

    for(int i=0;i<numsSize;i++)
    {
        if(vote == 0)    target = nums[i]; //票数为0，更新目标值

        vote += (target == nums[i] ? 1 : -1);
    }

    return target;

}

/*
//C++哈希 O(N)和 O(N)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto i:nums)
        {
            map[i]++;
            if(map[i] > nums.size()/2)  return i;
        }
        return 0;
    }
};
*/
