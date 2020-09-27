#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int judge(int x,int y,char ch)
{
    int res = 0;
    switch(ch)
    {
        case '+':
            res = x+y;
            break;
        case '-':
            res = x-y;
            break;
        case '*':
            res = x*y;
            break;
        case '/':
            res = x/y;
            break;
        default:
            break;
    }
    return res;
}


int evalRPN(char ** tokens, int tokensSize){

    if(tokensSize <= 0)    return -1;

    int *numStack = (int *)calloc(tokensSize+1,sizeof(int));
    int top = -1;

    for(int i=0;i<tokensSize;i++)
    {
        //(tokens[i][0] == '-' && '\0' == tokens[i][1])这里增加判断的目的是防止负数字符串如-11被检测为负号
        if(tokens[i][0] == '+' ||(tokens[i][0] == '-' && '\0' == tokens[i][1])||tokens[i][0] == '*'||tokens[i][0] == '/' )
        {
            int x = numStack[top--];
            int y = numStack[top--];
            numStack[++top] = judge(y,x,tokens[i][0]);//计算完了直接入栈，注意y在x前
        }
        else
        {
            numStack[++top] = atoi(tokens[i]);//atoi直接转换为数字
        }

    }

    return numStack[top];
}
