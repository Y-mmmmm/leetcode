#include <stdio.h>



struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*
给定一个二叉搜索树的根节点 root，返回树中任意两节点的差的最小值。

 

示例：

输入: root = [4,2,6,1,3,null,null]
输出: 1
解释:
注意，root是树节点对象(TreeNode object)，而不是数组。

给定的树 [4,2,6,1,3,null,null] 可表示为下图:

          4
        /   \
      2      6
     / \    
    1   3  

最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。

 

注意：

    二叉树的大小范围在 2 到 100。
    二叉树总是有效的，每个节点的值都是整数，且不重复。

*/


/*
二叉搜索树

方法1：中序遍历，使用指针记录前一个节点，然后记录最小值

方法2：中序遍历保存到数组中，然后排序后两两做差取最小值

*/

int res;
struct TreeNode* prev;

void inOrder(struct TreeNode* root)
{
    if(root == NULL)    return;
    inOrder(root->left);

    if(prev != NULL)
    {
        if(res > root->val - prev->val)
            res = root->val - prev->val;
    }    
    
    prev = root;

    inOrder(root->right);
}

int minDiffInBST(struct TreeNode* root){
    if(root == NULL)    return 0;

    res = INT_MAX;
    prev = NULL;

    inOrder(root);

    return res;
    
}

