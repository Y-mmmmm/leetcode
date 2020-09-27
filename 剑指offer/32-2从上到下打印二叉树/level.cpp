

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

 
class Solution {
public:
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;        
    
        if(root == nullptr) return res;

        queue<TreeNode*>  que;
        que.push(root);

        while(!que.empty())
        {
            vector<int> path; //在这创建
            int size = que.size();//必须先读取大小，否则循环中会改变
            for(int i=0;i<size;i++)
            {
                TreeNode *cur = que.front();
                que.pop();
                path.push_back(cur->val);

                if(cur->left != nullptr)    que.push(cur->left);
                if(cur->right!=nullptr)     que.push(cur->right);
            }
            res.push_back(path);
        }

        return res;

    }
};