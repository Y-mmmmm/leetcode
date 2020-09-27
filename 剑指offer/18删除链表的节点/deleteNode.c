#include <stdio.h>
#include <stdlib.h>

//不用自己释放

struct ListNode {
      int val;
      struct ListNode *next;
  };
 


struct ListNode* deleteNode(struct ListNode* head, int val){
    
    if(head == NULL)
        return NULL;
    if(head->val == val)
        return head->next;
        
    struct ListNode *prev = head;
    while(prev->next != NULL && prev->next->val != val)
    {
        prev = prev->next;
    }

    if(prev->next != NULL)
    {
        prev->next = prev->next->next;
    }

    return head;
}


//linus大佬解法
/*

+------+         +------+         +------+
| head |         |node2 |         |node3 |
+--+---+         +--+---+         +--+---+
   |                    
   v                      
+--+---+         +--+---+         +--+---+      ......
| val  |         | val  |         | val  |
+------+         +------+         +------+
| next + ---->   | next + ---->   | next |
+------+         +------+         +------+

indirect要么指向head, 要么指向nodex->next这个存储区域，当发现节点需要删除时，比如要删除node2

执行*indirect = (*indirect)->next;，head->next中的值改为node3（node3为第三个节点的地址），即head->next等于node3 这样就删除了node2。

关键在于indirect直接引用了head或nodex->next这些存储区域，而不是用struct ListNode* curr = curr->next;这样复制链表指针

*/

struct ListNode* deleteNode(struct ListNode* head, int val)
{
    struct ListNode** indirect = &head; 

    //struct ListNode* temp;

    for(; *indirect; indirect = &((*indirect)->next))
   {
        if((*indirect)->val == val)
       {
            //temp = *indirect;
            *indirect = (*indirect)->next;
            //free(temp);
            break;
        }
    }
    return head;
}

