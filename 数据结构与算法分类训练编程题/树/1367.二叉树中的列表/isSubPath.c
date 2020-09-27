#include <stdio.h>

/*
给你一棵以 root 为根的二叉树和一个 head 为第一个节点的链表。
如果在二叉树中，存在一条一直向下的路径，且每个点的数值恰好一一对应以 head 为首的链表中每个节点的值，那么请你返回 True ，否则返回 False 。
一直向下的路径的意思是：从树中某个节点开始，一直连续向下的路径。
*/


struct ListNode 
{
    int val;
    struct ListNode *next;
};
 
struct TreeNode 
{
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};


/*
dfs(root, head) 表示是否存在一条从root节点开始，与链表相匹配的向下路径。
isSubPath(head, root)表示在以root为根节点的子树中，是否存在一条与链表匹配的向下路径。

dfs要求这条路径必须是从root开始的，而isSubPath只要求这条路径是在以root为根节点的子树中就可以了（不一定非要从root开始）。

总之双递归的思想就是：
    一个函数负责判断以当前节点为根的子树是否符合题目要求，另一个用来遍历整个树的所有结点，具体每个结点再交给第一个函数来判断。
    在这个题目里面第一个函数就是dfs，第二个函数就是isSubPath。

*/

//双递归

bool dfs(struct ListNode* head, struct TreeNode* root)
{
    if(head == NULL)    return true;//特判：链表走完了，返回true
    if(root == NULL)    return false;//特判：链表还没走完，树走完了，返回false

    if(head->val != root->val)  return false;//节点值不对，返回false

    //当前节点是的，继续往左子树或者右子树找
    return dfs(head->next,root->left) || dfs(head->next,root->right);
}


bool isSubPath(struct ListNode* head, struct TreeNode* root)
{
    if(head == NULL)    return true; //空链表或者链表走完了，符合
    if(root == NULL)    return false;//空树节点或者链表没空时树空了，不符合

    //先判断当前节点是否匹配，也就是当前节点是否可以作为匹配的起始点
    //如果当前节点不是起始点，再往左子树或者右子树找匹配的起始点
    return dfs(head,root)||isSubPath(head,root->left)||isSubPath(head,root->right);
}


