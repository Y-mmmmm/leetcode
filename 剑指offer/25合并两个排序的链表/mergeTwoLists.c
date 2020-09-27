#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>



struct ListNode 
{
    int val;
    struct ListNode *next;
};
 


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    struct ListNode head;//注意不能使用malloc，否则无法free
    head.val = 0;
    head.next = NULL;

    struct ListNode *cur = &head;

    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val < l2->val)
        {
            cur->next = l1;
            l1 = l1->next;
        }
        else
        {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = (l1 == NULL ? l2 : l1);
    return head.next;
}





