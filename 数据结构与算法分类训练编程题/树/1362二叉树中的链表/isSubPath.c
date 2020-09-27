#include <stdio.h>
#include <stdbool.h>


/*
给你一棵以 root 为根的二叉树和一个 head 为第一个节点的链表。

如果在二叉树中，存在一条一直向下的路径，且每个点的数值恰好一一对应以 head 为首的链表中每个节点的值，
那么请你返回 True ，否则返回 False 。

一直向下的路径的意思是：从树中某个节点开始，一直连续向下的路径。

*/


/*
思路：递归  本题的思路与二叉树的子树/二叉树的镜像类似，但递归的细节判定有区别
    1.找到根节点
    2.判断子结构


    1.遍历树节点，确定哪个节点是链表的头节点
    2.如果 树 的当前节点值与 链表 的头节点值相同，调用 recur 函数判断子结构是否也相同；
    3.如果不同，就递归调用主函数来寻找 树 的哪个节点与 链表 的头节点匹配。

    注意：链表的判定条件没有树那么严格，因为树有左右，链表无所谓

*/

struct ListNode {
    int val;
    struct ListNode *next;
};

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };
 

bool recur(struct ListNode* head, struct TreeNode* root)
{
    if(head == NULL)    return true; //链表遍历完，返回true
    if(root == NULL)    return false;//树先结束，返回false

    //注意后面head->next 和 root的左右比较，采用的是 || ，因为链表无所谓左右
    return (head->val == root->val)&&(recur(head->next,root->left)||recur(head->next,root->right));
}

bool isSubPath(struct ListNode* head, struct TreeNode* root){

    return (head != NULL && root != NULL)&&(recur(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right));
}