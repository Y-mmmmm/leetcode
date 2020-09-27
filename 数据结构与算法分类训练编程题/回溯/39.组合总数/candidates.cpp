/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以[无限制重复]被选取。

说明：

    所有数字（包括 target）都是正整数。
    解集不能包含重复的组合。 

示例 1：

输入：candidates = [2,3,6,7], target = 7,
所求解集为：
[
  [7],
  [2,2,3]
]

示例 2：

输入：candidates = [2,3,5], target = 8,
所求解集为：
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

提示：

    1 <= candidates.length <= 30
    1 <= candidates[i] <= 200
    candidate 中的每个元素都是独一无二的。
    1 <= target <= 500

*/

//画出 N 叉树，路径选择就是target - candidates[i]元素来选择，但要考虑取出重复元素的问题，如果第一个分支选择了，后面的分支就不能再选择


class Solution {
public:
    vector<vector<int>> res;
    vector<int>path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        backtrack(candidates,target,0);
        return res;
    }

    void backtrack(vector<int>& candidates,int target,int begin)
    {
        if(target < 0)  return;

        if(target == 0)
        {
            res.push_back(path);
            return;
        }

        //每个candidate[i]都要先一直尝试自身，直到不符合，再尝试candidates[i+1]
        //关键在于去重:每次以当前开始位置一直找，直到减不了就去当前节点后面找，所以不会找到前面
        for(int i = begin; i < candidates.size(); i++)
        {
            if(target < candidates[i])  continue;

            path.push_back(candidates[i]);

            backtrack(candidates, target - candidates[i], i);

            path.pop_back();//回溯
        }
    }
        
};

