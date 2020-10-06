/*
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

限制：
0 <= 节点个数 <= 5000
*/

//注意：链表看不懂就画图，画图就懂了

#include <stdio.h>
#include <stdlib.h>


 typedef struct ListNode 
 {
      int val;
      struct ListNode *next;
  }ListNode_t;
 

//我自己的解法
//思路，新创建一个辅助头节点，然后用头插法依次将原链表插入，最后移动头指针，释放辅助头节点
struct ListNode* reverseList_1(struct ListNode* head)
{
    if(head == NULL)
        return NULL; 

    ListNode_t *Headnode = (ListNode_t *)malloc(sizeof(ListNode_t));
    
    Headnode->next = NULL;
    Headnode->val = 0;

    ListNode_t *tmp = head;
    ListNode_t *pb = NULL; //辅助指针
    while(tmp)
    {
        pb = tmp->next;  //保存原头节点的下一个节点地址 
        tmp->next = Headnode->next;//头插法，将辅助头节点指向节点的地址给新插入的节点
        Headnode->next = tmp;//新插入节点地址给辅助头节点
        tmp = pb; //移动节点
    }
    head = Headnode->next;//换头
    free(Headnode);
    return head;
    
}


//链接：https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/solution/fan-zhuan-lian-biao-yi-dong-de-shuang-zhi-zhen-jia/
//方法2，三指针
/*
定义两个指针： pre 和 cur ；pre 在前 cur 在后。每次让 pre的 next 指向 cur ，实现一次局部反转
局部反转完成之后， pre和 cur同时往前移动一个位置，循环上述过程，直至 pre到达链表尾部
*/
ListNode_t *reverseList_2(ListNode_t* head) 
{
    ListNode_t *cur = NULL, *pre = head;
    ListNode_t *tmp = NULL;
    while (pre != NULL) 
    {
        tmp = pre->next; //先保存pre指向的下一个节点地址
        pre->next = cur; //让当前pre指向的节点反转指向cur
        cur = pre; //让cur指向pre节点
        pre = tmp; //pre移动到下一个节点
    }
    return cur; //反转后，cur就是头
}


//方法三
/*
使用递归函数，一直递归到链表的最后一个结点，该结点就是反转后的头结点，记作 ret
此后，每次函数在返回的过程中，让当前结点的下一个结点的 next指针指向当前节点。
同时让当前结点的 next指针指向 NULL，从而实现从链表尾部开始的局部反转
当递归函数全部出栈后，链表反转完成。

*/

ListNode_t *reverseList_3(ListNode_t *head) 
{
    //递归中止的条件是当前为空或者下一个节点为空
    if (head == NULL || head->next == NULL) 
    {
        return head; 
    }
    ListNode_t *ret = reverseList_3(head->next); //递归找到最后一个节点
    head->next->next = head; //反转指向
    //防止链表循环，最后指向NULL
    head->next = NULL;
    return ret;//返回上一层
}

//方法四
/*
原链表的头结点就是反转之后链表的尾结点，使用 head 标记 .定义指针 cur，初始化为 head
每次都让 head下一个结点的 next指向 cur，实现一次局部反转
局部反转完成之后，cur和 head的 next指针同时 往前移动一个位置
循环上述过程，直至 cur到达链表的最后一个结点 

*/

ListNode_t *reverseList(ListNode_t *head) 
{
    if (head == NULL) 
        return NULL; 

    ListNode_t *cur = head;
    ListNode_t *pb = NULL;
    while (head->next != NULL) 
    {
        pb= head->next->next; //保存下一个节点后的节点地址

        head->next->next = cur; //让当前节点后的节点的next指针反向指向cur

        cur = head->next; //cur移动到下一个节点

        head->next = pb; //移动到pb节点
    }
        return cur;
}



