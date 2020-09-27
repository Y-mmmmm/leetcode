#include <stdio.h>
#include <stdbool.h>

/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。
假设输入的数组的任意两个数字都互不相同。

参考以下这颗二叉搜索树：

     5
    / \
   2   6
  / \
 1   3

示例 1：

输入: [1,6,3,2,5]
输出: false

示例 2：

输入: [1,3,2,6,5]
输出: true

*/


/*
思路：
首先：二叉搜索树的节点值 left < root <right
其次：后续遍历数组特点：[  left    ][  right    ][  root  ]
                 	         [ i, m-1 ][  m, j-1  ][      j    ]
在后序遍历得到的序列中，最后一个数字是根节点的值，根节点前面的数字可以划分为两个部分。
第一部分是左子树的值，它们都比根节点值小，第二部分是右子树的值，它们都比根节点值大。

    1.递归
        根节点为数组最后一个元素j，根据二叉搜索树的特点和后序遍历的特点
        找到右子树的左边界m（第一个比根节点大的值的位置），即可划分左右子树
        然后缩小边界判定子结构

    2.单调栈
*/


bool recur(int* postorder,int i,int j)
{
    if(i >= j)   return true;//区间[i,j]收到头了，节点判断结束了
    int root = postorder[j]; //根节点就是后序遍历数组最后一个元素

    int p = i;
    while(postorder[p] < root)  p++; //左子树元素都比根节点小，右子树元素都比根节点大，在[i,j]区间找出左子树的右边界或者说右子树的左边界

    int m=p; //记录右子树左边界

    while(postorder[p] > root)  p++; //再接着找右子树右边界，也就是根节点

    //判断右子树右边界是否为根节点，然后再判断左子树[i,m-1]，和右子树[m-1,j-1]是否也满足二叉搜索树的特征
    return p==j && recur(postorder,i,m-1)&&recur(postorder,m,j-1);
}

bool verifyPostorder(int* postorder, int postorderSize){
    if(postorder == NULL)   return true;
    return recur(postorder,0,postorderSize-1);
}




//-----------------------------------------------------

bool recur(int* postorder, int postorderSize,int i,int j)
{
    //当 i ≥ j，说明此子树节点数量 ≤1 ，无需判别正确性，因此直接返回 true
    //左子树为空的时候，m=i；j=m-1；所以i要大于j
    //if(i >= j)  return true;
    if(i >= j -1)  return true;//if(i >= j)优化为j-1，任意两个数都可以构成搜索树的后序遍历
    int p = i;
    while(postorder[p]<postorder[j])    p++;//找到右子树左边界，也是左子树的右边界
    int m = p;
    while(postorder[p]>postorder[j])    p++;//找到右子树右边界

    //p==j 右子树右边界=根节点，正确，然后递归判断左右子树的结构
    return p==j &&recur(postorder,postorderSize,i,m-1)&&recur(postorder,postorderSize,m,j-1);
}


bool verifyPostorder(int* postorder, int postorderSize){
    if(postorder == NULL)  return true;//本题空节点认为true

    return recur(postorder,postorderSize,0,postorderSize-1);
}

