/*
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]

进阶: 递归算法很简单，你可以通过迭代算法完成吗？

*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/* 
中序遍历：left -> root -> right；需要辅助栈
*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode *>node_stack;//辅助栈

        while(root != nullptr || !node_stack.empty())
        {
            if(root != nullptr) //左子树不为空，一直走到尽头，沿途暂存走过的节点值
            {
                node_stack.push(root); //暂存节点
                root = root->left;
            }
            else //左子树空了，开始准备访问右子树
            {
                root = node_stack.top();  //取出栈中的节点值
                res.push_back(root->val); //这就是根
                node_stack.pop();  //完了抛弃
                root = root->right; //去右子树找
            }
        }

        return res;
        
    }
};


