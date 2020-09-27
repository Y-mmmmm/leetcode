#include <iostream>

using namespace std;


/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
*/

/*
二叉搜索树的特点：left < root < right
因此采用中序遍历：左 中 右
*/

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node *pre,*head;//全局指针
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) return nullptr;
        //中序遍历构成链表
        inorder(root);
        //构成循环链表
        head->left = pre;
        pre->right = head;

        return head;     
    }
    void inorder(Node* cur)
    {
        if(cur == NULL) return;//递归出口
        inorder(cur->left); //遍历左节点
    
        if(pre == nullptr)  
            head = cur;   //找到最左下角节点即为头  
        else
            pre->right = cur;
                           
        cur->left = pre; //构成双向链表
        pre = cur; //记录pre节点，pre节点总是在cur节点之前

        inorder(cur->right);//遍历右节点

    }
};

