#include <stdio.h>
#include <stdlib.h>

/*
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  

示例 1：
输入：[3,4,5,1,2]
输出：1

示例 2：
输入：[2,2,2,0,1]
输出：0

*/

/*
思路：二段排序数组查找问题，重点在于找到两个单增区间边界
    旋转后的数组可以划分为两个有序的子区间，前面区间的元素都大于等于后面的元素，我们要找的就是两个子区间的分界
    很自然想到二分查找

    nums[mid] > nums[right]
        最小元素肯定在mid的右边，所以 left = mid + 1

    nums[mid] == nums[right]
        此时 mid 可能处于左边的增区间，也可能处于右边的增区间，即最小元素不确定在它的左边还是右边
        所以 right-- ，换一个 nums[right] 再试

    nums[mid] < nums[right]
        此时 mid 肯定处在右边的增区间，所以 right = mid
*/

int minArray(int* numbers, int numbersSize){
    int Left = 0;
    int Right = numbersSize-1;
    
    while(Left < Right)
    {
        int Mid = Left + (Right - Left)/2;
        if(numbers[Mid] > numbers[Right])
        {
            Left = Mid + 1;
        }
        else if(numbers[Mid] < numbers[Right])
        {
            Right = Mid;
        }
        else
        {
            Right--;
        }
               
    }

    return numbers[Left];
}
