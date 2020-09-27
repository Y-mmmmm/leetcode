#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*
给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。

例如，
给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和值: 2

你应该返回如下子树:

      2     
     / \   
    1   3

在上述示例中，如果要找的值是 5，但因为没有节点值为 5，我们应该返回 NULL。

*/


//方法1 迭代法
struct TreeNode* searchBST(struct TreeNode* root, int val){

    struct TreeNode *cur = root;

    while(cur != NULL)
    {
        if(val < cur->val)
            cur = cur->left;
        else if(val > cur->val)
            cur = cur->right;
        else if(val == cur->val)
            return cur;
    }

    return NULL;
}

//方法2 递归

struct TreeNode* searchBST(struct TreeNode* root, int val){

    if(root == NULL || root->val == val)    return root;

    if(val < root->val) 
        return searchBST(root->left,val);
    else if(val > root->val) 
        return searchBST(root->right,val);
    else
        return NULL;
}