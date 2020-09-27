#include <stdio.h>

/*
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
        6
      /   \
     2     8
    / \   / \
   0   4 7   9
      / \
     3   5 

示例 1:
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6 
解释: 节点 2 和节点 8 的最近公共祖先是 6。

示例 2:
输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。

说明:

    所有节点的值都是唯一的。
    p、q 为不同节点且均存在于给定的二叉搜索树中。

*/

/*
题目给出的条件：
1.二叉搜索树 则 left < root < right
2.公共祖先可以是节点本身

思路：
给的参数是 根节点 节点p 节点q ；
若 root 是 p,q 的 最近公共祖先 ，则只可能为以下情况之一：

    p 和 q 在 root 的子树中，且分列 root 的 异侧（即分别在左、右子树中）；
    p=root，且 q 在 root 的左或右子树中；
    q=root，且 p 在 root 的左或右子树中；

循环搜索： 当节点 root 为空时跳出；

    当 p,q 都在 root 的 右子树 中，则遍历至 root.righ ；
    否则，当 p,q 都在 root 的 左子树 中，则遍历至 root.left ；
    否则，说明找到了 最近公共祖先 ，跳出。

返回值： 最近公共祖先 root 。
*/


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {

    struct TreeNode *cur = root;

    while(cur != NULL)
    {
        if(cur->val > p->val && cur->val > q->val)
            cur = cur->left;
        else if(cur->val < p->val && cur->val < q->val)
            cur = cur->right;
        else
            break;
    }

    return cur;   
}


