/*
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

    可以认为区间的终点总是大于它的起点。
    区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

示例 1:
输入: [ [1,2], [2,3], [3,4], [1,3] ]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。

示例 2:
输入: [ [1,2], [1,2], [1,2] ]
输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。

示例 3:
输入: [ [1,2], [2,3] ]
输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。


*/


//贪心 ： 每一步最优，最后就是全局最优

int cmp(const void *a,const void *b)
{
    int **pa = (int **)a;
    int **pb = (int **)b;

    return pa[0][1]-pb[0][1];
}

//贪心算法
int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize){
    if(intervals == NULL || intervalsSize < 1)   return 0;
    
    qsort(intervals,intervalsSize,sizeof(int *),cmp);//以区间末尾的大小进行升序排序，注意 int *

    int nonOverLapCnt = 1; //至少有一个区间不相交
    int x_end = intervals[0][1]; //排序后的第一个区间end

    for(int i=1;i<intervalsSize;i++)
    {
        int start = intervals[i][0]; //下一个区间的开始位置
        //只要下一个区间的起始位置>=前一个区间的结束位置，就是不相交
        if(start >= x_end)
        {
            nonOverLapCnt++; //计数不重叠的区间个数
            x_end = intervals[i][1]; //更新下一个区间的结尾
        }
    }

    //移除区间数量 = 总数量 - 不重叠数量
    return intervalsSize - nonOverLapCnt;
}

