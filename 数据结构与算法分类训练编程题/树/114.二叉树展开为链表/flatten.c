/*
给定一个二叉树，原地将它展开为一个单链表。

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6

将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

*/


/*
后序遍历：左 右 根

第一步：暂存右子树，将左子树接到右子树
第二步：左子树置空，找到接到右子树的左子树的最右节点
第三步：将暂存的右子树接过来


    1
   / \
  2   5
 / \   \
3   4   6

//将 1 的左子树插入到右子树的地方
    1
     \
      2         5
     / \         \
    3   4         6        
//将原来的右子树接到左子树的最右边节点
    1
     \
      2          
     / \          
    3   4  
         \
          5
           \
            6
            
 //将 2 的左子树插入到右子树的地方
    1
     \
      2          
       \          
        3       4  
                 \
                  5
                   \
                    6   
        
 //将原来的右子树接到左子树的最右边节点
    1
     \
      2          
       \          
        3      
         \
          4  
           \
            5
             \
              6         
  以此类推
*/

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


//后序遍历
void flatten(struct TreeNode* root){
    if(root == NULL)    return;
   
    flatten(root->left);
    flatten(root->right);

    struct TreeNode *tmp = root->right;//暂存右子树

    root->right = root->left; //将左子树接到右子树

    root->left = NULL; //左子树置空

    while(root->right != NULL)  root = root->right;//找到接到右子树的左子树的最右节点

    root->right = tmp;//把直接的左子树接过来

}

