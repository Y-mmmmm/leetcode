#include <stdio.h>

/*
题目说明

蛇形矩阵是由1开始的自然数依次排列成的一个矩阵上三角形。

样例输入
5

样例输出
1 3 6 10 15
2 5 9 14
4 8 13
7 12
11
*/

/*
a[i][0] = a[i-1][0] + i;
a[0][j] = a[0][j-1] + j + 1 + i;
*/


int main()
{
    int n;
    
    while(scanf("%d",&n)!=EOF)
    {
        int a[n][n];
        a[0][0] = 1;
        for(int i=0;i<n;i++)
        {
            if(i>0)
            {
                a[i][0] = a[i-1][0] + i;
            }
            printf("%d",a[i][0]);//先输出行首
            //再从每行第二个数开始打印
            for(int j=1;j<n-i;j++)
            {
                a[i][j] = a[i][j-1] + j + 1 + i; //当前行比上一行的间隔要多加一个 1,也就是 +i
                printf(" %d",a[i][j]); //注意前面的空格
            }
            printf("\n");//每行结束换行
        }
    }
    return 0;
}
