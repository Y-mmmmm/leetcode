#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

//递归法
int* reversePrint1(struct ListNode* head, int* returnSize){
    if(head == NULL){
        *returnSize = 0;
        return malloc(sizeof(int) * 10000);
    }
    int *ans = reversePrint(head->next, returnSize);
    ans[(*returnSize)++] = head->val;
    return ans;
}

int* reversePrint2(struct ListNode* head, int* returnSize){
    if(head==NULL){
        *returnSize=0;
        return NULL;
    }
    struct ListNode *p = head;
    int num=0;
    while(p!=NULL){
        p=p->next;
        num++;
    }
    int *res=(int *)malloc(sizeof(int)*num);
    for(int i=0;i<num;i++){
        res[num-1-i]=head->val;
        head=head->next;
    }
    *returnSize=num;
    return res;
}

