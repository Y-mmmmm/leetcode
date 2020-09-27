#include <stdio.h>



struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*
给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

*/


/*
关键：
    1.路径的保存方式：字符指针数组 *path[] -> **path + path[i] 先给二维指针分配空间存储指针的地址，
                    再为每个存储的指针地址分配空间 == char *argv[] /char **argv
    2.什么时候保存：到达叶子节点->叶子节点的判定条件：左右子树都为空
    3.路径回溯：一条路径记录完毕后，回到上层记录的位置
    4.树的遍历
    5.sprintf == itoa 的运用
*/



void dfs(char **path, char *temp, struct TreeNode *root, int cnt, int *size)
{
    if (root == NULL)   return;
        
    temp[cnt++] = root->val;//先记录节点值

    //到达叶子节点，一条路径结束，记录路径
    if (root->left == NULL && root->right == NULL) 
    {       
        int len = 0;
        for (int i = 0; i < cnt - 1; i++) 
        {
            //sprintf将temp[i]转换成字符并保存至path，返回值为写入的字符长度
            len += sprintf(&path[*size][len], "%d->", temp[i]);           
        }
        //再记录叶子节点
        sprintf(&path[*size][len], "%d", temp[cnt - 1]); 

        *size += 1;//层数+1
        return;//回溯
    }

    //前序遍历
    //cnt是值传递，不会修改上次的计数值。比如当前递归计到5，传参后，下一个节点从5计到6，但是递归返回上层时，当前还是从5开始处理。因此包含了回溯时的路径回退
    dfs(path, temp, root->left, cnt, size);
    dfs(path, temp, root->right, cnt, size);
    return;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define NUM 100

char **binaryTreePaths(struct TreeNode* root, int* returnSize)
{
    char **path = (char **)malloc(NUM * sizeof(char *));///开辟一个二维指针数组

    for (int i = 0; i < NUM; i++) 
    {
        path[i] = (char *)malloc(NUM * sizeof(char));//为每层分配空间
    }
    char temp[NUM]; //用来保存临时变量
    int cnt = 0;
    int size = 0;

    dfs(path, temp, root, cnt, &size);

    *returnSize = size;
    return path;
}


/*
void dfs(struct TreeNode* root, char **path, int *buff,int *size,int cnt)
{
    if(root == NULL)    return;

    buff[cnt++] = root->val;

    if(root->left == NULL && root->right == NULL)
    {
        int len = 0;
        for(int i=0;i<cnt-1;i++)
        {
            len += sprintf(&path[*size][len],"%d->",buff[i]);
        }
        sprintf(&path[*size][len],"%d",buff[cnt-1]);

        *size += 1;
        return;
    }

    dfs(root->left,path,buff,size,cnt);
    dfs(root->right,path,buff,size,cnt);

}

#define MAXNUM  100

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){

    char **path = (char **)calloc(MAXNUM,sizeof(char *));

    for(int i=0;i<MAXNUM;i++)
        path[i] = (char *)calloc(MAXNUM,sizeof(char));

    int buff[MAXNUM];

    int cnt = 0;
    int size = 0;

    dfs(root,path,buff,&size,cnt);

    *returnSize = size;

    return path;
}
*/


/*
void get_path(char **array, struct TreeNode* root, int* returnSize, int *buf, int local)
{
    if (root == NULL) return;
           
    if(!root->left && !root->right) {
        //说明找到路了，把缓冲区的打印出来即可
        char *str = (char*)malloc(1024);
        int len = 0;

        for (int i = 0; i < local; i++) 
        {
            len += sprintf(str + len, "%d->", buf[i]);
        }
        sprintf(str + len, "%d", root->val);
        array[(*returnSize)++] = str;
    } 
    else 
    {
        // 把当前的值写进buf，层级+1，继续递归找路
        buf[local++] = root->val;
        get_path(array, root->left, returnSize, buf, local);
        get_path(array, root->right, returnSize, buf, local);
    }
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    char **ret = (char **)malloc(1024 * sizeof(char*));
    *returnSize = 0;
    int buf[1024] = {0};
    get_path(ret, root, returnSize, buf, 0);
    return ret;
}

*/




