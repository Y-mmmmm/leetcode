#include <stdio.h>
#include <stdlib.h>

/*
请完成一个函数，输入一个二叉树，该函数输出它的镜像。

例如输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

示例 1：
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]

限制：
0 <= 节点个数 <= 1000

*/


/*
思路：
1.辅助栈
    先将节点顺序压栈
    然后交换左右节点顺序

2.递归
*/


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };
 

//辅助栈法
struct TreeNode* mirrorTree(struct TreeNode* root){

    if(root == NULL)    return NULL;

    struct TreeNode **stack = (struct TreeNode **)calloc(1000,sizeof(struct TreeNode));
    int head = 0;
    int tail = 0;

    struct TreeNode *node = root;
    stack[tail++] = node; //root push

    while(head != tail)
    {
        node = stack[--tail]; //pop  --tail

        //push
        if(node->left != NULL)   stack[tail++] = node->left;
        if(node->right != NULL)  stack[tail++] = node->right;

        //交换当前的左右节点
        struct TreeNode *tmp = node->left;
        node->left = node->right;
        node->right = tmp;       
    }

    free(stack); //以后要注意，用完了最好free开辟的内存

    return root;
}

//--------------------------------------------------------

//递归法
struct TreeNode* mirrorTree(struct TreeNode* root){
    if(root == NULL)    return NULL;  //递归结束条件

    //递归交换左右节点
    struct TreeNode *leftroot = mirrorTree(root->right); 
    struct TreeNode *rightroot = mirrorTree(root->left);

    root->left = leftroot;
    root->right = rightroot;

    return root;
}

