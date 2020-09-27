#include <stdio.h>



struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*
给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。

对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。

以 10^9 + 7 为模，返回这些数字之和。

输入：[1,0,1,0,1,0,1]
输出：22
解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

*/

/*
和记录二叉树所有路径类似：
    1.如何计算一条路径的十进制数：每深入一层，结果*2即可，模2
    2.什么时候累加一条路径和：到达叶子节点
    3.路径回溯时，如何去除和暂存中间结果：使用值传递方式
*/




//tmp用于暂存运算结果，使用值传递，因此递归返回时还是进入之前的值，就不用考虑路径回溯的问题
void preOrder(struct TreeNode* root,int *sum,int tmp)
{
    if(root == NULL)    return;
    tmp = tmp*2 + root->val;//根节点为高位，因此每递归一层 *2即可

    if(root->left == NULL && root->right == NULL)
        *sum += tmp;//到达叶子节点才累加和

    preOrder(root->left,sum,tmp);
    preOrder(root->right,sum,tmp);
    
}

int sumRootToLeaf(struct TreeNode* root){
    if(root == NULL)    return 0;
    int sum = 0;
    preOrder(root,&sum,0);

    return sum%(1000000007);
}

