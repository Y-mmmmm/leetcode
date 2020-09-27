#include <iostream>
#include <stack>
#include <vector>


using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
先序：考察到一个节点后，即刻输出该节点的值，并继续遍历其左右子树。(根左右)

中序：考察到一个节点后，将其暂存，遍历完左子树后，再输出该节点的值，然后遍历右子树。(左根右)

后序：考察到一个节点后，将其暂存，遍历完左右子树后，再输出该节点的值。(左右根)

*/


class Solution
{

public:
    void preOrder(TreeNode *root)
    {
        stack<TreeNode*> node_stack;
        while(root != nullptr || !node_stack.empty())
        {
            if(root != nullptr)
            {
                cout<<root->val<<' ';//先输出节点值
                node_stack.push(root);//将该节点压栈
                root = root->left;//继续向左子树前进
            }
            else
            {
                root = node_stack.top();//左子树结束，取出该节点
                node_stack.pop();
                root = root->right; //再去找右节点

            }            
        }
    };

    void inOrder(TreeNode *root)
    {
        stack<TreeNode*> node_stack;
        while(root != nullptr || !node_stack.empty())
        {
            if(root != nullptr)
            {
                node_stack.push(root);
                root = root->left;
            }
            else
            {                
                root = node_stack.top();//左子树为空，才访问根节点
                cout<<root->val<<' '; //输出该值
                node_stack.pop();//弹出
                root = root->right;//访问右子树
            }
            
        }

    };

    void postOrder(TreeNode *root)
    {
        stack<TreeNode*> node_stack;
        TreeNode *lastvisit = root;
        while(root != nullptr || !node_stack.empty())
        {
            if(root != nullptr)
            {
                node_stack.push(root);
                root = root->left;
            }
            else
            {
                root= node_stack.top();
                //后序遍历在决定是否可以输出当前节点的值的时候，需要考虑其左右子树是否都已经遍历完成。左子树为空时，右子树不一定为空
                //若lastVisit等于当前考查节点的右子树，表示该节点的左右子树都已经遍历完成，则可以输出当前节点
                if(root->right == nullptr || root->right == lastvisit)
                {
                    cout<<root->val<<' ';
                    node_stack.pop();

                    //并把lastVisit节点设置成当前节点，将当前游标节点node设置为空，下一轮就可以访问栈顶元素
                    lastvisit = root;
                    root = nullptr;
                }
                else
                {
                    root = root->right;//否则，需要接着考虑右子树
                }
                
            }   

        }

    };
   
};



int main(int argc, char* argv[]) {
    Solution ss;
	
	TreeNode* A = new TreeNode(1);
	TreeNode* B = new TreeNode(2);
	TreeNode* C = new TreeNode(4);
	TreeNode* D = new TreeNode(7);
	TreeNode* E = new TreeNode(3);
	TreeNode* F = new TreeNode(5);
    TreeNode* G = new TreeNode(6);
	TreeNode* H = new TreeNode(8);
	A->left  = B;
	A->right = E;
	B->left  = C;
	C->right = D;
	E->left  = F;
	E->right = G;
	G->left  = H;
	cout << "Pre order traversal:" << endl;
	ss.preOrder(A);

	cout << endl<<"In order traversal:" << endl;
	ss.inOrder(A);

	cout << endl<<"Post order traversal:" << endl;
	ss.postOrder(A);
	
 
	return 0;
}


