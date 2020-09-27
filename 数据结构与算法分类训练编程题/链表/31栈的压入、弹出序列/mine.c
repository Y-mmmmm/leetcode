
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
模拟栈法
*/



bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){

    int *stack = (int *)calloc(pushedSize,sizeof(int));
    int top = 0; //指向栈
    int i = 0; //指向pushed
    int j = 0; //指向poped

    while(i < pushedSize)
    {
        stack[top++] = pushed[i++];
        while(top && stack[top - 1] == popped[j])
        {
            top--;
            j++;
        } 
    }
    return top == 0;
}

