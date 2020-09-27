/*
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

*/


class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        int len = nums.size();
        if(len == 0)    return res;

        vector<int>visited(len,0);
        //有重复元素全排列，先排序！排序完之后，重复的元素在一起，重复的前一次选过了就直接返回不选了，方便剪枝
        sort(nums.begin(),nums.end());

        backtrack(nums,visited);

        return res;
    }
    void backtrack(vector<int>& nums,vector<int>&visited)
    {
        if(path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            //如果访问过了，跳过
            //如果和前面一样的，也就是重复的，并且也访问过了，跳过
            if(visited[i] == 1 || (i>0 && nums[i] == nums[i-1] && visited[i-1] == 1))
                continue;

            path.push_back(nums[i]);
            visited[i] = 1;

            backtrack(nums,visited);
            visited[i] = 0;

            path.pop_back();
        }

    }
};