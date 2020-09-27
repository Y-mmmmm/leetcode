#include <stdio.h>

/*
有一幅以二维整数数组表示的图画，每一个整数表示该图画的像素值大小，数值在 0 到 65535 之间。
给你一个坐标 (sr, sc) 表示图像渲染开始的像素值（行 ，列）和一个新的颜色值 newColor，让你重新上色这幅图像。
为了完成上色工作，从初始坐标开始，记录初始坐标的上下左右四个方向上像素值与初始坐标相同的相连像素点，
接着再记录这四个方向上符合条件的像素点与他们对应四个方向上像素值与初始坐标相同的相连像素点，……，重复该过程。
将所有有记录的像素点的颜色值改为新的颜色值。最后返回经过上色渲染后的图像。

示例 1:

输入: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
输出: [[2,2,2],[2,2,0],[2,0,1]]
解析: 
在图像的正中间，(坐标(sr,sc)=(1,1)),
在路径上所有符合条件的像素点的颜色都被更改成2。
注意，右下角的像素没有更改为2，
因为它不是在上下左右四个方向上与初始点相连的像素点。

注意:

    image 和 image[0] 的长度在范围 [1, 50] 内。
    给出的初始点将满足 0 <= sr < image.length 和 0 <= sc < image[0].length。
    image[i][j] 和 newColor 表示的颜色值在范围 [0, 65535]内。

*/

/*
二维数组遍历问题 == N叉树遍历问题

将图像中与当前颜色相同的替换为新颜色

思路：dfs 和 bfs

*/

void dfs(int** image, int rowlen, int collen, int i,int j,int curColor, int newColor)
{
    if(i < 0 || i >= rowlen || j<0 || j >= collen || image[i][j] != curColor || image[i][j] == -1)
        return;  
    image[i][j] = -1;//标记，防止重复访问
    
    dfs(image,rowlen,collen,i-1,j,curColor,newColor);//再遍历四个方向
    dfs(image,rowlen,collen,i+1,j,curColor,newColor);
    dfs(image,rowlen,collen,i,j-1,curColor,newColor);
    dfs(image,rowlen,collen,i,j+1,curColor,newColor);

    image[i][j] = newColor;//递归到底，回溯换新

}


int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){

    int m = imageSize;
    int n = *imageColSize;

    *returnSize = m;//返回矩阵的行的大小

    for(int i = 0;i<n;i++)
    {
        (*returnColumnSizes)[i] = n;//每一列的大小
    }

    int curColor = image[sr][sc];

    if(curColor == newColor)    return image;//当前颜色和要替换的相同，就不需要替换，直接返回

    dfs(image,m,n,sr,sc,curColor,newColor);
    return image;
}

