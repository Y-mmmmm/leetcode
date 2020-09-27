#include <stdio.h>


/*
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

    每个孩子至少分配到 1 个糖果。
    相邻的孩子中，评分高的孩子必须获得更多的糖果。

那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1:
输入: [1,0,2]
输出: 5
解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。

示例 2:
输入: [1,2,2]
输出: 4
解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。

*/

/*
思路：题目要求满足两个条件
    规则定义： 设学生 A 和学生 B 左右相邻，A 在 B 左边；
        左规则： 当 ratingsB>ratingsA​时，B 的糖比 A 的糖数量多。
        右规则： 当 ratingsA>ratingsB​时，A 的糖比 B 的糖数量多。

    相邻的学生中，评分高的学生必须获得更多的糖果 等价于 所有学生满足左规则且满足右规则。

    算法流程：

        先从左至右遍历学生成绩 ratings，按照以下规则给糖，并记录在 left 中：
            先给所有学生 1 颗糖；
            若 ratingsi>ratingsi−1​，则第 i 名学生糖比第 i−1 名学生多 1 个。
            若 ratingsi<=ratingsi−1​，则第 i 名学生糖数量不变。（交由从右向左遍历时处理。）
            经过此规则分配后，可以保证所有学生糖数量 满足左规则 。

        同理，在此规则下从右至左遍历学生成绩并记录在 right 中，可以保证所有学生糖数量 满足右规则 。

        最终，取以上 2 轮遍历 left 和 right 对应学生糖果数的 最大值 ，这样则 同时满足左规则和右规则 ，即得到每个同学的最少糖果数量。

    复杂度分析：
        时间复杂度 O(N) ： 遍历两遍数组即可得到结果；
        空间复杂度 O(N) ： 需要借用left，right的线性额外空间。

*/


/*
class Solution {
    public int candy(int[] ratings) {
        int[] left = new int[ratings.length];
        int[] right = new int[ratings.length];

        Arrays.fill(left, 1);
        Arrays.fill(right, 1);

        for(int i = 1; i < ratings.length; i++)
            if(ratings[i] > ratings[i - 1]) left[i] = left[i - 1] + 1;

        int count = left[ratings.length - 1];
        for(int i = ratings.length - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1]) right[i] = right[i + 1] + 1;
            
            count += Math.max(left[i], right[i]);
        }
        return count;
    }
}
*/



int candy(int* ratings, int ratingsSize){

    if(ratings == NULL || ratingsSize <= 0) return 0;

    int candy_num[ratingsSize];
    int  res = 0;
    candy_num[0] = 1;
    /*从左到右遍历一次*/
    for(int i = 1; i < ratingsSize; i++)
    {
        if(ratings[i] > ratings[i - 1])
            candy_num[i] = candy_num[i-1] + 1;//从左往右：如果比前一个人分高，那么糖果比前一个人+1
        else
            candy_num[i] = 1;//每人至少有一个
    }
    /*从右到左再遍历一次*/  
    for(int j = ratingsSize - 2; j >= 0; j--)
    {
        //从右往左：如果比后一个人分高，但是糖果没他多，那么糖果比后一个人+1
        if(ratings[j] > ratings[j + 1] && candy_num[j] <= candy_num[j+1])
           candy_num[j] = candy_num[j+1] + 1;
    }
        
    for(int i = 0; i < ratingsSize; i++)
    {
        res += candy_num[i];
    }        
    return res;
}





