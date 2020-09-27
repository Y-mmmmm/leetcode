#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


/*
素数：除了1以外，只能被自身整数的数，必须大于1；最小的素数是2
*/

//------------------------------------------------
/*方法1：暴力循环除到n-1,时间复杂度O(n)*/
bool is_Prime_1(unsigned int n)
{
    if(n == 1)
        return false;
    if(n == 2 || n == 3)
        return true;

    for(int i=2;i<n;i++)
    {
        if((n%i) == 0)
            return false;
    }
    return true;
}

//------------------------------------------------
/*方法2：改进的方法1，一个数可以因式分解，分解得到数肯定小于sqrt(n)，故不需要遍历到n-1*/
bool is_Prime_2(unsigned int n)
{
    if(n == 1)
        return false;
    if(n == 2 || n == 3)
        return true;

    int tmp = sqrt(n);
    for(int i=2;i < tmp+1;i++)
    {
        if((n%i) == 0)
            return false;
    }
    return true;
}

//------------------------------------------------
/*方法3：根据质数的分布规律：大于等于5的质数一定和6的倍数相邻，但在6的倍数相邻两侧并不是一定就是质数。*/
/*
证明：令x≥1，将大于等于5的自然数表示如下：
······ 6x-1，6x，6x+1，6x+2，6x+3，6x+4，6x+5，6(x+1），6(x+1)+1 ······
可以看到，不在6的倍数两侧，即6x两侧的数为6x+2，6x+3，6x+4，由于2(3x+1)，3(2x+1)，2(3x+2)，
所以它们一定不是素数，再除去6x本身，显然，素数要出现只可能出现在6x的相邻两侧。
这里要注意的一点是，在6的倍数相邻两侧并不是一定就是质数。
此时判断质数可以6个为单元快进，即将方法（2）循环中i++步长加大为6，加快判断速度，
原因是，假如要判定的数为n，则n必定是6x-1或6x+1的形式，对于循环中6i-1，6i，6i+1,6i+2，6i+3，6i+4，
其中如果n能被6i，6i+2，6i+4整除，则n至少得是一个偶数，但是6x-1或6x+1的形式明显是一个奇数，故不成立；
另外，如果n能被6i+3整除，则n至少能被3整除，但是6x能被3整除，故6x-1或6x+1（即n）不可能被3整除，故不成立。
综上，循环中只需要考虑6i-1和6i+1的情况，即循环的步长可以定为6，每次判断循环变量k和k+2的情况即可，
理论上讲整体速度应该会是方法（2）的3倍。

*/

bool is_Prime_3(unsigned int n)
{
    if(n == 1)
        return false;
    if(n == 2 || n == 3)
        return true;

    if((n%6) != 1 && (n%6) != 5) //注意 &&
        return false;

    int tmp = sqrt(n);

    for(int i=5; i <= tmp; i += 6) //注意 <=
    {
        if(n%i == 0 || n%(i+2) == 0)       
            return false;                   
    }

    return true;
}


//------------------------------------------------

void main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        if(is_Prime_3(n))
        {
            printf("%d YES!\n",n);
        }
        else
        {
            printf("%d NO\n",n);
        }            
        
    }
}


/*
void main()
{
    int n;
    int cnt =0;
    while(scanf("%d",&n) != EOF)
    {
        for(int i=2;i<n;i++)
        {
            if(is_Prime_3(i) && is_Prime_3(n-i))
            {
                cnt++;
                printf("%d = %d + %d\n",n,i,n-i);
            }
        }
        printf("----%d pairs----\n",cnt/2);   
        cnt = 0;     
        
    }
}
*/

