/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

    所有数字（包括目标数）都是正整数。
    解集不能包含重复的组合。 

示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]

*/



/*


在全排列的问题里，相同的数字集合，不同的顺序表示了不同的排列。visited 数组表示了哪些数字已经出现过，接下来不能使用；

而组合问题里，由于不强调顺序，包含了一个数字的所有组合得到以后，下一轮搜索就不能再含有这个数字，否则会出现重复。因此需要设置搜索起点 begin。

这是它们二者的区别，因此不能使用找排列的方法找组合。从深度优先遍历的角度理解回溯算法，就相对容易了。必要的时候需要画图思考。

**重点还是去重**


解释语句: if(i>begin && candidates[i] == candidates[i-1])  是如何避免重复的。

这个避免重复当思想是在是太重要了。

这个方法最重要的作用是，可以让同一层级，不出现相同的元素。即
                  1
                 / \
                2   2  这种情况不会发生 但是却允许了不同层级之间的重复即：
               /     \
              5       5
                
                例2
                  1
                 /
                2      这种情况确是允许的
               /
              2  
                
为何会有这种神奇的效果呢？
首先 i-1 == i 是用于判定当前元素是否和之前元素相同的语句。这个语句就能砍掉例1。

可是问题来了，如果把所有当前与之前一个元素相同的都砍掉，那么例2的情况也会消失。

因为当第二个2出现的时候，他就和前一个2相同了。
                
那么如何保留例2呢？
那么就用 i > begin 来避免这种情况，你发现例1中的两个2是处在同一个层级上的

例2的两个2是处在不同层级上的。

在一个for循环中，所有被遍历到的数都是属于一个层级的。我们要让一个层级中，

必须出现且只出现一个2，那么就放过第一个出现重复的2，但不放过后面出现的2。

第一个出现的2的特点就是 i == begin. 第二个出现的2 特点是 i > begin.


*/

class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        int len = candidates.size();
        if(len == 0)    return res;

        sort(candidates.begin(),candidates.end());//先排序

        backtrack(candidates,target,0);
        return res;
        
    }

    void backtrack(vector<int>& candidates, int target,int begin)
    {
        if(target < 0 ) return;

        if(target == 0)
        {
            res.push_back(path);
            return;
        }

        for(int i=begin;i<candidates.size();i++)
        {
            if(target < candidates[i] || (i>begin && candidates[i] == candidates[i-1])) //i > begin
                continue;

            path.push_back(candidates[i]);

            backtrack(candidates,target - candidates[i],i+1);//i+1去下一层找

            path.pop_back();

        }

    }
};


