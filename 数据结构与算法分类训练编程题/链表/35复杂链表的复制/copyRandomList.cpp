#include <iostream>
#include <unordered_map>

using namespace std;

/*
请实现 copyRandomList 函数，复制一个复杂链表。
在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，
还有一个 random 指针指向链表中的任意节点或者 null。

*/

/*
思路：
1.哈希+迭代
2.bfs：队列
3.dfs
4.拷贝每个节点到当前节点后面，最后父子链表分离
*/

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


//迭代+哈希
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)    return nullptr;

        unordered_map<Node*,Node*> map;//创建哈希表

        for(Node *p = head;p != nullptr;p = p->next)
        {
            map[p] = new Node(p->val); //一一对应复制节点
        }
        for(Node *p = head;p != nullptr;p = p->next)
        {
            if(p->next) map[p]->next = map[p->next];
            if(p->random)   map[p]->random = map[p->random]; //连接节点
        }
        return map[head];       
    }
};


//复制与分离，画图就明白了
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;

        //1.拷贝新节点到原节点后面
        Node *cur = head;
        while(cur)
        {
            Node *copyNode = new Node(cur->val);
            copyNode->next = cur->next;
            cur->next = copyNode;
            cur = cur->next->next;
        }
        //2.复制节点的随机指针
        cur = head;
        while(cur)
        {
            if(cur->random != nullptr)
            {
                cur->next->random = cur->random->next;//复制节点的random = 当前节点的random指向节点的下一个节点
            }

            cur = cur->next->next;
        }
        //3.拆分链表
        Node *copyHead = head->next;        
        Node *curCopy = head->next; //指向复制节点
        cur = head;
        while(cur)
        {
            cur->next = cur->next->next;
            cur = cur->next;
            if(curCopy->next != nullptr)
            {
                curCopy->next = curCopy->next->next;
                curCopy = curCopy->next;
            }
        }
        return copyHead;
    }
};


