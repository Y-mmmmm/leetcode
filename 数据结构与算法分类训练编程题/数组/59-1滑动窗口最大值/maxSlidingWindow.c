#include <stdio.h>
#include <stdlib.h>


/*
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

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

提示：
你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。

*/

/*
思路：
1.维护一个单调递减的双端队列，最大值放队首
2.极值法
*/


//极值法

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
       


