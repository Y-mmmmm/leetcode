
//注意审题：不用任何数学库函数，所以我们只用加减乘除
#include <stdio.h>

//此代码错误


//二分搜索求开n次方
double epr = 10E-14;
double Mysqrt(double m, int n)
{
    double left = 0;
    double right = m;
    double mid = left + (right - left) / 2;
    double last;//保存上一次运算的结果
    double temp;
    do {
        //m除以mid n-1次
        temp = m;
        for (int i = 0; i<n-1; i++)
            temp = temp / mid;
        //二分
        if (mid>temp)
            right = mid;
        else
            left = mid;
        //记录、更新
        last = mid;
        mid = left + (right - left) / 2;
    } while (mid - last>epr ||mid - last<-epr);
    return mid;
}
int main()
{
    double m;
    int n;
    scanf("%d,%d",&m,&n);
           
    printf("%f",Mysqrt(m,n));
    
}


/*
%d 有符号10进制整数
%i 有符号10进制整数
%o 无符号8进制整数
%u 无符号10进制整数
%x 无符号的16进制数字，并以小写abcdef表示
%X 无符号的16进制数字，并以大写ABCDEF表示
%F/f 浮点数
%E/e 用科学表示格式的浮点数
%g 使用%f和%e表示中的总的位数表示最短的来表示浮点数 G 同g格式，但表示为指数
%c 单个字符
%s 字符串 
%p地址
*/
