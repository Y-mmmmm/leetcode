#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//如果num很大的话，需要改为long或者long long
bool is_Prime( int num ) 
{
    if(num == 1)
        return false;
    
    if(num == 2 || num == 3 )  //两个较小数另外处理
        return true ;
    
    if((num%6) != 1 && (num%6) != 5) //不在6的倍数两侧的一定不是质数
        return false;

    int tmp = sqrt(num); //int直接去掉小数点后的数字取整

    //在6的倍数两侧的也可能不是质数
    for(int i= 5; i <= tmp; i += 6 ) //在6的俩侧如果不是素数，那么就是5或者7的倍数，只需要判断是否为这俩个数的倍数即可
    {
        if((num%i) == 0|| (num%(i+2)) == 0 )
            return false ;
    }
        
    //排除所有，剩余的是质数
    return true ;
}

/*
对数检测有问题，不能简单的除2，例如 10=3+7=7+3=5+5
5+5怎么算，所以需要重新考虑怎么得出对数

向上取余怎么样，(cnt+1)/2 --->好像可以

*/
int main() 
{
    int n;
    int cnt = 0;
    printf("NOTE:please input an even number!\n");

    while(scanf("%d",&n) != EOF)
    {
        if(n <= 0 || (n%2) == 1)
        {
            printf("NOTE:please input an even number!\n");
            continue;

        }
        for (int i = 2; i < n ; i++) 
        {
            if (is_Prime(i)  && is_Prime(n - i)) 
            {
                cnt++;
                printf("%d = %d + %d\n",n,i,n-i);
            }
        }
        printf("----%d pairs----\n",(cnt+1)/2);
        cnt = 0;
    }
    
}
