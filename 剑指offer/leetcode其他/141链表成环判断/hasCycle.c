#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
给定一个链表，判断链表中是否有环。

*/


struct ListNode 
{
    int val;
    struct ListNode *next;
};


/*
思路：快慢指针
快慢指针同时走，快指针走两步，慢指针走一步，如果成环两个指针会相遇
*/

bool hasCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL) //head->next == NULL 表示需要考虑只有一个节点的情况
        return false;

    struct ListNode *Fast = head;
    struct ListNode *Slow = head;
    
    //注意！一定要添加Fast->next != NULL ，目的是防止快指针走两步成功，否则循环中会越界访问
    while(Fast != NULL && Fast->next != NULL) 
    {
        Fast = Fast->next->next;
        Slow = Slow->next;
        if(Fast == Slow)
        {
            return true;
        }
    }
    return false;
    
}




