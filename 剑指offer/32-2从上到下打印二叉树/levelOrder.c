#include <stdio.h>
#include <stdlib.h>


/*
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

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
  [9,20],
  [15,7]
]

提示：

    节点总数 <= 1000
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

/*
1.  返回一个指针数组，数组每个元素指针指向该层所有结点构成的数组
2.  *returnSize:表示返回数组的个数
3.  **returnColumnSizes是一个二维数组，但其实就用了第一层
    *returnColumnSizes指向每一层的数组，其元素对应某一层结点构成一维数组中结点的个数
*/
//----------------------------------------------------------------
#define MAXLEN  1100

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if(root == NULL)    return NULL;

    struct TreeNode **queue = (struct TreeNode **)calloc(MAXLEN,sizeof(struct TreeNode *));
    int head = 0;
    int tail = 0;

    int levelNodeSize = 0;//每层节点个数

    int **ret = (int **)calloc(MAXLEN,sizeof(int *)); //这里只是分配了存储指针的最大长度
    *returnColumnSizes = (int *)calloc(MAXLEN,sizeof(int *)); //分配存储ret长度的每层节点大小的空间

    int len = 0; //返回数组的长度
    
    struct TreeNode *tmp = root;
    queue[tail++] = tmp;//push

    while(head != tail)
    {
        levelNodeSize = (tail - head + MAXLEN)%MAXLEN; //计算每层节点的个数

        returnColumnSizes[0][len] = levelNodeSize; //存入每层节点大小

        ret[len] = (int *)calloc(levelNodeSize,sizeof(int)); //根据每层节点大小分配内存

        //逐层存放节点
        for(int i=0;i<levelNodeSize;i++)
        {
            tmp = queue[head++]; //pop
            ret[len][i] = tmp->val;

            if(tmp->left != NULL)
            {
                queue[tail++] = tmp->left;
            }
            if(tmp->right != NULL)
            {
                queue[tail++] = tmp->right;
            }

        }
        len++;
    }

    *returnSize = len;
    return ret;
}





//----------------------------------------------------------------
#define MAXSIZE  1100

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if(root == NULL)    return NULL;

    //**queue = *queue[]
    struct TreeNode **queue = (struct TreeNode **)calloc(MAXSIZE,sizeof(struct TreeNode *));
    int head = 0;
    int tail = 0;

    int **ret = (int **)calloc(MAXSIZE,sizeof(int *));
    *returnColumnSizes = (int *)calloc(MAXSIZE,sizeof(int *));
    //returnColumnSizes[0] = (int *)calloc(MAXSIZE,sizeof(int *));

    int size = 0;

    struct TreeNode *tmp = root;
    queue[tail++] = tmp; //push
    
    while(head != tail)
    {
        size = (tail - head + MAXSIZE)%MAXSIZE;//计算队列当前容量，也就是入栈的每层节点个数

        //returnSize[0] = *returnSize
        //returnColumnSizes[0][returnSize[0]]  
        (*returnColumnSizes)[*returnSize] = size; //将节点个数存入*returnColumnSizes指向的每个数组

        //ret[i][j] = *(*(ret + i) + j)
        //ret[i] = *(ret + i)
        ret[*returnSize] = (int *)calloc(size,sizeof(int));//根据每层size大小分配内存 *(ret + *returnSize) = ret[*returnSize]

        //将每层节点单独存入数组
        for(int i = 0;i<size;i++)
        {
            tmp = queue[head++];//pop
            ret[*returnSize][i] = tmp->val;

            if(tmp->left != NULL)
            {
                queue[tail++] = tmp->left;
            }
            if(tmp->right != NULL)
            {
                queue[tail++] = tmp->right;
            }
        }
        (*returnSize)++;
        
    }
    return ret;
}




//------------------------------------------


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int *nums = (int *)malloc(sizeof(int) * 10000);
    int **res = (int **)malloc(sizeof(int *) * 1000);
    returnColumnSizes[0] = (int *)malloc(sizeof(int) * 1000);
    returnSize[0] = 0;
    struct TreeNode *Queue[10000];
    int front, rear, last, cnt, n;
    front = rear = last = cnt = n = 0;
    Queue[root? rear++: rear] = root;
    last = rear;

    while (front < rear) {
        struct TreeNode *p = Queue[front++];
        ++cnt;
        nums[n++] = p->val;
        if (p->left) Queue[rear++] = p->left;
        if (p->right) Queue[rear++] = p->right;

        if (front == last) {
            last = rear;
            returnColumnSizes[0][returnSize[0]] = cnt;
            res[returnSize[0]++] = nums + n - cnt;
            cnt = 0;
        }
    }

    return res;
}


