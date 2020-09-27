#include <stdio.h>


/*
计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
*/

/*
思路：关键在于如何确定 左子节点
*/


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


//方法1
int sumOfLeftLeaves(struct TreeNode* root){
    if(root == NULL)    return 0;

    int leftSum = 0;
    if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
        leftSum = root->left->val;

    return leftSum + sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
}

//方法2 标记法
int dfs(struct TreeNode* root,int leftFlag)
{
    if(root == NULL)    return 0;
    int sum = 0;
    if(leftFlag == 1 && root->left == NULL && root->right == NULL) //只有当前是左节点，并且是叶子节点，才叠加当前值
        sum = root->val;

    return dfs(root->left,1) + dfs(root->right,0) + sum ;
}

int sumOfLeftLeaves(struct TreeNode* root){
    if(root == NULL)    return 0;

    return dfs(root,0);
}



