#include <iostream>
#include <string>
#include <vector>
#include <stack>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
   // ListNode(int x) : val(x), next(NULL) {}
};

//辅助栈法
//时间复杂度O(N)
//空间复杂度O(N)
class Solution1 {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> a;
        vector<int> b;
        
        while(head)
        {
            a.push(head->val);
            head=head->next;
        }
        while(!a.empty())
        {
            b.push_back(a.top());
            a.pop();
        }
        return b;
    }
};

//递归法
class Solution2 {
public:
    vector<int> reversePrint(ListNode* head) {
        if(!head)
            return {};
        vector<int> a=reversePrint(head->next);
        a.push_back(head->val);
        return a;
    }
};


