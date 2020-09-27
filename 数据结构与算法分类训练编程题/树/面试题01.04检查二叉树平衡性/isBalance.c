#include <stdio.h>

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//还是双递归


//方法1 先序遍历 自顶向下
int depth(struct TreeNode* root)
{
    if(root == NULL)    return 0;//当前节点为空或者越过叶子节点了

    return 1 + fmax(depth(root->left),depth(root->right));//否则取当前节点的左右子树最大深度
}

bool isBalanced(struct TreeNode* root){
    if(root == NULL) return true; //节点空或者越过叶子节点，true

    int left = depth(root->left);
    int right = depth(root->right);//获得当前左右子树的深度

    int bf = abs(left-right);//计算平衡因子

    //先判断当前节点为起始节点的树的平衡性，再判断其左子树和右子树的平衡性
    return (bf <= 1) && isBalanced(root->left) && isBalanced(root->right);

}

//方法2 自底向上
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


