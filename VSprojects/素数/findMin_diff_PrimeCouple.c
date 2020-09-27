#include <stdio.h>
#include <stdbool.h>

/*
任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，
本题目要求输出组成指定偶数的两个素数差值最小的素数对
*/


bool isPrime(int n)
{
    if(n == 1)    return false;
    if(n == 2 || n == 3)    return true;
    
    if(n%6 !=5 && n%6 != 1)    return false;
    
    int tmp = sqrt(n);
    for(int i=5;i<=tmp;i += 6)
    {
        if(n%i == 0 || n%(i+2) == 0)
            return false;
    }
    return true;

}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=n/2;i>1;i--)//关键在于从一半开始找，越接近中点差越小
        {
            if(isPrime(i)&&isPrime(n-i))
            {
                printf("%d\n%d\n",i,n-i);
                break;
            }
        }
    }
    return 0;
}

