
/*
给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

*/

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


/*
使用二叉树的层序遍历，在每层最后一个节点时将该节点next指针指向NULL，其他都指向队列头即可
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *>que;

        if(root == nullptr) return root;

        que.push(root);

        while(!que.empty())
        {
            int n = que.size();

            for(int i=0;i<n;i++)
            {
                Node *cur = que.front();
                que.pop();
                if(i == n-1)    
                    cur->next = NULL;
                else
                    cur->next = que.front();

                if(cur->left)   que.push(cur->left);
                if(cur->right)  que.push(cur->right);
            }
            
        }
        return root;       
    }
};

