#include <stdio.h>
#include <stdlib.h>


/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

*/

/*
思路：其实很简单，就相当于合并两个链表，只不过这里是求和，另外考虑进位
1.先建立链表的头节点，遍历两个链表
2.计算 sum = x + y + carry 和 carry = sum/10；
3.创建新节点，节点值为 sum % 10
4.注意 每次插入新节点，使用游标移动到新节点，这样下次插入就是直接插入了

*/

struct ListNode {
    int val;
    struct ListNode *next;
 };


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL)  return l2;
    if(l2 == NULL)  return l1;

    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;

    //创建头节点
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 0;
    head->next = NULL;

    //游标指向链表
    struct ListNode *cur = head;

    int carry = 0;
    int sum = 0;

    while(p1 != NULL || p2 != NULL) //注意！ 这里使用 || 目的是某个节点结束了继续进行本操作，而不用跳出循环重新解决剩下的
    {
        int x = p1 != NULL ? p1->val:0;
        int y = p2 != NULL ? p2->val:0;//防止某个节点先为空，所以提前预判

        sum = x + y + carry; //加法器
        carry = sum/10; //进位计算

        //创建新节点
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));  
        node->val = sum%10; //求余！！
        node->next = NULL;
        cur->next = node;
        cur = cur->next;//移动游标到新节点

        if(p1 != NULL) p1 = p1->next;
        if(p2 != NULL) p2 = p2->next;
    }

    //存在最后一位相加还有进位，所以要创建新节点填充进位
    if(carry == 1)
    {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));  
        node->val = carry;
        node->next = NULL;
        cur->next = node;
        cur = cur->next;
    }

    return head->next;
}


