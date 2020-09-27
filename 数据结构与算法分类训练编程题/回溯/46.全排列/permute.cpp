/*
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

*/

//回溯，全排列，关键在于当前的之后，要在剩下的里面找，所以需要一个辅助数组
//看代码的结构，非常像N叉树的遍历！！！

class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
    vector<vector<int>> permute(vector<int>& nums) {

        int len = nums.size();
        if(len == 0)    return res;
        vector<int> visited(len,0);

        backtrack(nums,len,visited);
       
        return res;
        
    }

    void backtrack(vector<int>& nums,int len,vector<int>&visited)
    {
        if(path.size() == len) //递归出口
        {
            res.push_back(path);
            return;
        }

        for(int i=0;i<len;i++)
        {
            if(visited[i] == 1) continue;//如果当前访问过了，当前元素不进行记录，进行下一轮循环

            path.push_back(nums[i]);
            visited[i] = 1;

            backtrack(nums,len,visited);//递归

            visited[i] = 0;

            path.pop_back();//回溯
        }

    }
};

