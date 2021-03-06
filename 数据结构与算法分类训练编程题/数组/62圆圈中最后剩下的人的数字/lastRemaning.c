#include <stdio.h>


/*
0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。

例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。


示例 1：
输入: n = 5, m = 3
输出: 3

示例 2：
输入: n = 10, m = 17
输出: 2

限制：
    1 <= n <= 10^5
    1 <= m <= 10^6
*/

/*
思路：本题就是约瑟夫问题
1.使用单项循环链表模拟，但会超时
2.使用数学公式，以活着的人的下标，进行逆向递推，因为最后活着的人的下标就是 0 

f(n,m) = (f(n-1,m) + m)%n  ,f(n,m)表示n个人，以m报数，最后活下来的那个人的下标

f(n,m) 是那个活着人的在每轮报数后的下标,下标,下标,因为,最后活着的人的下标是0;

    正向推导过程: 约瑟夫环最后一个人的下标,一定是0(只剩一个人活着了),这点都能理解 所以从0推导

    一个人的时候: 这个活着的人的下标是0. 所以需要知道当两个人存在的时候,这个人的下标是多少;

    两个人的时候: 这个活着的人下标:(0+3)%2=1 所以需要知道当三个人存在的时候 ,这个人的下标是多少;

    三个人的时候: 这个活着的人下标:(1+3)%3=1 所以需要知道当四个人存在的时候 ,这个人的下标是多少;

    主要是公式f(n,m)=(x + m)%n 的理解,这个x到底指的是什么; 指的是在下一轮报数,那个活着人的下标:我们唯一知道的是最终活着的人的下标是0

    f(n,m)=( f(n-1,m) + m)%n 是第一轮报数,这个活着人的下标; 但是需要知道这个人在第二轮的下标 f(n-1,m),才能推出第一轮报数的下标

    f(n-1,m)=(f(n-2,m) + m)%n 是第二轮报数, 这个活着人的下标;

    ............................................................................................

    最后一轮报数 f(2,m)=(f(1,m) + m)%n=(0 + m)%n  ；f(1,m) = 0


*/



int lastRemaining(int n, int m){

    if(n <= 0)  return 0;
    
    int ans = 0;

    for(int i=2;i<=n;i++)
    {
        ans = (ans + m)%i; //注意：ans是活着的人的下标
    }
    return ans;
}