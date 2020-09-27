#include <iostream>
#include <vector>

using namespace std;

/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

示例 1：
输入：target = 9
输出：[[2,3,4],[4,5]]

示例 2：
输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]

*/

/*
思路：滑动窗口

1.连续正数序列 就是 例如 1 2 3 4 5 6 ... 等正数递增序列
2.输出和为目标值的正数序列 意味着 序列值小于 目标值


注意：[l,r) 左闭右开区间
*/


class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {

        int l = 1;//左指针
        int r = 1;//右指针

        vector<vector<int>> res;

        int t = target/2 + 1;//排序数组越往右越大，意味着离目标值越近，左指针的指向不会超过一半
        int sum = 0;

        while(l < t)
        {
            if(sum < target)
            {
                sum += r; //累加右指针指向的数=累加窗口值
                r++; 
            }
            else if(sum > target)
            {
                sum -= l; //窗口值超了，去掉左指针的值，左指针右移，缩小窗口
                l++;
            }
            else
            {
                vector<int> arr;
                for(int i=l;i<r;i++)
                {
                    arr.push_back(i); //记录当前窗口值
                }

                res.push_back(arr); //记录当前这个数组
                sum -= l;//去除左指针指向的值，左指针右移，重新找下一个数组
                l++;
            }           
        }

        return res;
    }
};


