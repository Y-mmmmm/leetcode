#include <stdio.h>

/*
检查子树。你有两棵非常大的二叉树：T1，有几万个节点；T2，有几万个节点。设计一个算法，判断 T2 是否为 T1 的子树。
如果 T1 有这么一个节点 n，其子树与 T2 一模一样，则 T2 为 T1 的子树，也就是说，从节点 n 处把树砍断，得到的树与 T2 完全相同。

示例1:
 输入：t1 = [1, 2, 3], t2 = [2]
 输出：true

示例2:
 输入：t1 = [1, null, 2, 4], t2 = [3, 2]
 输出：false
*/




struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


/*
类似题 1367.二叉树中的列表
https://leetcode-cn.com/problems/linked-list-in-binary-tree/
*/

//双递归

bool dfs(struct TreeNode* t1, struct TreeNode* t2)
{
    if(t1 == NULL && t2 == NULL)    return true; //树的检查条件比链表的更严格，只有同时空，才符合
    if(t1 == NULL || t2 == NULL)    return false;//只有有一个先空了，则不符合子树的条件

    //如果值不等，也不符合;值相等表示当前节点符合，继续判断该节点下的左子树和右子树
    return (t1->val == t2->val) && dfs(t1->left,t2->left)&&dfs(t1->right,t2->right);

}

bool checkSubTree(struct TreeNode* t1, struct TreeNode* t2){

    //只要有一个为空，就不符合子树的条件
    //先判断当前节点是否可以作为子树的根节点
    //若当前节点不符合，则继续在t1的左子树或者右子树中查找子树的起始根节点
    return (t1 !=NULL && t2 != NULL)&&(dfs(t1,t2) || checkSubTree(t1->left,t2)||checkSubTree(t1->right,t2));

}
