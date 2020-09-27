#include <stdio.h>


/*
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。

示例 1:

输入: [1,3,4,2,2]
输出: 2

示例 2:

输入: [3,1,3,4,2]
输出: 3

说明：

    不能更改原数组（假设数组是只读的）。
    只能使用额外的 O(1) 的空间。
    时间复杂度小于 O(n2) 。
    数组中只有一个重复的数字，但它可能不止重复出现一次。
*/


/*
注意：限制条件多

方法：快慢指针
*/
int findDuplicate(int* nums, int numsSize){
    if(nums == NULL || numsSize <= 0)   return -1;

    int fast = 0;
    int slow = 0;
    int finder = 0;

    while(1)
    {
        slow = nums[slow];//慢指针走一步
        fast = nums[nums[fast]];//快指针走两步
        if(slow == fast)//在环中相遇
        {
            while(nums[slow] != nums[finder])
            {
                finder = nums[finder]; //快慢指针相遇时，新指针从头与慢指针一起走，直到遇到入口节点
                slow = nums[slow];
            }
            return nums[slow];
        }           
    }
    return -1;   
}




//和题意不符的暴力法
int findDuplicate(int* nums, int numsSize){

    int res = 0;

    for(int i=0;i<numsSize;i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            res = nums[i]^nums[j];
            if(res == 0)
                return nums[i];
        }
    }

    return 0;

}


