#include <stdio.h>
#include <stdlib.h>


/*
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

示例 1：
输入：nums = [3,4,3,3]
输出：4

示例 2：
输入：nums = [9,1,7,9,7,9,7]
输出：1

*/


/*
思路：不用哈希和暴力的话，只有考虑位运算
方法1.遍历统计
     如果一个数字出现3次，它的二进制每一位也出现的3次。
     如果把所有的出现三次的数字的二进制表示的每一位都分别加起来，那么每一位都能被3整除。 
     我们把数组中所有的数字的二进制表示的每一位都加起来。如果某一位能被3整除，那么这一位对只出现一次的那个数的这一肯定为0。
     如果某一位不能被3整除，那么只出现一次的那个数字的该位置一定为1.

方法2.有限状态机
     同样是统计每个位出现1的次数，可能的状态有0次，1次，2次，超过3次归零重新记录，最后需要的状态是1次的，
     记状态 高位为 a，低位为 b ，输入为数组每个元素的每个bit 记为 c ，新态 a* ,b*;可以得出真值表
     a  b  c   a*  b*
     0  0  0   0   0
     0  1  0   0  [1]
     1  0  0  [1]  0
     1  1  0   x   x
     0  0  1   0  [1]
     0  1  1  [1]  0
     1  0  1   0   0
     1  1  1   x   x

得出 a* = a&~b&~c + ~a&b&c 
    b* = ~a&b&~c + ~a&~b&c = ~a&(b^c)
注意：上面的计算是同时的，也就是说 a* 和 b* 中的a ，b都是当前的初值，
     不能将先计算的a*作为a带入b*，因为数电或者说PFGA是并行运算的。如果要带入，需要改状态转移图


*/
//方法1
int singleNumber(int* nums, int numsSize){
    int res = 0;
    for(int i = 0; i < 32; i++)
    {
        int bitNum = 0;
        for(int j = 0; j < numsSize; j++)
        {
            bitNum += (nums[j] >> i) & 1;//求第i位次数
        }

        if(bitNum%3 == 1)    res |= 1 << i;//第i位置1

    }
    return res;
}

//方法2 
int singleNumber(int* nums, int numsSize){
    if(nums == NULL || numsSize <= 0)   return 0;

    int a = 0;
    int b = 0;
    for(int i=0;i<numsSize;i++)
    {
        int tmp = a;
        a = a&(~b)&(~nums[i]) | (~a)&b&nums[i] ; //a b 同时使用上次的a和b进行计算，注意是 | 运算，不能加，加会产生进位
        b = (~tmp)&(b^nums[i]);       
    }

    return b;
}

//并行计算易理解版
int singleNumber(int* nums, int numsSize){
    if(nums == NULL || numsSize <= 0)   return 0;

    int a = 0;
    int b = 0;
    int an = 0;
    int bn = 0;
    for(int i=0;i<numsSize;i++)
    {       
        an = a&(~b)&(~nums[i]) | (~a)&b&nums[i] ;
        bn = (~a)&(b^nums[i]); 
        a = an;
        b = bn;      
    }
    return b;
}

//改成串行的
int singleNumber(int* nums, int numsSize){
    if(nums == NULL || numsSize <= 0)   return 0;

    int a = 0;
    int b = 0;
    for(int i=0;i<numsSize;i++)
    {   
        b = (~a)&(b^nums[i]); 
        a = (~b)&(a^nums[i]);//将上面先计算的b带入a
   
    }
    return b;
}

