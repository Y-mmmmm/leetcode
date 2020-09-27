#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*
输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
*/


/*
思路：1.先序遍历 + 判断深度  --自顶向下（代价比较大）
     2.后序遍历 + 剪枝  --自底向上，遇到不平衡直接返回  最优解
*/



struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//------------------------------------------------------------

//方法1

int Depth(struct TreeNode* root)
{
    if(root == NULL)    return 0;

    return 1 + fmax(Depth(root->left),Depth(root->right));
}


bool isBalanced(struct TreeNode* root){
    if(root == NULL)    return true;

    int left = Depth(root->left);//计算左子树深度
    int right = Depth(root->right);//计算右子树深度

    int bf = abs(left -right);//计算平衡因子

    //当前节点平衡因子小于2 并且左子树平衡 ，右子树也平衡就是AVL树
    return bf <= 1 && isBalanced(root->left) && isBalanced(root->right);//先左后右 = 先序遍历

}

//-----------------------------------------------------------------

//方法2
//后续遍历，以-1作为不平衡的标记
int PostOrder(struct TreeNode* root)
{
    if(root == NULL)    return 0;

    int left = PostOrder(root->left);//先遍历到最左节点
    if(left == -1)  return -1;//左节点深度=-1 就是不平衡，不平衡直接层层向上返回-1

    int right = PostOrder(root->right);//再遍历到右节点
    if(right == -1) return -1;//同理

    //深度差小于1就是平衡树，向上返回当前深度，不平衡就返回-1
    return abs(left - right) <= 1 ? (fmax(left,right)+1) : -1;
}

bool isBalanced(struct TreeNode* root){
    if(root == NULL)    return true;

    return PostOrder(root) == -1 ? false : true; //最后返回的深度不是-1就是平衡的

}

