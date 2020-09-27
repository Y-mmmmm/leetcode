#include <stdio.h>


/*
给定一棵二叉搜索树，请找出其中第k大的节点。
*/


/*
思路：二叉排序树的性质 left < root < right 因此其中序遍历就是一个升序的排序数组
    那么中序遍历的倒序就是 right -> root ->left ，是一个降序的数组，采用倒序方式遍历到第K个节点就停止，
    后面没必要遍历了；

    方法1.中序遍历的倒序 -- 最优
    方法2.中序遍历时将树的节点全部加入数组，使用变量统计数组的长度，最后输出len-k元素
    方法3.使用队列，中序遍历将节点放入队列，再pop出第k个节点

*/



struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void InOrder(struct TreeNode* root,int *n,int *res)
{
    if(root->right != NULL && *n>0)  InOrder(root->right,n,res); //修改的中序遍历的倒序，增加对k的计数判断
       
    (*n)--;
    if(*n == 0)
    {
        *res = root->val;
        return;
    }
    if(root->left != NULL && *n>0)   InOrder(root->left,n,res);
      
}


int kthLargest(struct TreeNode* root, int k){
    int cnt = k;
    int ret = 0;
    InOrder(root,&cnt,&ret);

    return ret;
}




