#include <stdio.h>

/*
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。


示例 1：

输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：

输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：

输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。

进阶：
你是否可以不用额外空间解决此题？
*/


/*
思路：快慢指针
1.快指针走两步
2.慢指针走一步
3.当快慢指针在环中相遇时，让查询指针从头开始和慢指针一起走，直到两个值相等就是入口节点


*/


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL)  return NULL;

    struct ListNode *slow = head; //慢指针
    struct ListNode *fast = head; //快指针
    struct ListNode *finder = head;//查询入口节点指针

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            while(finder->val != slow->val) //注意以值判定入口
            {
                finder = finder->next;//这里可以先将fast指针重新指向head代替finder节省空间，本题这么做是为了代码清晰
                slow = slow->next;
            }
            return slow;            
        }
    }
    return NULL;
    
}


