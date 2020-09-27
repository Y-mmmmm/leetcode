



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
//使用一个二维数据记录偷或不偷的最大值
//定义一个数组res,长度为2,res[0]表示不抢该节点可获得最大值,res[1]表示抢劫该节点可获得最大值
//myrob意为：在以r为根节点的树中,返回抢劫根节点与不抢劫根节点可获得的最大值

class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = myrob(root);
        return max(res[0], res[1]);
    }
private:
    vector<int> myrob(TreeNode* root) {
        if(root == NULL) return vector<int> (2,0);

        vector<int> res(2);
        vector<int> left = myrob(root->left);
        vector<int> right = myrob(root->right);

        res[0] = max(left[0],left[1]) + max(right[0],right[1]);//当前节点不偷，取左右孩子偷或不偷的最大值之和
        res[1] = root->val + left[0] + right[0];//当前节点偷，返回左右孩子不偷的最大值之和+当前节点值
        return res;
    }
};