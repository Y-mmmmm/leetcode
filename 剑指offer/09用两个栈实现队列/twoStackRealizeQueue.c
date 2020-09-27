#include <stdio.h>
#include <stdlib.h>

/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ,
分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

*/


/*
思路：两个栈模拟队列，一个守财奴，一个败家子
stack1：只管进
stack2: 只管出
有个缺点，静态分配了最大数组10000，空间利用率低，内存消耗大。可以考虑试试双向链表

*/

typedef struct {
    int len;
    int top1;
    int top2;
    int *stack1;
    int *stack2;

} CQueue;


CQueue* cQueueCreate() {
    CQueue *queue = (CQueue *)malloc(sizeof(CQueue));
    if(queue == NULL)
    {
        return NULL;
    }
    queue->len = 1000;
    queue->top1 = -1;
    queue->top2 = -1;
    queue->stack1 = (int *)calloc(queue->len,sizeof(int));
    queue->stack2 = (int *)calloc(queue->len,sizeof(int));

    if(queue->stack1 == NULL || queue->stack2 == NULL)
    {
        return NULL;
    }

    return queue;
}

//守财奴
void cQueueAppendTail(CQueue* obj, int value) {

    obj->stack1[++(obj->top1)] = value; //++在前，因为从-1开始数，方便

}

//败家子
int cQueueDeleteHead(CQueue* obj) {
    //如果stack2是空的，就需要将stack1的数据倒序塞进来
    if(obj->top2 == -1)
    {
        while(obj->top1 != -1)
        {
            obj->stack2[++(obj->top2)] = obj->stack1[(obj->top1)--]; //倒序塞进stack1
        }
    }

    return obj->top2 == -1 ? -1 : obj->stack2[(obj->top2)--];//再正序pop出，若stack1是空的，则stack2也空时，返回-1
}

void cQueueFree(CQueue* obj) {
    free(obj->stack1);
    free(obj->stack2);
    free(obj);

}
//-------------------------------------------------
typedef struct {
    int *stack_in;
    int *stack_out;
    int top_in;
    int top_out;
    int len;

} CQueue;


CQueue* cQueueCreate() {
    CQueue *queue = (CQueue *)malloc(sizeof(CQueue));
    if(queue == NULL)   return NULL;

    queue->len = 1000;

    queue->stack_in = (int *)calloc(queue->len,sizeof(int));
    queue->top_in = -1;

    queue->stack_out = (int *)calloc(queue->len,sizeof(int));
    queue->top_out = -1;

    if(queue->stack_in == NULL || queue->stack_out == NULL) return NULL;

    return queue;
}

void cQueueAppendTail(CQueue* obj, int value) {
    if(obj == NULL) return;

    obj->stack_in[++(obj->top_in)] = value;

}

int cQueueDeleteHead(CQueue* obj) {
    if(obj == NULL) return -1;

    if(obj->top_out == -1)
    {
        while(obj->top_in != -1)
        {
            obj->stack_out[++(obj->top_out)] = obj->stack_in[(obj->top_in)--];
        }
    }

    return obj->top_out == -1?-1:obj->stack_out[(obj->top_out)--];
}

void cQueueFree(CQueue* obj) {
    if(obj == NULL) return;
    free(obj->stack_in);
    free(obj->stack_out);
    free(obj);
}



