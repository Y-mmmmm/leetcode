#include <stdio.h>

struct TreeNode 
{
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
    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }

    int **res = (int *)calloc(MAXLEN,sizeof(int *)); 
    *returnColumnSizes = (int *)calloc(MAXLEN,sizeof(int *));//存储二维数组每层的长度

    struct TreeNode **queue = (struct TreeNode **)calloc(MAXLEN,sizeof(struct TreeNode *));//存储树的指针；只有二级指针才能存指针，一级指针只能存类型值
    int head = 0;
    int tail = 0;
    queue[tail++] = root;

    struct TreeNode *tmp;
    int len = 0; //二维数组的长度
    int levelNodeNum = 0;//每层节点的数量，也就是每层的长度
    while(head != tail)
    {
        levelNodeNum = (tail - head)%MAXLEN; //根据队列大小计算出每层节点个数
        returnColumnSizes[0][len] = levelNodeNum;
        res[len] = (int *)calloc(levelNodeNum,sizeof(int));//根据每层节点长度分配空间

        //根据每层节点个数，一口气处理完
        for(int i=0;i<levelNodeNum;i++)
        {
            tmp = queue[head++];
            res[len][i] = tmp->val;

            if(tmp->left != NULL)  queue[tail++] = tmp->left;
            if(tmp->right != NULL)  queue[tail++] = tmp->right;
        }
        len++;    
    }

    *returnSize = len;

    return res;

}