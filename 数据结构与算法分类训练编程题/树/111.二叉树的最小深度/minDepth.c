#include <stdio.h>


/*
给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明: 叶子节点是指没有子节点的节点。

示例:
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

返回它的最小深度  2.
*/



struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int minDepth(struct TreeNode* root){
    if(root == NULL)    return 0;

    if(root->left != NULL && root->right != NULL)   
        return 1 + fmin(minDepth(root->left),minDepth(root->right)); //左右都不为空，取最小的

    return 1 + fmax(minDepth(root->left),minDepth(root->right)); //其中有一个空或者都为空，取最大的
}
