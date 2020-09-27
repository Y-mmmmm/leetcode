/*
硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)

示例1:

 输入: n = 5
 输出：2
 解释: 有两种方式可以凑成总金额:
5=5
5=1+1+1+1+1

示例2:

 输入: n = 10
 输出：4
 解释: 有四种方式可以凑成总金额:
10=10
10=5+5
10=5+1+1+1+1+1
10=1+1+1+1+1+1+1+1+1+1

说明：

注意:

你可以假设：

    0 <= n (总金额) <= 1000000

*/



/*
dp 数组建立：dp[i][j] 表示 i 种硬币组成面值为 j 时的方法数

考虑 base case

    dp[0][j] 0 种硬币组成面值 j，不可能有方案，因此是 0， java 初始化时数组是 0，不用特殊处理

    dp[i][0] 多种硬币组成面值 0，只有一种方案，就是一枚也不选

状态转移方程：

    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i])

    其中 dp[i - 1][j] 表示当前硬币不选，那么由 i - 1 种组成面值 j

    dp[i][j - coins[i]) 表示当前硬币选了，那么还需要组成面额为 j - coins[i], 这都是已要组成的面值大于当前硬币值为前提的。

因此可以先写出一个二维 dp 的代码，再进一步进行优化，状态压缩


 完全背包问题
 dp[i][j] 使用前i种硬币计算j分的表示法种数 令coins=[25, 10, 5, 1]
 dp[i][j] = dp[i-1][j-0*coins[i]] + dp[i-1][j-1*coins[i]] + dp[i-1][j-2*coins[i]] + ... dp[i-1][j-k*coins[i]]
 j >= k*coins[i]

 递推一下 dp[i][j]另j-conins[i]
 dp[i][j-1*coins[i]] = dp[i-1][j-coins[i]] + dp[i-1][j-2*coins[i]] + ... dp[i-1][j-k*coins[i]]

 dp[i][j] - dp[i][j-coins[i]] = dp[i-1][j]
 所以
 dp[i][j] = dp[i][j-coins[i]] + dp[i-1][j]

再优化为一维
*/

int waysToChange(int n){
 
    int coins[4] = {1,5,10,25};

    int dp[n+1]; //dp[i] 为组成i面额的硬币情况数
    for (int i = 1; i <= n; i++) 
        dp[i] = 0;

    dp[0] = 1;//组成0的硬币种类数为 1，（没有硬币也是一种情况）

    /*先遍历硬币，保证在考虑一枚硬币的情况时，没有较大的硬币影响，这样，我们最终每种组合情况，都是以硬币的面额大小非递减组合。保证了同样的情况，调换顺序后重复计算的情况。*/

    for(int i = 0; i < 4; i++) 
    {
        for(int j = coins[i]; j <= n; j++) 
        {
            dp[j] = (dp[j] + dp[j - coins[i]]) % 1000000007;
        }
    }

    return dp[n];
}

//------------------------------------------------------
/*
class Solution {
    /**
     * 方法 1 ： 二维 dp 比较直观的解法
     */
    public int waysToChange(int n) {
        int[] coins = new int[]{1, 5, 10, 25};
        int[][] dp = new int[5][n + 1];  // 一般多开一个位置，0 空着不用
        // base case
        for (int i = 1; i <= 4; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= n; j++) {
                // 下面👇这部分代码是可以进一步改写的，因为从状态转移方程里面可以看到都有 dp[i-1][j],
                // 因此可以直接不用判断就赋值给 dp[i][j]，判断后再加上『 选择当前硬币时 』的补偿值就可以了

                if (j - coins[i-1] < 0){                   // 要组成的面值比当前硬币金额小，该硬币不可以选择
                    dp[i][j] = dp[i - 1][j] % 1000000007;  // 只能由 i - 1 中硬币来组成面值 j
                } else {
                    // 当前硬币可以不选，也可以选择
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - coins[i-1]]) % 1000000007;
                }
            }
        }
        return dp[4][n];
    }

    /**
     * 方法 2 ： 进一步一维 dp ，从状态转移方程可以看出，dp[i][j] 仅仅和 dp[i-1]的状态有关，所以可以压缩为 1 维
     */
    public int waysToChange(int n) {
        int[] coins = new int[]{1, 5, 10, 25};
        int[] dp = new int[n + 1];
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = 1; i <= n; i++) {
                if (i - coin >= 0) {
                    dp[i] = (dp[i] + dp[i - coin]) % 1000000007;
                }
            }
        }
        return dp[n];
    }
}


作者：kelly2018
链接：https://leetcode-cn.com/problems/coin-lcci/solution/java-wan-quan-bei-bao-xiang-xi-ti-jie-yu-yi-bu-bu-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/
