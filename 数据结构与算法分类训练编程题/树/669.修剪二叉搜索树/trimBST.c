/*
给定一个二叉搜索树，同时给定最小边界L 和最大边界 R。通过修剪二叉搜索树，使得所有节点的值在[L, R]中 (R>=L) 。你可能需要改变树的根节点，所以结果应当返回修剪好的二叉搜索树的新的根节点。

示例 1:

输入: 
    1
   / \
  0   2

  L = 1
  R = 2

输出: 
    1
      \
       2

示例 2:

输入: 
    3
   / \
  0   4
   \
    2
   /
  1

  L = 1
  R = 3

输出: 
      3
     / 
   2   
  /
 1

*/

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };
 

/*
 修剪BST树，其步骤为：
   若为空树，返回NULL;
   否则：
      1.先修剪根，若根的值不在[L,R]范围内，则执行如下循环：
           若根小于下限L，必然有其左子树结点全部小于L，放弃根和左子树，使右子树的根成为新树的根。
           大于上限R的情况同理。最后结束时，要么根为空，要么根的值在[L,R]中。
      2.递归修剪左子树。
      3.递归修建右子树。

题目要求返回BST被修剪后的根结点，那么我们从根结点开始修剪。
1.如果根结点太小，根结点的左子树的所有结点只会更小，说明根结点及其左子树都应该剪掉，因此直接返回右子树的修剪结果。
2.如果根结点太大，根结点的右子树的所有结点只会更大，说明根结点及其右子树都应该剪掉，因此直接返回左子树的修剪结果。
3.如果根结点没问题，则递归地修剪左子结点和右子结点。
4.如果结点为空，说明无需修剪，直接返回空即可。
5.左右子结点都修剪完后，返回自身。

*/

struct TreeNode* trimBST(struct TreeNode* root, int L, int R){
    if (root == NULL)   return NULL;

    //下面两个if相当于删除不满足要求的节点
    if (root->val < L)  return trimBST(root->right, L, R);
        
    if (root->val > R)  return trimBST(root->left, L, R);
        
    root->left = trimBST(root->left, L, R); 
    root->right = trimBST(root->right, L, R);

    return root;
}