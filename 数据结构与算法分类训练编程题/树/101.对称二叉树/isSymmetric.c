#include <stdio.h>

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


/*
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3

进阶：

你可以运用递归和迭代两种方法解决这个问题吗？

*/


bool dfs(struct TreeNode* L,struct TreeNode* R)
{
    if(L == NULL && R == NULL)    return true; //左右子树同时为空才为true
    if(L == NULL || R == NULL || L->val != R->val)   return false; //只要有一个节点为空或者节点值不对，就是false

    return dfs(L->left,R->right)&&dfs(L->right,R->left); //镜像对比，左子树的左节点和右子树的右节点；左子树的右节点和右子树的左节点
}


bool isSymmetric(struct TreeNode* root){
    if(root == NULL) return true;
   
    return dfs(root->left,root->right);
}





