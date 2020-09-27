/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.

说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？
*/

struct ListNode {
     int val;
     struct ListNode *next;
 };

//快慢指针，快指针先走n步，然后和慢指针一起走，直到快指针为空，此时慢指针指向的就是倒数第k个节点
//需要注意一些特例，例如只有一个节点的情况
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){

    if(head  == NULL || n < 0)   return NULL;
    if(head->next == NULL && n == 1)
    {
        //free(head);
        return NULL; //只有一个节点，并且要删除的也是这个，直接返回NULL
    }

    struct ListNode *fast = head;
    struct ListNode *slow = head;
    struct ListNode *pre;

    for(int i=0;i<n;i++)
        fast = fast->next; //快指针先走n步

    if(fast == NULL)    return head->next; //如果快指针走了n步直接空了，例如[1,2],n=2的情况，此时要删除头，所以直接返回头节点下一个

    while(fast != NULL)
    {      
        pre = slow;
        fast = fast->next;
        slow = slow->next;
    }

    pre->next = slow->next;
    //free(slow);
    return head;
}