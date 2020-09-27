#include <stdio.h>



#define MAX(a,b)    ((a)>(b))?(a):(b)


void main()
{
    int a = 3;
    int b = 3;

    int c = MAX(a,b);

    printf("%d\n",c);
}
