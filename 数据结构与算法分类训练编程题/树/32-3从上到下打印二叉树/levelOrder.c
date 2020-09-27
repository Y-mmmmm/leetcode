#include <stdio.h>
#include <stdlib.h>

/*
请实现一个函数按照之字形顺序打印二叉树，
即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，
第三行再按照从左到右的顺序打印，其他行以此类推。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

返回其层次遍历结果：

[
  [3],
  [20,9],
  [15,7]
]
*/

/*
思路：
1.双端队列

利用双端队列的两端皆可添加元素的特性，设打印列表（双端队列） tmp ，并规定：

    奇数层 则添加至 tmp 尾部 ，
    偶数层 则添加至 tmp 头部 。

2.双栈
偶数层保存在栈2，奇数层保存在栈1，根据奇偶pop与保存

3.单队列，但是打印方向根据奇偶层判断
*/


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAXLEN  1100

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
        *returnSize = 0;
    if(root == NULL)    return NULL;

    struct TreeNode **queue = (struct TreeNode **)calloc(MAXLEN,sizeof(struct TreeNode *));
    int head = 0;
    int tail = 0;

    *returnColumnSizes = (int *)calloc(MAXLEN,sizeof(int *));
    int **ret = (int **)calloc(MAXLEN,sizeof(int *));

    int len = 0;
    int k;

    struct TreeNode *tmp = root;
    queue[tail++] = root;

    while(head != tail)
    {
        int size = (tail - head + MAXLEN)%MAXLEN;
        ret[len] = (int *)calloc(size,sizeof(int));
        returnColumnSizes[0][len] = size;

        for(int i=0;i<size;i++)
        {
            tmp = queue[head++];
            k = (len%2 == 0) ? i:(size-1 - i ); //控制打印方向
            ret[len][k] = tmp->val;

            if(tmp->left != NULL)   queue[tail++] = tmp->left;
            if(tmp->right != NULL)  queue[tail++] = tmp->right;
        }
        len++;
    }
    *returnSize = len;
    //free(queue);
    return ret;
}


