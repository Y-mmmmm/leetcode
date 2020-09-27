



/*
给定一个无序的整数数组，找到其中最长上升子序列的长度。

示例:

输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。

说明:

    可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
    你算法的时间复杂度应该为 O(n2) 。

进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

*/




/*
思路：
1.动态规划 O(N^2)
dp[i] 表示以 nums[i] 这个数结尾的最长递增子序列的长度。

base case ：dp[i] = 1；以自己结尾的都是1

转移方程：
if(nums[j]<nums[i])    前i个中存在一个以j结尾的元素严格小于nums[i],那么nums[i]可以接在后面
    dp[i] = max(dp[i],dp[j]+1); 0<= j <i;dp[j]表示前i个中第j个元素结尾的最长上升子序列的长度

2.动态规划+二分查找 O(N)

很具小巧思。新建数组 cell，用于保存最长上升子序列。

对原序列进行遍历，将每位元素二分插入 cell 中。

    如果 cell 中元素都比它小，将它插到最后
    否则，用它覆盖掉比它大的元素中最小的那个。

总之，思想就是让 cell 中存储比较小的元素。这样，cell 未必是真实的最长上升子序列，但长度是对的。


注：
memset的赋值是指对sizeof(dp)中的dp的字节进行的赋值。它的赋值单位是单个字节。
对于数组型的，你只能赋值0和-1，对于字符型的你可以赋值任何有效数字进去。
原因如下：

    字符型是单个字节，比如说你需要赋值为1，单个字节也就是8位，那么就是0000,0001
    数组型的元素是4个字节，比如说你要赋值为1，那么单个整型就是：0000，0001，0000，00001，0000，0001，0000，0001，
    转成十进制就是16843009 那么，对于-1和0，-1在任何字节中均是所有位数均为1，0在任何字节中所有位数均为0，对于字节赋值，这两种均是没有任何问题的。



*/



//动态规划
#define myMax(a,b)  ((a)>(b)?(a):(b))

int lengthOfLIS(int* nums, int numsSize){
    if(nums == NULL || numsSize <= 0)   return 0;
    if(numsSize == 1)   return 1;

    int dp[numsSize];
    for(int i=0;i<numsSize;i++)
        dp[i] = 1;

    for(int i=1;i<numsSize;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(nums[j] < nums[i])
                dp[i] = myMax(dp[i],dp[j]+1);
        }
    }

    int max = 0;
    for(int i=0;i<numsSize;i++)
    {
        max = myMax(max,dp[i]);
    }

    return max;
}


//辅助栈+二分
int lengthOfLIS(int* nums, int numsSize){
    if(nums == NULL || numsSize <= 0)   return 0;
    if(numsSize == 1)   return 1;

    int stack[numsSize];
    int top = 0; //以0开始
    stack[top++] = nums[0]; //先push

    for(int i=1;i<numsSize;i++)
    {
        if(nums[i] > stack[top-1]) //此时栈顶元素是top-1
        {
            stack[top++] = nums[i];//比栈顶元素大，直接接在后面
        }
        else //比栈顶小，去栈中找到比栈顶小的位置替换
        {
            int left = 0;
            int right = top-1;//右边界top-1
            while(left <= right)
            {
                int mid = left + (right-left)/2;
                if(nums[i] <= stack[mid]) //注意 <=
                    right = mid-1;
                else 
                    left = mid+1; //只要收缩边界就行了
            }
            stack[right+1] = nums[i]; //最后替换该位置
        }
    }

    return top;//返回长度  
}

//------------------------------------------------------
int lengthOfLIS(int* nums, int numsSize){
    if(nums == NULL || numsSize <= 0)   return 0;
    if(numsSize == 1)   return 1;

    int stack[numsSize];
    int top =-1;  //以-1开始
    stack[++top] = nums[0];//压栈

    for(int i=1;i<numsSize;i++)
    {
        if(nums[i] > stack[top]) //此时栈顶就是top
        {
            stack[++top] = nums[i];
        }
        else
        {
            int left = 0;
            int right = top;
            while(left <= right)
            {
                int mid = left + (right-left)/2;
                if(nums[i] <= stack[mid]) //注意 <=
                    right = mid-1;
                else 
                    left = mid+1; //仅收缩边界
            }
            stack[right+1] = nums[i]; //替换
        }
    }

    return ++top;  //长度从0-top，所以长度要+1
}

