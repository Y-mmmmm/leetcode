#include <stdio.h>
#include <stdlib.h>

/*
给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

示例:
输入: [1,2,3,4,5]
输出: [120,60,40,30,24]

*/

/*
思路：对称遍历
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructArr(int* a, int aSize, int* returnSize){

    if(a == NULL || aSize <= 0)
    {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = aSize;

    int *b = (int *)calloc(aSize,sizeof(int));

    int tmp = 1;
    b[0] = 1;//初始化为1

    for(int i=1;i<aSize;i++)
    {
        b[i] = b[i-1]*a[i-1];//左下三角先累乘
    }
    for(int i=aSize-2;i>=0;i--) 
    {
        tmp *= a[i+1];//右上三角再累乘剩下的
        b[i] *= tmp;
    }
    return b;
}

//方法2
int* constructArr(int* a, int aSize, int* returnSize){

    if(a == NULL || aSize <= 0)
    {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = aSize;

    int *b = (int *)calloc(aSize,sizeof(int));

    int left = 1;
    for(int i=0;i<aSize;i++)//从左到右乘
    {
        b[i] = left;
        left *= a[i];
    }

    int right = 1;
    for(int i=aSize-1;i>=0;i--) //再从右到左乘
    {
        b[i] *= right;
        right *= a[i];       
    }
    return b;
}

//------------------------------------------
其实本质就是两个dp数组，分别维护 i 左侧、右侧的乘积和。楼主这里是省去了O(n)的空间

public int[] constructArr(int[] a) {
        if (a == null || a.length == 0) return a;
        int len = a.length;
        int[] left = new int[len];
        int[] right = new int[len];
        left[0] = right[len - 1] = 1;

        for (int i = 1; i < len; i++) {
            left[i] = left[i - 1] * a[i - 1];
        }
        for (int i = len - 2; i >= 0; i--) {
            right[i] = right[i + 1] * a[i + 1];
        }

        int[] ans = new int[len];
        for (int i = 0; i < len; i++) {
            ans[i] = left[i] * right[i];
        }
        return ans;
    }

//----------------------------------------
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        vector<int> b(len, 1);
        if(len == 0) return b;
        int left = 1, right = 1;
        for(int i = 0; i < len; i++){
            b[i] *= left;
            left *= a[i];               // 持有左边的所有数的乘积

            b[len - i - 1] *= right;
            right *= a[len -i - 1];     // 持有右边的所有数的乘积
        }
        return b;
    }
};
