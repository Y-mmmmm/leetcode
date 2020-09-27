/*
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 [连续] 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。


示例：

输入：s = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。

进阶：

    如果你已经完成了 O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。

*/

//双指针法
int minSubArrayLen(int s, int* nums, int numsSize){

    if(nums == NULL || numsSize < 1)    return 0;

    int left = 0;
    int right = 0;

    int min = INT_MAX;
    int sum = 0;
    while(right < numsSize)
    {
        sum += nums[right++]; //累加和，右指针右移

        //和>=目标s时，计算此时窗口大小，并将左指针右移
        while(sum >= s)
        {
            min = fmin(min,right-left);
            sum -= nums[left++];
        }  
    }
    return min == INT_MAX ? 0: min; //如果没找到，min还是INT_MAX,那么返回0
}
