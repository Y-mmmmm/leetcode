#include <iostream>
#include <vector>

using namespace std;

/*
给定一个 N 叉树，返回其节点值的后序遍历。

例如：3叉树

        1
     /  |  \
    3   2   4
  /   \
 5     6

返回其后序遍历: [5,6,3,2,4,1].
*/

/*
流程详解：
首先使用for循环遍历根节点的孩子们，先找到节点3，再递归节点3的孩子，找到节点5，再递归节点5的孩子，因为节点5的孩子都为空，所以关于节点5的孩子递归循环结束
将节点5存储；然后返回节点3，再接着节点3的孩子递归循环找到节点6，节点6的子节点也都为空，循环结束将节点3存储，然后返回节点1，再接着节点1的孩子递归循环找到节点2，
存储节点2，找到节点4，存储节点4，最后节点1的递归循环结束，存储1，结束

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
    vector<int> postorder(Node* root) {
        if(root == nullptr) return  res;

        for(auto i:root->children) //二叉树是遍历左子树、右子树；相应的这里就要改成遍历每个孩子，使用循环
            postorder(i);  

        res.push_back(root->val); //存入当前节点，等效于后序遍历中的printf

        return res;        
    }
};


