#include <stdio.h>
#include <stdbool.h>

/*
求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

//方法1,利用关系运算符的短路关系
int sumNums(int n){
   int sum = n;
   bool flag = n>0 && (sum += sumNums(n-1))>0; //n>0就继续递归，否则中止递归

   return sum; //返回递归的累加和
}


//方法2 利用求和公式 n(n+1)/2，让编译器计算
//牛逼！！！！！
int sumNums(int n) {
    bool arr[n][n+1];
    return sizeof(arr)>>1;
}
