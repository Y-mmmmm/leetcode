

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
反转的思路大同小异，利用x%10：取余得到最右边的数，即个位数值。
利用x/10: 除去最右边的数，即整体右移一位。
本题的关键点在于整数计算溢出的判断。
定义count时切记其取值范围要比-2的32次方~2的32次方大
*/
int reverse_1(int x)
{
    long rev = 0;
    while(x != 0)
    {
        rev = rev*10 + x%10; //计算反转数
        x = x/10; //循环去掉个位数
    }
    return ((rev>2147483647 || rev<-2147483648) ? 0 : rev); //返回时判断溢出，-2^31<int<2^31-1
}


int reverse_2(int x) 
{
    int rev = 0;
    while (x != 0) 
    {
        int pop = x % 10; //求余取出个位
        x /= 10; //去除个位

        if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0; //溢出检测,2147483647的个位7
        if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0; //溢出检测，-2147483648的个位-8
        rev = rev * 10 + pop; //计算反转数
    }
        return rev;
}



//把x的每一位倒序依次存放在一个数组中，在从数组中输出正序输出所要结果，最后给定范围输出。
int reverse_3(int x)
{
    int length = 0;
    int number = x;
    int rev;

    while(x !=0)
    {
        x = x/10;
        length++; //计算数据位数
    }

    int *a =(int *)malloc(sizeof(int)*length); //根据位数分配动态数组

    for(int i =length-1;i>=0;i--)
    {
        a[i] = number%10; //倒序存入数组
        number = number/10;
    } 

    for(int i=0;i<length;i++)
    {
        rev = rev + a[i]*pow(10,i); //将数据的每一位根据规则转换成整数
    }

   return ((rev > INT_MAX-1)||(rev < INT_MIN)) ? 0 : rev; //最后做溢出判断
}

int main()
{
    printf("%d\n",reverse_1(-123));
    printf("%d\n",reverse_2(-123));
    printf("%d\n",reverse_3(-123));
    return 0;
}
