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