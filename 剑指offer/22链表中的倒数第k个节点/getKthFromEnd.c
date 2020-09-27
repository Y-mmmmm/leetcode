
/*
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，
即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，
它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。

示例：

给定一个链表: 1->2->3->4->5, 和 k = 2.

返回链表 4->5.

*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
简单方法：
    先遍历统计链表长度，记为 nnn ；
    设置一个指针走 (n−k)(n-k)(n−k) 步，即可找到链表倒数第 kkk 个节点。
*/



/*
思路：快慢指针
    1.定义两个指向头节点的快慢指针
    2.快指针先走k步
    3.然后快慢指针同时走，直到快指针为空跳出循环，此时慢指针就指向倒数第k个节点
*/

struct ListNode 
{
    int val;
    struct ListNode *next;
};

struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    if(head == NULL)
        return NULL;
    struct ListNode *Fast = head;
    struct ListNode *Slow = head;

    for(int i=1;i<=k;i++)
    {
        Fast = Fast->next;
    }
    while(Fast != NULL)
    {
        Fast = Fast->next;
        Slow = Slow->next;
    }

    return Slow;

}


