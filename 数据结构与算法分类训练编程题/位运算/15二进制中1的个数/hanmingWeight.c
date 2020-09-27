#include <stdio.h>
#include <stdint.h>

//注意！！！一定要是无符号正数才可以移位判断，否则复数移位，左边补符号位1，最后直接死循环

/*
方法一：
思路：x = x & (x-1);从右向左数，找到第一个1，把1后面的所有的数字（包括1）都变为0，
再继续找下一个1，依次清0，直到所有的1都清0
*/
int hammingWeight_1(uint32_t n) 
{
	int cnt = 0;
	while(n)
	{
		n = n & (n-1);
		cnt++;
	}
	return cnt;
}

/*
方法二：时间复杂度O(n)
思路：例如一个int32数，使用while循环移位检测每一位是否为1；只有 1 & 1 = 1
*/
int hammingWeight_2(uint32_t n) 
{
	int cnt = 0;
	while(n)
	{
		cnt += n & 1;
        n = n >> 1;
		
	}
	return cnt;
}

/*
方法三：
思路：将所有1加起来，二分法；将相邻两位相加得到一个新数，再将新数的相邻两位相加，依次类推；类似2048的玩法
*/
int hammingWeight_3(uint32_t n) 
{
    n = (n & 0x55555555) + ((n>>1)  & 0x55555555); 
	n = (n & 0x33333333) + ((n>>2)  & 0x33333333); 
	n = (n & 0x0F0F0F0F) + ((n>>4)  & 0x0F0F0F0F); 
	n = (n & 0x00FF00FF) + ((n>>8)  & 0x00FF00FF); 
	n = (n & 0x0000FFFF) + ((n>>16) & 0x0000FFFF); 

	return n;

}


void main()
{
    printf("%d\n",hammingWeight_1(0x0F));
    printf("%d\n",hammingWeight_2(0x0F));
    printf("%d\n",hammingWeight_3(0x0F));
}
