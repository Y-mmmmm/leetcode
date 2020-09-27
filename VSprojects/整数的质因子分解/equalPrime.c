#include <stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=2;i<=n;i++)
        {
            while(n%i == 0)
            {
                printf("%d ",i);
                n /= i;
            }
        }
    }
    return 0;
}