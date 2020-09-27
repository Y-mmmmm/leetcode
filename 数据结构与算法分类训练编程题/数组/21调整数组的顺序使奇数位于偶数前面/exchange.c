#include <stdio.h>
#include <stdbool.h>

bool isEven( int n)
{
    return (n & 1) == 0; //偶数返回真，奇数返回假
}

//使用函数指针进行抽象封装，只需要更改功能函数即可
int* exchange(int* nums, int numsSize, bool(*fun)(int)){
    if(nums == NULL || numsSize <= 0)
    {
        return NULL;
    }
    int i = 0;
    int j = numsSize-1;
    int tmp;

    while(i<j)
    {
        while(i<j && (!fun(nums[i]))) //头指针找到奇数则继续，找到偶数则跳出   
            i++;

        while(i<j && (fun(nums[j])))  //尾指针找到偶数则继续，找到奇数则跳出  
            j--;

        if(i<j)
        {
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }       
    }

    return nums;
}

void ReorderOddEven(int *nums,int len)
{
    exchange(nums,len,isEven);

}

