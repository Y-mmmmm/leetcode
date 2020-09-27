#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



typedef struct TreeNode{
    int val;
    int BF;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode_t;


void R_Rotate(TreeNode_t **p)
{
    TreeNode_t *L = (*p)->left; // L 指向 p 的 左节点

    (*p)->left = L->right;      // L 的 右节点 接到 p 的左节点
    L->right = (*p);            // p 变成 L 的右节点

    *p = L;                     // p 指向新的根节点 = L变成了根节点
}

void L_Rotate(TreeNode_t **p)
{
    TreeNode_t *R = (*p)->right;// R 指向 p 的 右节点

    (*p)->right = R->left;      // R 的 左节点 接到 p 的右节点
    R->left = (*p);             // p 变成 R 的左节点

    *p = R;                     // p 指向新的根节点 = R变成了根节点
}
