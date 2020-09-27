#include<stdio.h>


#include<stdio.h>

//暴力法
double getCubeRoot(double input)
{
    double i;
    for(i=0.0;i<=input;i+=0.05) //注意步长 0.05
    {
        if((i*i*i)>=input)
            return i;
    }
    return 0;
}
//二分法
double getCubeRoot2(double input)
{
    double left = 1.0; //从1开始，查找 1-input之间的数
    double right = input;
    double mid;
    
    //right= left = mid 时break
    while(right - left > 0.001)
    {
        mid = left + (right - left)/2.0;
        
        if(mid*mid < input/mid)//降低溢出概率
            left = mid;
        else 
            right = mid;//直接收缩边界
    }
    return mid;
}

#define myAbs(a)    ((a)>(0)?(a):(-a))
//牛顿迭代法
double getCubeRoot3(double input)
{
    double x = input;
    
    while(myAbs(x*x*x - input)>0.001)
    {
        x = x - (x*x*x - input)/(3.0*x*x);
    }
    return x;
}


int main()
{
    double num,i;
    scanf("%lf",&num);

    printf("%.1lf\n",getCubeRoot3(num)); //输出要使用 printf(".1lf")

   return 0;
}
