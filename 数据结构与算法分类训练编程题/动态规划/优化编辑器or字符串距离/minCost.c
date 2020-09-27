#include <stdio.h>
#include <string.h>

/*
题目描述：
    对于两个字符串A和B，我们需要进行 插入i、删除d 和 修改r 操作将 A串 变为 B串。
    定义 ic，dc，rc 分别为三种操作的代价，请设计一个高效算法，求出将 A串 变为 B串 所需要的 最少代价。
    给定两个字符串 A 和 B，及它们的长度和三种操作代价，请返回将A串变为B串所需要的最小代价。保证两串长度均小于等于300.

    Levenshtein 距离，又称编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑操作次数。
    许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。
    编辑距离的算法是首先由俄国科学家Levenshtein提出的，故又叫Levenshtein Distance。

    Ex：
    字符串A:abcdefg
    字符串B: abcdef

    通过增加或是删掉字符”g”的方式达到目的。这两种方案都需要一次操作。把这个操作所需要的次数定义为两个字符串的距离。

    要求：
    给定任意两个字符串，写出一个算法计算它们的编辑距离。


*/

/*
思路：动态规划

    生成大小为 (N+1)*(M+1) 的矩阵 dp . dp[x][y] 表示 A [前]x个字符串 转换成 B[前]y个字符 所花费的代价.
    对于 第一行 来说, dp[0][y] 表示将一个空串变为 B的前y个字符组成的子串,花费的代价为 ic*y;
    同理,对于 第一列 dp[x][0] = x*dc;

    对于其他的位置, dp[x][y] 可能有以下几种取值:
        dp[x-1][y-1]+rc; // 若 A[x-1] != B[y-1] 将 A前x-1个字符 变为 B前y-1个字符,再将最后一个字符替换.
        dp[x-1][y-1];    // 若 A[x-1] == B[y-1] 将 A前x-1个字符 变为 B前y-1个字符,最后一个不用修改.
        dp[x-1][y]+dc;   // 删除一个字符,将 A前x-1个字符 变为 B的 前y个字符
        dp[x][y-1]+ic;   // 将A前x个字符变为B的前y-1个字符,再插入一个字符

        dp[x][y]的值就为以上四者最小的一个.
    求解完毕, dp[n][m] 即为所求.

    A[x-1]代表A的第x个字符，注意下标是从0开始的,B[y-1]代表 B的第y个字符

*/

 /* 
    字符串之间的距离，编辑距离，将strA编辑成strB所需的最小代价,编辑操作包括插入一个字符、删除一个字符、替换一个字符
    
    分别对应的代价是ic、dc、rc，insert cost、delete cost、replace cost

    strA[x-1]代表strA的第x个字符，注意下标是从0开始的,strA[y-1]代表strA的第y个字符

    定义一个代价矩阵为(N+1)*(M+1)，M N 表示strA strB的长度,dp[x][y]表示strA的前x个字符串编辑成 strB的前y个字符所花费的代价
    
    dp[x][y]是下面几种值的最小值：
        1、dp[x][y] = dp[x-1][y] + dc
            dp[x-1][y]将strA的前x-1个字符编辑成strB的前y个字符的代价已知，
            那么将strA的前x个字符编辑成strB的前y个字符的代价dp[x][y]就是dp[x-1][y] + dc
            相当于strA的前x-1个字符编辑成strB的前y个字符，现在变成了strA的前x个字符，增加了一个字符，要加上删除代价
        2、dp[x][y] = dp[x][y-1] + ic
            p[x][y-1]将strA的前x个字符编辑成strB的前y-1个字符的代价已知，
            现在变为strB的前y个字符，相应的在strA前x个操作代价的基础上插入一个字符
        3、dp[x][y] = dp[x-1][y-1]
            dp[x-1][y-1]将strA的前x-1个字符编辑成strB的前y-1个字符的代价已知，
            strA的第x个字符和strB的第y个字符相同，strA[x-1] == strB[y-1]，没有引入操作
        4、dp[x][y] = dp[x-1][y-1] + rc
            strA的第x个字符和strB的第y个字符不相同，strA[x-1] ！= strB[y-1]，
            在strA的前x-1个字符编辑成strB的前y-1个字符的代价已知的情况下，
            计算在strA的前x字符编辑成strB的前y个字符的代价需要加上替换一个字符的代价
* */

int min4(int a,int b,int c,int d)
{
    int min1;
    int min2;
    int min;
    
    min1 = (a)<(b)?(a):(b);
    
    min2 = (min1)<(c)?(min1):(c);
    
    min = (min2)<(d)?(min2):(d);
    
    return min;
}

#include <stdio.h>
#include <string.h>

#define min2(a,b)    ((a)<(b)?(a):(b))
#define min3(a,b,c)    (min2(a,min2(b,c)))


int calStringDistance(char *A,char *B)
{
    int lenA = strlen(A);
    int lenB = strlen(B);
    
    int dp[lenA+1][lenB+1];
    
    int rc = 1;//替换代价 1次
    int ic = 1;//插入代价 1次
    int dc = 1;//删除代价 1次
    
    int case1,case2,case3;
    
    memset(dp,0,sizeof(dp));
    
    for(int i=0;i <= lenA; i++)
        dp[i][0] = i;
    
    for(int i=0;i<=lenB;i++)
        dp[0][i] = i;
    
    for(int i=1;i<=lenA;i++)
    {
        for(int j=1;j<=lenB;j++)
        {
            // 将A的前x-1个字符已经编辑成了B的前y个字符，那么此时要将A的前x个字符编辑成B的前y个字符，A多了一个需要删除
            // 如A:abcd B:abc ，前3个已经是B了，只要删除一个d即可
            case1 = dp[i-1][j] + dc; 
            
            // 将A的前x个字符已经编辑成B的前y-1个字符，A到头了，B还缺一个，所以要增加一个
            case2 = dp[i][j-1] + ic; 

            if(A[i-1] == B[j-1]) 
                case3 = dp[i-1][j-1]; // A的前x-1个已经编辑成了B的前y-1个，此时A的第x个和B的第y个也相同，就不要操作
            else     
                case3 = dp[i-1][j-1] + rc; // A的前x-1个已经编辑成了B的前y-1个，但此时A的第x个和B的第y个不相同，就需要怎加一个替换操作
            
            dp[i][j] = min3(case1,case2,case3);//最后选取代价最小的
        }
    }
    
    return dp[lenA][lenB];
    
}


int main()
{
    char A[1000];
    char B[1000];
    
    while(gets(A))
    {
        gets(B);
        int minCost = calStringDistance(A,B);
        printf("%d\n",minCost);
    }

    return 0;
    
}



