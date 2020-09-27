#include <stdio.h>
#include <stdlib.h>


//两种解法：DFS和BFS
/*
DFS我们每次传坐标i，j即可，先判断是否能走在递归下面和右边位置，每次递归成功返回1加下面的递归数，不成功返回0，位计算用拆位法
BFS用队列先入起点，然后不能走就跳过，能走就加入下面和右边元素

*/

//DFS
//--------------------------------------------------------
int getSums(int x,int y)
{
    int sum = 0;
    while(x!=0)
    {
        sum += x%10;
        x /= 10;
    }
    while(y!=0)
    {
        sum += y%10;
        y /= 10;
    }
    return sum;
}

int dfs(int m,int n,int k,int row,int col,int *visited)
{
    //越界，已经访问过，位数和大于k，都返回0，说明不可达
    if(row >= m || row < 0 || col >= n || col < 0 || visited[row*n+col] == 1 || getSums(row,col)>k) 
        return 0;

    visited[row*n + col] = 1; //当前位置可达，则标记为已访问

    //返回 1(00位置) + 右方搜索的可达解总数 + 下方搜索的可达解总数
    return 1 + dfs(m,n,k,row+1,col,visited) + dfs(m,n,k,row,col+1,visited); 
    
}

int movingCount(int m, int n, int k){
    int *visited = (int *)calloc(m*n,sizeof(int));
    if(visited == NULL)
        return 0;
    
    return dfs(m,n,k,0,0,visited); //首先从坐标[0][0]开始
}

//-----------------------------------------------------------------


//BFS
int getSums(int x,int y)
{
    int sum = 0;
    while(x!=0)
    {
        sum += x%10;
        x /= 10;
    }
    while(y!=0)
    {
        sum += y%10;
        y /= 10;
    }
    return sum;
}

int movingCount(int m, int n, int k){
    int *visited = (int *)calloc(m*n,sizeof(int));
    if(visited == NULL)
        return 0;
    int queue[m*n][2]; //创建队列，存放位置下标
    int head = -1; //队列头
    int tail = -1; //队列尾
    int ans = 0;   //运动范围计数
    
    //push into tail； 先放00坐标
    tail++;
    queue[tail][0] = 0;
    queue[tail][1] = 0;
    
    //队列空说明遍历完了所有解
    while(head != tail)
    {
        head++;
        int row = queue[head%(m*n)][0]; //head%(m*n)目的是构成循环队列
        int col = queue[head%(m*n)][1]; //pop from head
        
        if(row>=m || row < 0 || col >= n || col < 0 || visited[row*n + col] == 1 || getSums(row,col) > k)
        continue;

        visited[row*n + col] = 1;

        ans++;

        //push into tail
        tail++;
        queue[tail%(m*n)][0] = row + 1; //下
        queue[tail%(m*n)][1] = col;

        tail++;
        queue[tail%(m*n)][0] = row;
        queue[tail%(m*n)][1] = col + 1; //右

    }

    return ans;

}



