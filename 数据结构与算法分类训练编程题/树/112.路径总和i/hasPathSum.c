#include <stdio.h>

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例: 
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
*/

//注意：题目要求必须从根节点到叶子节点




//方法1 简单递归

bool hasPathSum(struct TreeNode* root, int sum){
    if(root == NULL) return false;

    sum -= root->val;

    if(root->left == NULL && root->right == NULL && sum == 0) return true;//只有到达叶子节点并且和为0时，才是一条路径

    return hasPathSum(root->left,sum)||hasPathSum(root->right,sum);//否则和不为0，继续往子树中找
}







