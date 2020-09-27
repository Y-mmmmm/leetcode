#include <iostream>
#include <vector>

using namespace std;


/*
在经典汉诺塔问题中，有 3 根柱子及 N 个不同大小的穿孔圆盘，盘子可以滑入任意一根柱子。
一开始，所有盘子自上而下按升序依次套在第一根柱子上(即每一个盘子只能放在更大的盘子上面)。

移动圆盘时受到以下限制:
(1) 每次只能移动一个盘子;
(2) 盘子只能从柱子顶端滑出移到下一根柱子;
(3) 盘子只能叠在比它大的盘子上。

请编写程序，用栈将所有盘子从第一根柱子移到最后一根柱子。
你需要原地修改栈。

示例1:
 输入：A = [2, 1, 0], B = [], C = []
 输出：C = [2, 1, 0]

示例2:
 输入：A = [1, 0], B = [], C = []
 输出：C = [1, 0]

提示:

    A中盘子的数目不大于14个。
*/

class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        if(A.empty()) return;
        move(A.size(), A, B, C);
    }
    void move(int num,vector<int> &from,vector<int> &mid,vector<int>& to){
        if(num <= 0) return;
        if(num == 1){
            to.push_back(from.back());
            from.pop_back();
            return;
        }
        move(num-1,from,to,mid);    // 将A中n-1个盘从A移动到中间柱子B
        move(1,from,mid,to);        // A中剩下的最大的那个盘直接移动到C
        move(num-1,mid,from,to);    // 中间柱子B中剩下的N-1个移动到C
    }
};

//---------------------------------------------------------------------
class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        if(A.empty())   return;

        move(A.size(),A,B,C);
    }

private:
    void move(int n,vector<int>& A, vector<int>& B, vector<int>& C)
    {
        if(n <= 0)  return;
        if(n == 1)
        {
            C.push_back(A.back()); //直接将A首元素直接塞到C末尾
            A.pop_back(); //再删除A的首元素
            return;
        }

        move(n-1,A,C,B);//先把上面 n - 1 个盘子从 A 借助 C 移到 B（子问题，递归）；
        move(1,A,B,C);  //再将最大的 1 个盘子从 A 直接移到 C；
        move(n-1,B,A,C);//再将 B 上 n - 1 个盘子从 B 借助 A 移到 C（子问题，递归）。
    }
};
