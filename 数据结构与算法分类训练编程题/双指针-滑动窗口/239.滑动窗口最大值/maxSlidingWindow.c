
/*
给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

进阶：

你能在线性时间复杂度内解决此题吗？

示例:

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if(nums == NULL || numsSize <= 0)   
    {
        *returnSize = 0;
        return NULL;
    }

    int n = numsSize - k +1;//返回数组长度与窗口 k 有关
    *returnSize = n;

    int *res = (int *)calloc(n,sizeof(int));

    int max = 0; //记录最大值
    int maxIdx = -1;//记录最大值下标

    for(int i = 0;i < n;i++)
    {
        //判断最大值下标是否在滑动窗口内
        if(maxIdx >= i)
        {
            if(nums[i+k-1] > max) //最大值存在于当前于当前窗口，只需与刚加入窗口的值比较
            {
                max = nums[i+k-1];
                maxIdx = i+k-1;//更新
            }
        }
        else //最大值不在窗口内，找到最大值
        {
            max = nums[i];
            for(int j = i;j < i+k;j++) //遍历窗口，找到最大值
            {
                if(max < nums[j])
                {
                    max = nums[j];
                    maxIdx = j;
                }
            }
        }
        res[i] = max;//每次将最大值存入数组
        
    }

    return res;
}
