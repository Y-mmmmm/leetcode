#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};



struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    //空数组返回空指针，表示空树
    if(preorderSize == 0) 
        return NULL;

    int left_end,right_begin;    
    int num = preorderSize;//标记先序数组第一个元素在中序数组位置

    struct TreeNode* node =(struct TreeNode *)malloc(sizeof(struct TreeNode));

    node->val = preorder[0];

    //匹配preorder[0]在inorder的下标
    while(num--)
    {
        if(inorder[num] == preorder[0])  //找到根节点所在的num
        break;
    } 
     
    left_end = num;     
    right_begin = left_end + 1;

    node->left = buildTree(preorder+1,left_end,inorder,left_end);

    node->right = buildTree(preorder+right_begin, preorderSize-right_begin, inorder+right_begin, inorderSize-right_begin);

    return node;
}

void BiTree_print(struct TreeNode *elem)
{
    printf("%d  ",elem->val);

}

//前序遍历
void PreOrder_Traversal(struct TreeNode *Tree)
{
    if(Tree) //树不为空
    {
        BiTree_print(Tree); //打印当前节点值
        PreOrder_Traversal(Tree->left); //先访问该节点的左孩子
        PreOrder_Traversal(Tree->right); //再访问该节点的右孩子
    }
    return; //注意，这里因为是递归，所以遇到节点空就会返回上一级递归。
}


void main()
{
    int preorder[] = {3,9,20,15,7};
    int inorder[] = {9,3,15,20,7};

    struct TreeNode *tree = buildTree(preorder,5,inorder,5);

    PreOrder_Traversal(tree);
    


}

