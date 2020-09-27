#include <stdio.h>


/*
写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。

示例:

输入: a = 1, b = 1
输出: 2
 
提示：

    a, b 均可能是负数或 0
    结果不会溢出 32 位整数
*/


/*
sum = a^b   非进位和：异或运算
c = a&b <<1​   进位：与运算+左移一位​

循环或递归求 n 和 c ，直至进位 c=0 

*/

int add(int a, int b){
    if(b == 0)
        return a;
    int sum = a^b; //计算不进位的和
    int carry  = (unsigned int )(a&b) << 1; //计算进位，转成uint是因为C/C++不支持负数左移，会报错

    return add(sum,carry);//递归把进位加上，进位为0则退出
}

