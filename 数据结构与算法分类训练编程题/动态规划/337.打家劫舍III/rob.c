/*
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。

计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。

示例 1:

输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

输出: 7 
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.

示例 2:

输入: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.

*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };
 
/*
主要在于普通递归计算量太大，需要优化，参考C++的
*/

//4 个孙子偷的钱 + 爷爷的钱 VS 两个儿子偷的钱 哪个组合钱多，就当做当前节点能偷的最大钱数。
int rob(struct TreeNode* root){

    if(root == NULL)    return 0;

    int money = root->val;

    if(root->left != NULL)
        money += rob(root->left->left) +rob(root->left->right);

    if(root->right != NULL)
        money += rob(root->right->left)+ rob(root->right->right);
    
    //当前节点不偷：rob(root->left) + rob(root->right)
    //当前节点偷：money
    return fmax(money,rob(root->left) + rob(root->right));
}

//优化，自底向上

typedef struct TreeNodeStatus
{
    int gorob;
    int notrob;
}RobStatus_t;

RobStatus_t dfs(struct TreeNode *root)
{
    if(root == NULL)    return (RobStatus_t){0,0};

    RobStatus_t res;

    RobStatus_t left = dfs(root->left);
    RobStatus_t right = dfs(root->right);

    res.gorob = root->val + left.notrob + right.notrob;

    res.notrob = fmax(left.gorob,left.notrob) + fmax(right.gorob,right.notrob);

    return res;
   
}

int rob(struct TreeNode* root){
    
    RobStatus_t rootStatus = dfs(root);
    return fmax(rootStatus.gorob,rootStatus.notrob);
}


//优化 官方的答案
struct SubtreeStatus {
    int selected;
    int notSelected;
};

struct SubtreeStatus dfs(struct TreeNode *root) {
    if (!root) {
        return (struct SubtreeStatus){0, 0};
    }
    struct SubtreeStatus l = dfs(root->left);
    struct SubtreeStatus r = dfs(root->right);

    int selected = root->val + l.notSelected + r.notSelected;
    int notSelected = fmax(l.selected, l.notSelected) + fmax(r.selected, r.notSelected);

    return (struct SubtreeStatus){selected, notSelected};
}

int rob(struct TreeNode *root) {
    struct SubtreeStatus rootStatus = dfs(root);
    return fmax(rootStatus.selected, rootStatus.notSelected);
}
