#include <stdio.h>
#include <stdlib.h>

/*
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中
关键点：
****调用 min、push 及 pop 的时间复杂度都是 O(1)****
 
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();   --> 返回 0.
minStack.min();   --> 返回 -2.

*/

/*
思路：辅助栈
1.push ：每次将当前值与最小值比较，当前值小则更新最小值，并压入辅助栈当前最小值；当前值大，则压入上次最小值。
2.pop：弹出两个栈的栈顶，同时更新最小值为辅助站栈顶元素

*/

#define MAXSIZE 10000

typedef struct {
    int *x_stack;/*数据栈*/
    int *min_stack;/*辅助最小值栈*/
    int x_top;
    int min_top;/*栈顶指针*/
    int min_val;/*记录最小值*/
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack)) ;

    obj->x_stack = (int *)calloc(MAXSIZE,sizeof(int));
    obj->min_stack = (int *)calloc(MAXSIZE,sizeof(int));
    obj->x_top = -1;
    obj->min_top = -1;
    obj->min_val = 0;

    return obj;
}

void minStackPush(MinStack* obj, int x) {
    if(obj == NULL) return;

    if(obj->x_top < MAXSIZE)
    {
        if(obj->x_top == -1)    obj->min_val = x;/*初始化最小值*/
            
        obj->x_stack[++(obj->x_top)] = x;
                      
        if(x < obj->min_val)    obj->min_val = x;/*更新最小值*/
   
        obj->min_stack[++(obj->min_top)] = obj->min_val; //压入最小值
        
    }
    
}

void minStackPop(MinStack* obj) {
    if(obj == NULL) return;

    --(obj->x_top);
    --(obj->min_top);

    if(obj->min_top != -1 )   
        obj->min_val = obj->min_stack[obj->min_top];/*出栈后，更新最小值*/
        
}

int minStackTop(MinStack* obj) {
    if(obj == NULL) return -1;
    return obj->x_stack[obj->x_top];
}

int minStackMin(MinStack* obj) {
    if(obj == NULL) return -1;
    return obj->min_stack[obj->min_top];
}

void minStackFree(MinStack* obj) {
    if(obj == NULL) return;
    free(obj->x_stack);
    free(obj->min_stack);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackMin(obj);
 
 * minStackFree(obj);
*/

