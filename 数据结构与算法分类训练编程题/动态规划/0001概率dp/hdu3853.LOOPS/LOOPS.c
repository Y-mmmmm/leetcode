/*
Akemi Homura is a Mahou Shoujo (Puella Magi/Magical Girl).

Homura wants to help her friend Madoka save the world. But because of the plot of the Boss Incubator, she is trapped in a labyrinth called LOOPS.

The planform of the LOOPS is a rectangle of R*C grids. There is a portal in each grid except the exit grid. 
It costs Homura 2 magic power to use a portal once. 
The portal in a grid G(r, c) will send Homura to the grid below G (grid(r+1, c)), 
the grid on the right of G (grid(r, c+1)), or even G itself at respective probability (How evil the Boss Incubator is)!
At the beginning Homura is in the top left corner of the LOOPS ((1, 1)), and the exit of the labyrinth is in the bottom right corner ((R, C)). 
Given the probability of transmissions of each portal, your task is help poor Homura calculate the EXPECT magic power she need to escape from the LOOPS.

 Input
The first line contains two integers R and C (2 <= R, C <= 1000).

The following R lines, each contains C*3 real numbers, at 2 decimal places. Every three numbers make a group. 
The first, second and third number of the cth group of line r represent the probability of transportation to 
grid (r, c), grid (r, c+1), grid (r+1, c) of the portal in grid (r, c) respectively. 
Two groups of numbers are separated by 4 spaces.

It is ensured that the sum of three numbers in each group is 1, and the second numbers of the rightmost groups are 0 (as there are no grids on the right of them) 
while the third numbers of the downmost groups are 0 (as there are no grids below them).

You may ignore the last three numbers of the input data. They are printed just for looking neat.

The answer is ensured no greater than 1000000.

Terminal at EOF



Output
A real number at 3 decimal places (round to), representing the expect magic power Homura need to escape from the LOOPS.

Sample Input

2 2 
0.00 0.50 0.50 0.50 0.00 0.50 
0.50 0.50 0.00 1.00 0.00 0.00
 
Sample Output

6.000

有R*C的迷宫，左上角（1，1）是入口，（R,C）是出口，对于每个格子，有三种选择，停留在本格，向下走一格，向右走一格，
每走一格需要消耗 2 个魔法值，题目中给出每个格子的这三种选择的概率，问从入口到出口所消耗的平均魔法值数。

*/

/*

逆向递推： dp[R][C]=0;    dp[i][j]指的是当前格子到终点所需要的平均魔法值.也就是期望值

pStay  = p[i][j][0] 代表当前格子下一步停留在本格子自身的概率

pRight = p[i][j][1] 代表下一步向右走的概率

pDown  = p[i][j][2] 代表下一步向下走的概率

那么 有  dp[i][j] = pStay * dp[i][j] + pRight*dp[i][j+1] + pDown*dp[i+1][j] + 2 

       即 dp[i][j] = (pRight * dp[i][j+1] + pDown * dp[i+1][j] + 2 )/ (1 - pStay);
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int n,m;
double p[1010][1010][5];
double dp[1010][1010];
const double EPS = 1e-6;

int main()
{    
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                for(int k = 0; k < 3; k++) 
                    scanf("%lf", &p[i][j][k]);
            }
        }
        memset( dp, 0, sizeof(dp) );

        for(int i = n-1; i >= 0; i--)
        {
            for(int j = m-1; j >= 0; j--)
            {
                if(i == n-1 && j == m-1) continue; //dp[n-1][m-1] = 0

                double pStay  = p[i][j][0];
                double pRight = p[i][j][1];
                double pDown  = p[i][j][2];

                if( fabs(pStay-1.0) < EPS ) continue; //保证下面分母不为0

                dp[i][j] = (pRight * dp[i][j+1] + pDown * dp[i+1][j] + 2) / (1 - pStay);
            }
        }

        printf("%.3f\n",dp[0][0]);
    }

    return 0;
}

