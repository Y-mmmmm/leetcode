/*
给定字符串J 代表石头中宝石的类型，和字符串 S代表你拥有的石头。 S 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。

J 中的字母不重复，J 和 S中的所有字符都是字母。字母区分大小写，因此"a"和"A"是不同类型的石头。

示例 1:

输入: J = "aA", S = "aAAbbbb"
输出: 3

示例 2:

输入: J = "z", S = "ZZ"
输出: 0

注意:

    S 和 J 最多含有50个字母。
     J 中的字符不重复。

*/

/*
思路：
1.暴力法
2.哈希法
3.动态规划
*/

//因为题目简单，直接暴力法即可，不需要花里胡哨那么多
int numJewelsInStones(char * J, char * S){
    if(J == NULL || S == NULL)  return 0;

    int m = strlen(J);
    int n = strlen(S);

    int max = 0;

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)    
            max = (J[i] == S[j])?(max + 1):(max);

    return max;
}