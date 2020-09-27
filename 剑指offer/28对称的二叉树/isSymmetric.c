#include <stdio.h>
#include <stdbool.h>

/*

请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

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

示例 1：
输入：root = [1,2,2,3,4,4,3]
输出：true

示例 2：
输入：root = [1,2,2,null,3,null,3]
输出：false

*/

/*
思路：递归

    节点为空，直接true
    终止条件：1. 两节点同时为空则对称 L == NULL && R == NULL  return true
            2.有一个节点不为空则不对称， L == NULL || R == NULL return flase
            3.节点值不等不对称，L->val != R->val  return false

    递推工作：递归判断两节点的  L->left,R->right 和 L->right,R->left 是否对称
    返回值：两对节点都对称时，才是对称树，因此用与逻辑符 && 连接
*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
bool recur(struct TreeNode *L,struct TreeNode *R)
{
    if(L == NULL && R == NULL)  return true;
    if(L == NULL || R == NULL || L->val != R->val)  return false;

    return recur(L->left,R->right)&&recur(L->right,R->left);
}


bool isSymmetric(struct TreeNode* root){
   return root == NULL ? true : recur(root->left,root->right);
}

