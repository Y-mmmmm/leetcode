# README

## 这是一个采用链表形式的动态队列，预留了基本的接口；

使用头、尾指针管理节点，count用于对队列节点计数；

Type 目前为int型。

如果用于大数据量的情况，最好使用静态数组，设计成ringbuffer

```c
typedef struct node

{

  Type data;

  struct node *next;

}Node_t;

typedef struct queue

{

  Node_t *head; 

  Node_t *tail; 

  int count;  

}Queue_t;
```



