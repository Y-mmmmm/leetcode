#include "queue.h"

int main(void)
{
    Queue_t myqueue;
    int tmp;

    int a[6]={2,0,2,0,7,13};
    Queue_Init(&myqueue);

    for(int i =0;i<6;i++)
    {
        Queue_Push(a[i],&myqueue);
    }

    for(int i=0;i<6;i++)
    {
        Queue_Pop(&tmp,&myqueue);
        printf("%d ",tmp);
    }



}

