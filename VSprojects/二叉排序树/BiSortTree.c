#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*
二叉排序树、二叉搜索树、二叉查找树：left < root < right

*/


typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode_t;


/**
*   T 指向二叉数链表
*   target 要查找的值
*   f 指向 T 的根节点（双亲），初始调用此函数时传参 NULL
*   p 为遍历指针，查找到时 p 指向该节点
*/
bool Search(TreeNode_t *T ,int target ,TreeNode_t *f ,TreeNode_t **p)
{
    if(T == NULL)
    {
        *p = f; //遍历到叶子节点时，保存其父节点
        return false;
    }
    else if(target == T->val)
    {
        *p = T; //找到该节点时，保存该节点地址，方便后面使用
        return true;
    }
    else if(target < T->val)
    {
        return Search(T->left,target,T,p); //去左子节点找
    }
    else
    {
        return Search(T->right,target,T,p);//去右子节点找
    }
    
}


bool Insert(TreeNode_t **T,int insert_val)
{
    TreeNode_t *p;
    TreeNode_t *s;

    if(!Search(*T,insert_val,NULL,&p))
    {
        s = (TreeNode_t *)malloc(sizeof(TreeNode_t));
        s->val = insert_val;
        s->left = NULL;
        s->right = NULL;

        if(p == NULL)
        {
            *T = s; /*父节点空，直接插入 s 为新的根节点*/
        }     
        else if(insert_val < p->val)
        {
            p->left = s;
        }
        else
        {
            p->right = s;
        }
        return true;
            
    }
    else
    {
        return false; //树中有要插入的节点值，直接返回
    }   

}

//删除某个节点，然后重连二叉树 [搞不懂就画图，画图就明白了]
bool Delete(TreeNode_t **p)
{
    TreeNode_t *q;
    TreeNode_t *s;

    if((*p)->right == NULL) //右子树空，重接左子树，子承父业
    {
        q = *p;
        *p = (*p)->left;
        free(q);
    }
    else if((*p)->left == NULL) //左子树空，重接右子树
    {
        q = *p;
        *p = (*p)->right;
        free(q);
    }
    else //左右都不为空
    {
        //考虑谁来做爹，因为 左节点 < 根 < 右节点 ，删除的节点是当前根的话，显然去 左子树 中找 最右边节点 替换 根，符合原结构
        q = *p;
        s = (*p)->left;

        while(s->right) //去左子树中找到最右边的节点作为替换节点
        {
            q = s;        //q指向替换节点的父节点
            s = s->right; //s指向替换节点
        }
        (*p)->val = s->val; //直接将替换节点的值给待删除节点，完成覆盖

        if(q != *p) //该替换节点的父节点不是待删除节点
            q->right = s->left; //因为s已经是最右边节点，它只能有左节点，将它的左节点接到它的父节点上
        else
            q->left = s->right;

        free(s); //删除这个替换节点即可
        
    }
    return true;
}


bool Delete_Node(TreeNode_t **T,int del_data)
{
    if(*T == NULL)  return false;

    if(del_data == (*T)->val)
        return Delete(T);
    else if(del_data < (*T)->val)
        return Delete_Node(&(*T)->left,del_data);
    else
        return Delete_Node(&(*T)->right,del_data);
    
}

//中序遍历 左 根 右
void Inorder_Traversal(TreeNode_t *T)
{
    if(T)
    {
        Inorder_Traversal(T->left);
        printf("%d ",T->val);
        Inorder_Traversal(T->right);
    }
    return;
}


void main()
{
    int i;
    int a[10] = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};
    TreeNode_t *T = NULL;
    for(i=0;i<10;i++)
    {
        Insert(&T,a[i]);
    }
    Inorder_Traversal(T);

    Delete_Node(&T,88);
    printf("\n");
    Inorder_Traversal(T);
}


