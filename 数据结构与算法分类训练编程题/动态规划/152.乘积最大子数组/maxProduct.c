/*
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。

示例 1:

输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。

示例 2:

输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

示例 3:

输入: [0,2]
输出: 2


*/

#define max2(a,b)   ((a)>(b)?(a):(b))
#define max3(a,b,c) max2(a,max2(b,c))

#define min2(a,b)   ((a)<(b)?(a):(b))
#define min3(a,b,c) min2(a,min2(b,c))


/*
本题的关键在于，乘法的特殊性，最大值最小值会因为nums[i]的正负翻转
所以需要考虑nums[i]为负时，选择最优条件
*/
int maxProduct(int* nums, int numsSize){
    if(nums == NULL || numsSize < 1)    return 0;

    int maxDP[numsSize];
    int minDP[numsSize];//维护两个dp数组
    int res = nums[0];
    maxDP[0] = minDP[0] = nums[0];

    for(int i=1;i<numsSize;i++)
    {
        //三者取最大：当前元素，前一个子数组正数乘积*当前元素，前一个子数组的负数乘积*当前元素(nums[i]为负时)->可能翻转为最大正值
        maxDP[i] = max3(nums[i],maxDP[i-1]*nums[i],minDP[i-1]*nums[i]); 
        //三者取最小：当前元素，前一个子数组的正数乘积*当前元素(nums[i]为负时)->可能翻转为最小负值，前一个子数组的负数乘积*当前元素(nums[i]为负时)->可能翻转为最大正值
        minDP[i] = min3(nums[i],maxDP[i-1]*nums[i],minDP[i-1]*nums[i]);

        res = max2(res,maxDP[i]);
    }

    return res;
}

