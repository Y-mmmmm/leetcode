#include <stdio.h>



/*
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

示例 1:
给定的树 s:

     3
    / \
   4   5
  / \
 1   2

给定的树 t：

   4 
  / \
 1   2

返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。

示例 2:
给定的树 s：

     3
    / \
   4   5
  / \
 1   2
    /
   0

给定的树 t：

   4
  / \
 1   2

返回 false。
*/



struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//依然是双递归


bool dfs(struct TreeNode* s, struct TreeNode* t)
{
    if(s == NULL && t == NULL)  return true;
    if(s == NULL || t == NULL)  return false;

    return (s->val == t->val)&&dfs(s->left,t->left)&&dfs(s->right,t->right);

}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    if(s == NULL && t == NULL)  return true;
    if(s == NULL || t == NULL)  return false;

    return dfs(s,t)||isSubtree(s->left,t)||isSubtree(s->right,t);

}
