#include <stdio.h>



struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*
给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

例如：

输入: 原始二叉搜索树:
              5
            /   \
           2     13

输出: 转换为累加树:
             18
            /   \
          20     13

*/

/*
二叉搜索树 中序遍历！！！

观察发现：原二叉树 2-5-13
        累加树 20-18-13

        就是依次把后一个节点加到前一个节点上


*/



//逆中序遍历，从后往前累加
struct TreeNode* backPostOrder(struct TreeNode* root,int *sum)
{
    if(root != NULL)
    {
        backPostOrder(root->right,sum);
        *sum += root->val;
        root->val = *sum;
        backPostOrder(root->left,sum);
    }
    return root;
}

struct TreeNode* convertBST(struct TreeNode* root){

    int sum = 0;
    
    return backPostOrder(root,&sum);
}
