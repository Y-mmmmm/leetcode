#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Type;

#define MAXQUEUE    10

typedef struct node
{
    Type data;
    struct node *next;
}Node_t;

typedef struct queue
{
    Node_t *head; /*指向队首指针*/
    Node_t *tail;  /*指向队尾指针*/
    int count;      /*记录队列中的项数*/
}Queue_t;

/*初始化队列*/
void Queue_Init(Queue_t *pq);
/*检查队列是否已满*/
bool Queue_IsFull(const Queue_t *pq);
/*检查队列是否为空*/
bool Queue_IsEmpty(const Queue_t *pq);
/*获取队列项数*/
int Queue_GetCount(const Queue_t *pq);
/*向队列尾压入数据*/
bool Queue_Push(Type data,Queue_t *pq);
/*从队列头弹出数据*/
bool Queue_Pop(Type *pbuff,Queue_t *pq);
/*清空队列*/
void Queue_EmptyAll(Queue_t *pq);

#endif

