#include <stdio.h>
#include <stdbool.h>

/*
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:

     3
    / \
   4   5
  / \
 1   2
给定的树 B：

   4 
  /
 1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

示例 1：
输入：A = [1,2,3], B = [3,1]
输出：false

示例 2：
输入：A = [3,4,5,1,2], B = [4,1]
输出：true

限制：
0 <= 节点个数 <= 10000

*/

 
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*
思路：递归
    1.先遍历A节点，确定哪个节点是B的根节点
    2.如果 A 的当前节点值与 B 的根节点值相同，调用 recur 函数判断子树是否也相同；
    3.如果不同，就递归调用主函数来寻找 A 的哪个节点与 B 的根节点匹配。

注意：本题认为子树不完全相同，也可以作为子结构，因此判断条件宽松一点
*/


/*判断B与A的子结构*/

bool recur(struct TreeNode *A,struct TreeNode *B)
{
    if(B == NULL)  return true; //B已遍历完，返回 true
    if(A == NULL )  return false;
    //继续判断子结构是否相同
    return (A->val == B->val)&&recur(A->left,B->left)&&recur(A->right,B->right);  
}


/*遍历A，匹配根节点*/
bool isSubStructure(struct TreeNode* A, struct TreeNode* B){
    //if(A == NULL || B == NULL)  return false; //空树不是子结构
    //return recur(A,B) || isSubStructure(A->left,B) || isSubStructure(A->right,B);
    
    return (A != NULL && B != NULL) && (recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
}


