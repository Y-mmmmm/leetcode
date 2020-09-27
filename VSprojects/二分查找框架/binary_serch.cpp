#include <iostream>

/*
作者：labuladong
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
/*
注意边界问题

    1.把定义区间成为左闭右闭区间，左右边界是无差别的，弄成左闭右开，反而增加了思考的复杂程度；

    2.明确 int = left + ( right - left ) / 2 这里除以 2 是下取整；

    3.明确 while(left <= right) 和 while(left < right) 这两种写法其实在思路上有本质差别，
        while(left <= right) 在循环体内部直接[查找]元素，
        while(left < right)  在循环体内部一直在[排除]元素，第 2 种思路在解决复杂问题的时候，可以使得问题变得简单；

    4.始终在思考下一轮搜索区间是什么，把它作为注释写到代码里面，就能帮助我们搞清楚边界是不是能取到，等于、+1 、-1 之类的细节；

    5.思考清楚每一行代码背后的语义是什么，保证语义上清晰，也是写对代码，减少 bug 的一个非常有效的策略。

*/

int binary_search(int[] nums, int target) 
{
    int left = 0, right = nums.length - 1; 
    while(left <= right) 
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) 
        {
            left = mid + 1;
        } 
        else if (nums[mid] > target) 
        {
            right = mid - 1; 
        } 
        else if(nums[mid] == target) 
        {
            // 直接返回
            return mid;
        }
    }
    // 直接返回
    return -1;
}


//多个数相同时，找左边界

int left_bound(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
    // 搜索区间为 [left, right]
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            // 搜索区间变为 [mid+1, right]
            left = mid + 1;
        } else if (nums[mid] > target) {  
            // 搜索区间变为 [left, mid-1]
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 收缩右侧边界
            right = mid - 1;//<<--重点  
        }
    }
    // 检查出界情况
    if (left >= nums.length || nums[left] != target)//<<--重点
        return -1;
    return left;
}

//多个数相同时，找右边界
int right_bound(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else if (nums[mid] == target) {
            // 这里改成收缩左侧边界即可
            left = mid + 1;//<<--重点
        }
    }
    // 这里改为检查 right 越界的情况
    if (right < 0 || nums[right] != target)//<<--重点
        return -1;
    return right;
}

