/*
自除数 是指可以被它包含的每一位数除尽的数。

例如，128 是一个自除数，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。

还有，自除数不允许包含 0 。

给定上边界和下边界数字，输出一个列表，列表的元素是边界（含边界）内所有的自除数。

示例 1：

输入： 
上边界left = 1, 下边界right = 22
输出： [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]


*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize){

    *returnSize = 0;
    if(left == 0 || right == 0) return NULL;
    int maxLen = right - left + 1;

    int *res = (int *)calloc(maxLen,sizeof(int));
    if(res == NULL) return NULL;

    int len = 0;
    
    for(int i=left;i<=right;i++)
    {
        if(i<10)    
            res[len++] = i; //1-9都是自除数
        else
        {
            int tmp = i;
            //10的倍数、数字中间有0的、除自己的位不等于0的，都不行
            while(tmp != 0 && tmp%10 != 0 && i%(tmp%10) == 0) 
            {
                tmp = tmp / 10;
            }

            //tmp经过上面的判断后=0，才是自除数
            if(tmp == 0) 
                res[len++] = i;
        }       
    }

    *returnSize = len;
    return res;

}
