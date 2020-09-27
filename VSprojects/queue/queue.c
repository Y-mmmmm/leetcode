#include "queue.h"

static void CopyToNode(Type data,Node_t *pn);

static void CopyToBuff(Node_t *pn,Type *pi);

void Queue_Init(Queue_t *pq)
{
    pq->head = pq->tail = NULL;
    pq->count = 0;
}

bool Queue_IsFull(const Queue_t *pq)
{
    return pq->count == MAXQUEUE;
}

bool Queue_IsEmpty(const Queue_t *pq)
{
    return pq->count == 0;
}

int Queue_GetCount(const Queue_t *pq)
{
    return pq->count;
}

static void CopyToNode(Type data,Node_t *pn)
{
    pn->data = data;
}

static void CopyToBuff(Node_t *pn,Type *pbuff)
{
    *pbuff = pn->data;
}

bool Queue_Push(Type data,Queue_t *pq)
{   
    if(Queue_IsFull(pq)) /*队列满则无法插入*/
    return false;

    Node_t *pnew = (Node_t *)malloc(sizeof(Node_t)); //开辟一个节点
    if(pnew == NULL)
    {
        printf("Error: Unable to allocate memery!\n");
        return false;
    }
    CopyToNode(data,pnew); //将压入的数据拷贝到节点指向的数据域 = pnew->data = data;
    pnew->next = NULL;

    if(Queue_IsEmpty(pq))
        pq->head = pnew; /*队列空，将节点插在头节点后*/
    else
        pq->tail->next = pnew; /*队列非空，将节点插入尾部，也就是尾指针指向的节点后面*/

    pq->tail = pnew; /*更新尾指针指向*/
    pq->count++; /*节点计数+1*/
    
    return true;
}


bool Queue_Pop(Type *pbuff,Queue_t *pq)
{
    Node_t *pfree;

    if(Queue_IsEmpty(pq)) /*队列空则无法读取*/
        return false;

    CopyToBuff(pq->head,pbuff); /*将头指针指向的节点数据以指针方式拷贝到数据缓存*/

    pfree = pq->head; /*保存要释放的队列头节点*/
    pq->head = pq->head->next; /*将头指针指向后面的节点*/

    free(pfree); 
    pq->count--; /*节点数-1*/

    /*全部读出，则将尾指针指向NULL*/
    if(pq->count == 0)
    {
        pq->tail = NULL;
    }

    return true;
}

void Queue_EmptyAll(Queue_t *pq)
{
    Type dummy;
    while(!Queue_IsEmpty(pq))
        Queue_Pop(&dummy,pq);

}

