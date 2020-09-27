/*
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL

示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
*/


struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head == NULL)    return NULL;
    if(head->next == NULL)  return head;

    struct ListNode *tail;
    struct ListNode *cur = head;
    int len = 0;

    //找到尾节点
    while(cur)
    {
        len++;
        tail = cur;
        cur = cur->next;
    }
    struct ListNode *tmp = tail;

    tail->next = head; //构成环形链表

    //计算从尾节点开始走的长度
    int n = len-(k%len);//如何计算这个很重要

    //移动到新尾节点
    for(int i=0;i<n;i++)
    {
        tmp = tmp->next;
    }
    cur = tmp->next;//保存新头

    tmp->next = NULL;//断开

    return cur;
}