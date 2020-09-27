#include <stdio.h>

/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
        3
      /   \
     5     1
    / \   / \
   6   2 0   8
      / \
     7   4 
 
示例 1:
输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。

示例 2:
输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出: 5
解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。

说明:

    所有节点的值都是唯一的。
    p、q 为不同节点且均存在于给定的二叉树中。

*/

/*
注意：本题给的条件是 二叉树 ，元素没有了限制，但最低公共祖先依然满足之前的条件
    p 和 q 在 root 的子树中，且分列 root 的 异侧（即分别在左、右子树中）；
    p=root，且 q 在 root 的左或右子树中；
    q=root，且 p 在 root 的左或右子树中；

    对二叉树进行后序遍历：left right root

    递归出口就是都为空或者找到q，p之一
    1.先递归在左子树中找，找到p或者q就返回该节点，就是祖先
      再递归在右子树中找，找到p或者q就返回该节点，就是祖先
    2.若左子树中没找到，意味着p或者q就在右子树中，直接返回右子树找到的当前节点（在这里隐藏了一个判断，就是左右都为空时，返回空，因为此时右也空）
    3.若右子树中没找到，意味着都在左子树，直接返回左子树找到的当前节点
    4.如果都不为空，说明在当前节点两侧，直接返回当前节点

*/




struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q){
    
    if(root == NULL || root == p || root == q)  return root;//递归出口
    //后序遍历
    struct TreeNode *left = lowestCommonAncestor(root->left,p,q);//先递归在左子树中找，找到p或者q就返回该节点，就是祖先
    struct TreeNode *right = lowestCommonAncestor(root->right,p,q);//再递归在右子树中找，找到p或者q就返回该节点，就是祖先

    if(left == NULL)    return right;//若左子树中没找到，意味着p或者q就在右子树中，直接返回右子树找到的当前节点（在这里隐藏了一个判断，就是左右都为空时，返回空，因为此时右也空）
    else if(right == NULL)   return left;//若右子树中没找到，意味着都在左子树，直接返回左子树找到的当前节点
    else    return root;//如果都不为空，说明在当前节点两侧，直接返回当前节点

}

