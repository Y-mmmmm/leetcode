#include <stdio.h>


/*
思路
1.前后指针，前指针指向开头，后指针指向结尾，前指针负责找偶数，后指针负责找奇数，然后互换
2.快慢指针，快指针先找奇数，然后和慢指针指向的值互换，然后慢指针移动一位，知道快指针遍历完了数组
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//-----------------------------------------------------------
//前后指针
int* exchange(int* nums, int numsSize, int* returnSize){
    if(nums == NULL || numsSize <= 0)
    {
        *returnSize = 0;
        return NULL;
    }
    int i = 0; //前指针，指向数组头
    int j = numsSize-1; //后指针，指向数组尾
    int tmp;

    while(i<j)
    {
        while(i<j && (nums[i] &1) == 1)   //头小于尾并且头找到的数为奇数，就继续往后找 ；找到偶数就跳出
            i++;

        while(i<j && (nums[j] &1) == 0)  //头找到了偶数，尾开始找奇数，如果找到的是偶数，就继续找，找到奇数则跳出  
            j--;

        //if的目的是防止最后i=j时重复换位
        //头找到了偶数，尾找到了奇数，就互换位置
        if(i<j)
        {
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }       
    }
    *returnSize = numsSize;
    return nums;
}

//-----------------------------------------------------------

//快慢指针
int* exchange(int* nums, int numsSize, int* returnSize){
    if(nums == NULL || numsSize <= 0)
    {
        *returnSize = 0;
        return NULL;
    }
    int i = 0; //慢指针
    int j = 0; //快指针
    int tmp;
    *returnSize = numsSize;

    //快指针遍历数组
    while(j<numsSize)
    {
        if((nums[j] & 1) == 1) //如果快指针找到的是奇数
        {
            //if的目的是防止i=j时重复换位
            //快指针找到了奇数，就和慢指针互换
            if(i != j)
            {
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;           
            }
            i++; //换完之后慢指针移动一位
        }
        j++;              
    }
    
    return nums;
}
