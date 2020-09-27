#include <stdio.h>
#include <stdbool.h>

/*
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

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

返回 false

*/

/*
本题的解题流程就是模板！

思路：递归
    1.遍历s节点，确定哪个节点是t的根节点
    2.如果 s 的当前节点值与 t 的根节点值相同，调用 recur 函数判断子树是否也相同；
    3.如果不同，就递归调用主函数来寻找 s 的哪个节点与 t 的根节点匹配。

注意：本题关键在于子结构要完全一样才是子树，所以判断条件会严格一点

*/


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
//如果 s 的当前节点值与 t 的根节点值相同，调用 recur 函数判断子树是否也相同；
//如果不同，就递归调用主函数来寻找 s 的哪个节点与 t 的根节点匹配。
bool recur(struct TreeNode* s, struct TreeNode* t)
{
    if(s == NULL && t == NULL )   return true; //s和t同时遍历完了，才返回true
    if(s == NULL || t == NULL )   return false; //有一个先NULL 就是false

    return (s->val == t->val)&& recur(s->left,t->left)&&recur(s->right,t->right);//左右树都要判定 &&
}

//确定 s 的哪个节点是 t 的根节点
bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    
    return (s != NULL && t != NULL)&&(recur(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t));
}
