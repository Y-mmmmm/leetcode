/*
翻转一棵二叉树。

示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9

输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


//本质还是后序遍历
struct TreeNode* invertTree(struct TreeNode* root){
    if(root == NULL)    return NULL;

    struct TreeNode *left = invertTree(root->left);
    struct TreeNode *right = invertTree(root->right);

    root->left = right;
    root->right = left;

    return root;
}
