#include <stdio.h>



struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


//就是将节点值在[L,R]之间的都加起来，和左叶子之和那道题类似

int rangeSumBST(struct TreeNode* root, int L, int R){

    if(root == NULL)    return 0;

    int sum = 0;
    if(root->val >= L && root->val <= R)
        sum += root->val;

    return sum + rangeSumBST(root->left,L,R) + rangeSumBST(root->right,L,R);
}

/*
int rangeSumBST(struct TreeNode* root, int L, int R){

    if(root == NULL)    return 0;

    int sum = 0;
    if(root->val >= L && root->val <= R)
        return  root->val+ rangeSumBST(root->left,L,R) + rangeSumBST(root->right,L,R);
    else if(root->val < L) //去右子树找
        return rangeSumBST(root->right,L,R);
    else  //去左子树找
        return rangeSumBST(root->left,L,R);
}
*/