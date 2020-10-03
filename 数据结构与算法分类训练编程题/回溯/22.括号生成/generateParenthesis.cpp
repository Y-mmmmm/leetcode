/*
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例：

输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]

*/

/*
思路：回溯/DFS

画出二叉树即可，然后剪枝

*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        dfs(res,"",n,n);

        return res;
    }

    //回溯在于path是值传递，每次都会产生一个新的拷贝
    void dfs(vector<string>& res,string path,int left,int right)
    {
        //递归出口，左右括号都用完了
        if(left == 0 && right == 0)
        {
            res.push_back(path);
            return;
        }
        //剪枝，左括号比右括号多，不是 有效的 括号组合
        if(left > right)
            return;

        //添加左括号
        if(left > 0)
            dfs(res, path + "(", left - 1, right);

        //添加右括号
        if(right > 0)
            dfs(res, path + ")", left, right - 1);
    }
};
