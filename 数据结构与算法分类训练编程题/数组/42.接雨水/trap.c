/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

*/

int trap(int* height, int heightSize){
    if(height == NULL || heightSize <= 0)   return 0;

    int stack[heightSize+1];//单调栈，栈顶元素最小
    int top = -1;

    int cur = 0;
    int water = 0;

    while(cur < heightSize)
    {
        //只要栈不为空，或者当前元素比栈顶大，就可能在栈顶元素位置出有水，就要继续循环判断
        while(top != -1 && height[cur] > height[stack[top]])
        {           
            int h = height[stack[top--]]; //当前位置比栈顶元素大，那么栈顶元素的位置可能存在水，出栈
            
            if (top == -1)  break; // 栈空就出去
                
            int dt = cur - stack[top] - 1; //两堵墙之前的距离

            int min = fmin(height[stack[top]], height[cur]);//木桶原理，取最矮的

            water += dt * (min - h);//水的数量=木桶间距*深度，深度 = 木桶最矮的高度-有水位置的高度

        }
        stack[++top] = cur++;//栈空或者比栈顶元素小的就压栈  
    }
    return water;
}
