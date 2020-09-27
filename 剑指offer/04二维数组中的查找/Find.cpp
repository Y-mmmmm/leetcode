
//在一个二维数组中(每个一维数组的长度相同)
//每一行都按照从左到右递增的顺序排序,
//每一列都按照从上到下递增的顺序排序.
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数

/*
思路：
每次将 m 和目标值 target 比较：
    当 m < target，由于 m 已经是该行最大的元素，想要更大只有从列考虑，取值右移一位
    当 m > target，由于 m 已经是该列最小的元素，想要更小只有从行考虑，取值上移一位
    当 m = target，找到该值，返回 true 
用某行最小或某列最大与 target 比较，每次可剔除一整行或一整列
同理，也可以右上进行查找
*/

#include <iostream>
#include <vector>

using namespace std;

//时间复杂度 O(m+n)
//空间复杂度 O(1)
//左下找
class Solution1 
{
public:
    bool Find(int target,vector<vector<int> > array) 
    {
        int rowCount = array.size();    //第一维长度，行
        int colCount = array[0].size(); //第二维长度，列

        if(rowCount == 0 || colCount == 0)
            return false;

        int i,j;
        for(i = rowCount-1,j = 0; (i >= 0)&&(j < colCount); ) //从左下角开始遍历
        {
            if(target == array[i][j]) //找到了，返回true
                return true;
            if(target < array[i][j]) //目标比数组元素小，上移去值小的区域找
            {
                i--; //上移
                continue;
            }
            if(target > array[i][j]) //目标比数组元素大，右移去值大的区域找
            {
                j++; //右移
                continue;
            }
        }
        return false;
    }
};

//右上找
class Solution2 {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        int col = array[0].size();
        if(row ==0 || col == 0)
            return false;
        int i,j;
        for(i = 0,j = col-1; (j>=0)&&(i<row);) //从右上角开始遍历
        {
            if(target == array[i][j])
                return true;
            if(target > array[i][j])
            {
                i++;
                continue;
            }
            if(target <array[i][j])
            {
                j--;
                continue;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int> > array = {{1,7,8,9},{2,4,10,12},{3,5,13,16},{6,8,15,20}};
    
    Solution2 ss;

    if(ss.Find(100,array))
    {
        printf("OK\n");
    }
    else
    {
        printf("NO\n");
    }
    
 

    return 1;    
    
}

