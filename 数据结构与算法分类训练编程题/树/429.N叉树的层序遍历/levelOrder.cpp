#include <iostream>
#include <vector>

using namespace std;

/*
给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。


例如：3叉树

        1
     /  |  \
    3   2   4
  /   \
 5     6

返回其层序遍历:

[
    [1],
    [3,2,4],
    [5,6]
]

*/



class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    
    vector<vector<int>> levelOrder(Node* root) 
    {       
        vector<vector<int>> res;
       
        if(root == nullptr)    return res;

        queue<Node *> q;
        q.push(root);

        while(!q.empty())
        {
            vector<int> path;
            int size = q.size();//一定要先计算，否则循环中队列大小会改变

            for(int i=0;i<size;i++)
            {
                Node *tmp = q.front();
                q.pop();
                path.push_back(tmp->val);

                for(auto child:tmp->children)
                        q.push(child); //循环添加子节点

            }
            res.push_back(path);
        }
        return res;
    }
};


