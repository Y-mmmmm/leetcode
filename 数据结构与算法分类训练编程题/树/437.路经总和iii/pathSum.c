#include <stdio.h>

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*
给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

示例：

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:

1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11
*/


//方法一，效率偏低
//还是DFS 双递归
int dfs(struct TreeNode* root, int sum)
{
    if(root == NULL)    return 0; //当前节点为空，返回0

    sum -= root->val ; //到达当前节点时，还剩的值
    
    //如果sum已经递减到0了，说明存在一条路径
    //否则继续往下找
    return (sum == 0?1:0) + dfs(root->left,sum) + dfs(root->right,sum);
}

int pathSum(struct TreeNode* root, int sum){
    if(root == NULL)    return 0;

    //先计算以当前节点为起始节点的路径中是否有该路径和
    //再判断其左子树和右子树中是否有
    return dfs(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
}





