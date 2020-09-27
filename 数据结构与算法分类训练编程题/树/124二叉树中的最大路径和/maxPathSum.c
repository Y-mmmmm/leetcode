#include <stdio.h>


/*
给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:

输入: [1,2,3]

       1
      / \
     2   3

输出: 6

示例 2:

输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42

*/


/*
思路：二叉树的后序遍历

注意：本题中二叉树的 路径 的定义；路径可以为 如15->20->7(不经过根节点-10),路径 也可以是 15-> 20-> -10 

*/


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


#define myMax(a,b)  ((a)>(b)?(a):(b))

int dfs(struct TreeNode* node,int *maxSum)
{
    if(node == NULL)    return 0;

    int leftMax = dfs(node->left,maxSum);//取左节点提供的大于0的贡献值
    int rightMax = dfs(node->right,maxSum);//取右节点提供的大于0的贡献值

    leftMax = myMax(leftMax,0);
    rightMax = myMax(rightMax,0);

    int left_node_right = node->val + leftMax + rightMax;

    //计算最大路径贡献值，路径可以为left->root->right;也可以是left(right)->root->rootFather,取最大的
    *maxSum = myMax(*maxSum, left_node_right);

    //返回值为左右最大贡献贡献值+当前节点值
    return node->val + myMax(leftMax,rightMax);
}

int maxPathSum(struct TreeNode* root){
    int res = INT_MIN;
    dfs(root,&res);
    return res;
}
