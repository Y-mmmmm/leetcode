struct ListNode {
    int val;
    struct ListNode *next;
 };
 

/*
链表对折 ---画图

1.快慢指针找到中点，拆成两个链表
2.将后半部链表反转
3.合并两个链表
*/
struct ListNode *reverse(struct ListNode *head)
{
    struct ListNode *pre = head;
    struct ListNode *cur = NULL;
    struct ListNode *tmp = NULL;

    while(pre)
    {
        tmp = pre->next;
        pre->next = cur;
        cur = pre;
        pre = tmp;
    }
    return cur;
}

void reorderList(struct ListNode* head){
    if(head == NULL)    return;

    struct ListNode *fast = head;
    struct ListNode *slow = head;
    struct ListNode *mid;

    //1.快慢指针找到中点
    while(fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    mid = slow;

    //2.反转后半部链表
    struct ListNode *back = reverse(mid->next);
    mid->next = NULL;//断开，将中点指向空

    //3.合并链表
    struct ListNode *front = head;
    while(front && back)
    {
        struct ListNode *frontTmp = front->next;
        struct ListNode *backTmp = back->next;
        front->next = back;
        back->next = frontTmp;
        front = frontTmp;
        back = backTmp;
    }
}