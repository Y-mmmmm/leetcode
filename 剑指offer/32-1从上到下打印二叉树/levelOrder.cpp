#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {

        vector<int> res; //创建容器数组
        if(!root)
            return res;

        queue<TreeNode*> q; //创建队列

        q.push(root); //根节点push

        while(q.size()){
            TreeNode* node=q.front(); //node指针指向队列头          
            q.pop(); //pop

            res.push_back(node->val); //将队列头数据存入res尾部

            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }

        return res;
    }
};

