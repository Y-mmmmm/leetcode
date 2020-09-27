#include <stdio.h>
#include <stdlib.h>

/*
思路：辅助栈法，没必要以链表方式
时间复杂度O(N)
*/

struct ListNode {
    int val;
    struct ListNode *next;
};



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode *head, int* returnSize){
    if(head == NULL)
    {
        *returnSize = 0; //一定要注意这里，返回必须0，否则传空链表时，这里报错
        return NULL;
    }
        
    struct ListNode *phead = head;
    struct ListNode *stack = (struct ListNode *)malloc(sizeof(struct ListNode));//创建栈头
    if(stack == NULL)
        return NULL;
    stack->next = NULL;
    stack->val =0;

    while(phead)
    {
        struct ListNode *pb = phead->next; //保存下个节点，这里其实可以省略，但是加了力扣好像运行快一点
        struct ListNode *new_stack = (struct ListNode *)malloc(sizeof(struct ListNode)); //新插入节点就开辟栈
        
        if(new_stack == NULL)
        {
            return NULL;
        }
                   
        new_stack->next = stack->next;
        new_stack->val = phead->val; //栈中存的链表数据,push
        stack->next = new_stack; //头插法

        stack->val++;   //栈节点计数用的   
        phead = pb;
    }
    *returnSize = stack->val;

    int *parray = (int *)malloc(sizeof(int)*(*returnSize));//创建数组
    if(parray == NULL)
    {
        return NULL;
    }
    for(int i = 0;i<*returnSize;i++)
    {
        parray[i] = stack->next->val; //循环把栈中的数据塞入,pop
        stack->next = stack->next->next;//移动栈
    }
    return parray;

}