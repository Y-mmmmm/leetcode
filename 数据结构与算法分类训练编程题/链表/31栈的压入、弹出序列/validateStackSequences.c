#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，
序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

 
示例 1：

输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

*/


/*
模拟栈法
*/


bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    int* stack = (int *) malloc (sizeof(int) * pushedSize);
    int top = 0, p1 = 0, p2 = 0;
    while(p1 < pushedSize) //遍历pushed数组
    {
        stack[top++] = pushed[p1++]; //将pushed数组元素压栈
        while(top && stack[top - 1] == popped[p2]) //若当前栈不为空，并且栈顶元素和p2所指元素相同
        {
            --top; //栈顶元素出栈
            ++p2; //p2指针后移
        }
    }
    return !top; //top=0即为true，否则都是false
}








