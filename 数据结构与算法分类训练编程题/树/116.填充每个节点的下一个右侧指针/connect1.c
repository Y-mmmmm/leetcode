


struct Node {
    int val;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

/*
思路：
每个node左子树的next = node右子树
每个node右子树的next = node->next的左子树 (看图，node指向的是当前父节点，那么node->next就已经指向了右子树，再操作子树)

node->left->next = node->right;
node->left->right = node->next->left;

*/

void dfs(struct Node* root,struct Node* next)
{
    if(root == NULL)    return;

    root->next = next;

    dfs(root->left,root->right);

    dfs(root->right,(root->next != NULL ? root->next->left : NULL));

}

struct Node* connect(struct Node* root) {
    if(root == NULL)    return NULL;
    dfs(root,NULL);

    return root;	
}

