#include <stdio.h>
#include <stdbool.h>


/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。

注意空字符串可被认为是有效字符串。

示例 1:
输入: "()"
输出: true

示例 2:
输入: "()[]{}"
输出: true

示例 3:
输入: "(]"
输出: false

示例 4:
输入: "([)]"
输出: false

示例 5:
输入: "{[]}"
输出: true

示例6
输入: ""
输出: true

*/

//思路：辅助栈，遇到左括号则入栈，遇到右括号则出栈，栈空则为有效括号，否则错

bool isValid(char * s){
    if(s == NULL || *s == '\0')
        return true;
    char *stack = (char *)malloc(sizeof(char)*strlen(s)+1);
    if(stack == NULL)
        return false;
    int top = 0;

    for(int i=0;s[i];i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[' )
            stack[top++] = s[i];
        else
        {
            if(--top<0) return false; //判断栈是否为空，因为top初值=0
            if(s[i] == ')' && stack[top] != '(') return false;
            if(s[i] == '}' && stack[top] != '{') return false;
            if(s[i] == ']' && stack[top] != '[') return false;
            
        }
    }

    return (!top);

}


bool isValid(char * s){
    if(s == NULL || *s == '\0')
        return true;

    int len = strlen(s);
    char stack[len+1];
    int top = 0;

    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            stack[top++] = s[i];//push
        else
        {
            if(--top < 0)   return false;
            if((s[i] == ')' && stack[top] != '(')||(s[i] == ']' && stack[top] != '[')||(s[i] == '}' && stack[top] != '{')) 
            return false;
        }
        
    }
    
    return !top;
}




