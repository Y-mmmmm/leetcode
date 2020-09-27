#include <stdio.h>
#include <stdlib.h>

/*
输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。

示例 1：
输入：arr = [3,2,1], k = 2
输出：[1,2] 或者 [2,1]

示例 2：
输入：arr = [0,1,2,1], k = 1
输出：[0]

限制：

    0 <= k <= arr.length <= 10000
    0 <= arr[i] <= 10000

*/

/*
同属于TopK问题
1.快速排序后，取值
2.优化的快速排序 ：以 k 位置为基准值进行划分，左边就是组要的 k 个最小数
3. 优化队列，堆

*/


//方法1

int cmp(void *a,void *b)
{
    return *(int *)a - *(int *)b;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    if(arr == NULL || arrSize <= 0)
    {
        *returnSize = 0;
        return NULL;
    }

    int *res = (int *)calloc(arrSize,sizeof(int));
    qsort(arr,arrSize,sizeof(int),cmp);

    for(int i=0;i<k;i++)
        res[i] = arr[i];

    *returnSize = k;

    return res;
}


//方法2
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define swap1(a,b)   do{a ^= b;b ^= a; a ^= b;}while(0)

int portition(int *arr,int left,int right)
{
    
    if(right > left)
    {
        int index = (left + right)/2 + 1;
        swap1(arr[left],arr[index]);
    }

    int x = arr[left];
    int i = left;
    int j = right;

    while(i<j)
    {
        while(arr[j] >= x && i<j)    j--;
        if(i<j) arr[i++] = arr[j];

        while(arr[i] < x && i<j)    i++;
        if(i<j) arr[j--] = arr[i];
    }
    arr[i] = x;

    return i;
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){

    if(arr == NULL || arrSize <= 0 || k <= 0)
    {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = k;
    int *res = (int *)calloc(k,sizeof(int));

    if( k == arrSize)
    {
        memcpy(res,arr,sizeof(int)*k);
        return res;
    }

    int left = 0;
    int right = arrSize - 1;

    while(1)
    {
        int pviot = portition(arr,left,right); //和k-1比较
        if(pviot == k-1)  break;
        else if(pviot > k-1)  right = pviot - 1;
        else left = pviot + 1;
    }
    
    for(int i=0;i<k;i++)
    {
        res[i] = arr[i];
    }
    return res;
}



