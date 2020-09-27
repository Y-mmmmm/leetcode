

/*
给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。
当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

说明:
不允许旋转信封。

示例:

输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3 
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。

*/



/*
其实就是最长上升子序列 LIS 拓展到了二维，方法是先固定其中一维，再对另一维求 LIS

先以第一维大小进行升序排序，如果第一维相同则进行以第二维的大小降序排序，这样可以保证在求 LIS 时少判断

1.正常dp
2.辅助栈+二分
*/


/*
二维LIS，先固定第一维，再对第二维求LIS
先以宽度 w 进行升序排序，如果遇到 w 相同的情况，则按照高度 h 降序排序。之后对高度 h 计算LIS
因为两个宽度相同的信封不能相互包含的，逆序排序保证在 w 相同的数对中最多只选取一个。
*/

//二分法 O(NlogN)
int cmp(const void *a,const void *b)
{
    int **aa = (int **)a;
    int **bb = (int **)b;

    if(aa[0][0] == bb[0][0])
        return bb[0][1]-aa[0][1];//降序
    else 
        return aa[0][0]-bb[0][0];//升序
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    int n = envelopesSize;
    if(envelopes == NULL || n < 2)  return n;

    qsort(envelopes,n,sizeof(envelopes[0]),cmp);//排序的大小取sizeof(envelopes[0])

    int stack[n];
    int top = -1;

    stack[++top] = envelopes[0][1];

    for(int i=1;i<n;i++)
    {
        if(envelopes[i][1] > stack[top])
            stack[++top] = envelopes[i][1]; //比栈顶元素大，直接入栈
        else //否则在栈中二分查找找合适的位置替换掉第二小的那个
        {
            int left = 0;
            int right = top;
            while(left <= right)
            {
                int mid = left + (right - left)/2;
                if(envelopes[i][1] <= stack[mid]) //注意 <=
                    right = mid-1;
                else 
                    left = mid+1;
            }
            stack[right+1] = envelopes[i][1];//替换
        }
    }

    return ++top;//返回栈的大小，top初始=-1，长度从0-top，所以要+1
}




//动态规划 O(N^2)

int cmp(const void *a,const void *b)
{
    int **aa = (int **)a;
    int **bb = (int **)b;

    if(aa[0][0] == bb[0][0])
        return bb[0][1]-aa[0][1];//降序
    else 
        return aa[0][0]-bb[0][0];//升序
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize){
    int n = envelopesSize;
    if(envelopes == NULL || n < 2)  return n;

    qsort(envelopes,n,sizeof(envelopes[0]),cmp);//排序的大小取sizeof(envelopes[0])

    int dp[n];
    dp[0] = 1;

    for(int i=1;i<n;i++)
    {
        dp[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(envelopes[j][1] < envelopes[i][1])
                dp[i] = fmax(dp[i],dp[j]+1);
        }
    }

    int max = 0;

    for(int i=0;i<n;i++)
    {
        max = fmax(max,dp[i]);
    }

    return max;
}


