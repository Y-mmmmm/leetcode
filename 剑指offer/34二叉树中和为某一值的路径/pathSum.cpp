#include <iostream>
#include <vector>

using namespace std;

/*
输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

注意：一直到叶子节点才结束，不会提前结束
*/

/*
思路：本问题是典型的二叉树方案搜索问题，使用 回溯法 解决，其包含 先序遍历 + 路径记录 两部分

    先序遍历：按照 root root->left root->right 顺序遍历
    路径记录：在先序遍历中，先记录走过的路径，目标值递减节点值，只有到达叶子节点并且目标值=0 
            说明当前路径正确，添加到结果列表中，否则继续遍历，走到叶子节点任然不对，需要pop进行路径恢复。
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root,sum);
        return ans;
    }

    void dfs(TreeNode* root, int target){
        if(root == nullptr)    return; //节点空了，返回上一层

        path.push_back(root->val); //路径记录
        target -= root->val; //更新目标值

        if(target == 0 && root->left == nullptr && root->right == nullptr)
            ans.push_back(path);

        dfs(root->left,target);
        dfs(root->right,target);
        
        path.pop_back(); //左右节点都不满足条件，路径恢复至上一层，也就是删除刚加入路径的节点
    }
};

