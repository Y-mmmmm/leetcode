#include <stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=2;i<=n;i++)
        {
            while(n%i == 0)  // n是i的整数倍
            {
                printf("%d ",i);
                n /= i;  //先除掉这个数，在剩下结果中再找
            }
        }
    }
    return 0;
}