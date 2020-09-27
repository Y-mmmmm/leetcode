#include <iostream>
#include <vector>

using namespace std;

/*
给定一个 N 叉树，返回其节点值的前序遍历。

例如：3叉树

        1
     /  |  \
    3   2   4
  /   \
 5     6

返回其前序遍历: [1,3,5,6,2,4]
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
    vector<int> res;
    vector<int> preorder(Node* root) {
        if(root == nullptr) return res;
        res.push_back(root->val);

        for(auto i:root->children)
            preorder(i);

        return res;       
    }
};


