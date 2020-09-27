#include <stdio.h>

/*
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7

返回它的最大深度 3 

*/


/*

思路：树的深度 等于 左子树的深度 与 右子树的深度 中的 最大值 +1

方法1.递归/dfs类似树的前序遍历
方法2.BFS,实现原理就是一层层遍历，统计一下总共有多少层；
    树的层序遍历 / 广度优先搜索往往利用 队列 实现。
    关键点： 每遍历一层，则计数器 +1 ，直到遍历完成，则可得到树的深度。


*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 

//方法1
int maxDepth(struct TreeNode* root){
    if(root == NULL)    return 0;

    int left = 1 + maxDepth(root->left);
    int right = 1 + maxDepth(root->right);

    return left > right ? left : right;
}

//方法2
int maxDepth(struct TreeNode* root){
    if(root == NULL)    return 0;
    
    return 1 + fmax(maxDepth(root->left),maxDepth(root->right));

}

