#include <stdio.h>


int leap(int a) /*自定义函数leap()用来指定输入的年份是否为闰年*/
{
    if ((a%4==0&&a%100!=0) || a%400==0)    /* 闰年判定条件 */
        return 1;    /*是闰年返回1*/
    else
        return 0;    /*不是闰年返回O*/
}

bool leap(int a) 
{
    return a%4==0 && (a%100 != 0 || a%400 == 0)    
}



