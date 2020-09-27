#include <stdio.h>
#include <stdlib.h>


/*
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

返回：

[3,9,20,15,7]

节点总数 <= 1000
*/

/*
思路：二叉树的层序遍历，又叫广度优先遍历BFS
利用队列，队列空说明遍历完了

1.先将根节点放入队列，然后pop队首元素，将其数值存入数组
2.然后判断当前节点是否有左右节点，有则push进队列
3.循环pop读取队首，也就是先读左节点，将其值存入数组，然后判断其子节点，将其子节点push
4.然后pop读取右节点，将其值存入数组，然后判断其子节点，将其子节点push


例如：先将根节点3放进队列，tail++，然后循环中pop读取队首3，head++，先将其值3存入数组，然后判断它有左右节点9和20，
将它俩存入队列tail++，下一次循环时，先pop 9，判断它没有子节点，下一轮pop 20，有左右子节点，则将15，7存入。。。
最后队列为空时，说明遍历完了

*/

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* levelOrder(struct TreeNode* root, int* returnSize){
    
    *returnSize = 0;
    if(root == NULL)    return NULL;

    //注意此处，开辟的是存储树结构的空间，所以要转换为数结构体指针，又由于每个节点存的是树的地址，所以是二级指针
    //等效于指针数组 *queue[1100]
    struct TreeNode **queue = (struct TreeNode **)malloc(1010*sizeof(struct TreeNode *));

    int *ret = (int *)malloc(1010*sizeof(int));
    int head = 0;
    int tail = 0;
    int size = 0;

    struct TreeNode *tmp = root; //定义指针指向树

    queue[tail++] = tmp;//将头节点push

    while(head != tail)
    {
        tmp = queue[head++]; //pop头节点
        ret[size++] = tmp->val; //先存储值

        //再分别判断左右节点，有则存入
        if(tmp->left != NULL)
        {
            queue[tail++] = tmp->left;
        }
        if(tmp->right != NULL)
        {
            queue[tail++] = tmp->right;
        }

    }
    *returnSize = size;

    return ret;
}



//--------------------------------------------

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct queue{
    struct TreeNode *data[1009];
    int head;
    int tail;
}QUEUE,*PQUEUE;
int *levelOrder(struct TreeNode *root, int *returnSize)
{
    //判断树是否为空
    if (!root)
    {
        *returnSize = 0;
        return NULL;
    }
    //将根节点入队
    QUEUE q;
    q.head = 0;
    q.tail = 1;
    q.data[0] = root;
    int count = -1;
    int *result = (int *)malloc(sizeof(int)*1009);
    while (q.head != q.tail)
    {
        if (q.data[q.head]->left)
        {
            q.data[q.tail++] = q.data[q.head]->left;
        }
        if (q.data[q.head]->right)
        {
            q.data[q.tail++] = q.data[q.head]->right;
        }
        //出队
        count++;
        result=(int *)realloc(result, sizeof(int) * (count + 1));
        result[count] = q.data[q.head]->val;
        q.head++;
    }
    *returnSize = count + 1;
    return result;
}

