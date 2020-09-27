#include <stdio.h>

/*
思路：
方法1 使用二分法逼近，mid*mid 和x比较
方法2 牛顿迭代，使用泰勒展开
*/
/*
实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:
输入: 4
输出: 2

示例 2:
输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。


*/

/*
int mySqrt(int x){
    if(x == 0)
        return 0;
    long left = 1;
    long right = x/2+1;

    while(left <= right)
    {
        long mid = left + (right - left)/2;
        long pow = mid * mid;
        if(pow < x)
            left = mid + 1;
        else if(pow > x)
            right = mid - 1;
        else if(pow == x)
            return (int)mid;
    }
    return right;
}
*/

/*
求x的平方根，相当于y = √x，由于这个函数是单调递增（有序）的，所以可以考虑用二分法进行求解。

1.比较mid * mid 跟 x 的大小，相等则直接返回 mid，否则就去以 mid 为中点的左右区间去查找，循环直到left > right 退出。
2.x (x ≠ 0)的平方根一定是落在 [1, x/2 + 1]区间，所以取left = 1, right = x/2 + 1。
3.为了防止 mid * mid 太大，取 mid 跟 x/mid 进行比较。

*/

int mySqrt(int x)
{
    int left = 1;
    int right = x/2 +1;

    while(left <= right)
    {
        int mid = left + (right -left)/2;
        if(mid < x/mid)//mid < x/mid = mid*mid < x ；目的是防止溢出
            left = mid + 1;
        else if(mid > x/mid)
            right = mid -1;
        else if(mid == x/mid)
            return mid;
    }
    return right;
}

//泰勒展开
int mySqrt(int x){
    long a = x;
    while(a*a > x)
    {
        a = (a + x/a)/2;
    }

    return (int)a;

}
