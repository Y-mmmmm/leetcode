#include <stdio.h>
#include <stdlib.h>

int print_lowest1_bit(int n)
{
    int cnt = 0;
    while(n)
    {
        if(n&1 == 1)    return cnt;

        n >>= 1;
        cnt++;
    }
    return 0;
}


void main()
{
    int n;
    while(scanf("%d",&n)!= EOF)
    {
        if(n == 0)  
            printf("Sorry! NO 1\n");
        else
            printf("1 at bit : %d\n",print_lowest1_bit(n));               
    }
}
