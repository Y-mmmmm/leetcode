#include <stdio.h>



 struct ListNode {
    int val;
    struct ListNode *next;
};


//方法1
 /*
 *你变成我，走过我走过的路。
 *我变成你，走过你走过的路。
 *然后我们便相遇了..

太浪漫了 两个结点不断的去对方的轨迹中寻找对方的身影，只要二人有交集，就终会相遇❤

两个链表长度分别为L1+C、L2+C， C为公共部分的长度，按照楼主的做法： 第一个人走了L1+C步后，回到第二个人起点走L2步；
第2个人走了L2+C步后，回到第一个人起点走L1步。 当两个人走的步数都为L1+L2+C时就两个家伙就相爱了
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL)
        return NULL;
    struct ListNode *node1 = headA;
    struct ListNode *node2 = headB;

    while(node1 != node2)
    {
        node1 = node1 != NULL ? node1 = node1->next : headB;
        node2 = node2 != NULL ? node2 = node2->next : headA;
    }

    return node1;
    
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL)  return NULL;

    struct ListNode *pA = headA;
    struct ListNode *pB = headB;

    while(pA != pB)
    {
        pA = pA == NULL ? headB:pA->next;
        pB = pB == NULL ? headA:pB->next;
    }

    return pA;
}


//方法2  参考链表成环判断
/*
1.先获得两个链表的长度
2.得出链表的差t
3.让长的节点先走t步，然后两个指针一起走，直到相遇
*/

unsigned int GetListLength(struct ListNode *pHead) {
    unsigned int len = 0;
    struct ListNode *pNode = pHead;
    
    while (pNode != NULL) {
        len++;
        pNode = pNode->next;
    }
    return len;
}
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    unsigned int lenA = GetListLength(headA);
    unsigned int lenB = GetListLength(headB);
    int lenDif = lenA - lenB;

    struct ListNode *headLong = headA, *headShort = headB;
    if (lenDif < 0) {
        headLong = headB;
        headShort = headA;
        lenDif = -lenDif;
    }

    for (int i = 0; i < lenDif; ++i) {
        headLong = headLong->next;
    }

    while ((headLong != NULL) && (headShort != NULL) && (headLong != headShort)) {
        headLong = headLong->next;
        headShort = headShort->next;
    }

    return headLong;
};



