/*
你有一个 n x 3 的网格图 grid ，你需要用 红，黄，绿 三种颜色之一给每一个格子上色，且确保相邻格子颜色不同（也就是有相同水平边或者垂直边的格子颜色不同）。

给你网格图的行数 n 。

请你返回给 grid 涂色的方案数。由于答案可能会非常大，请你返回答案对 10^9 + 7 取余的结果。


示例 1：

输入：n = 1
输出：12
解释：总共有 12 种可行的方法 //双色组合有6种,ABC三色:ABA,ACA,BAB,BCB,CAC,CBC //三色组合有6种,ABC三色:ABC,ACB,BAC,BCA,CAB,CBA

示例 2：

输入：n = 2
输出：54

示例 3：

输入：n = 3
输出：246

示例 4：

输入：n = 7
输出：106494

示例 5：

输入：n = 5000
输出：30228214

*/

/*
每一行分为 ABA(使用AB两种颜色) 和 ABC(使用三种颜色) 这样的两种情况，且仅有这两种情况

第 i - 1 行是 ABC 类，第 i 行是 ABC 类：以 ABC 为例，那么第 i 行只能是 BCA 或 CAB，方案数为 2；
                     第 i 行是 ABA 类：以 ABC 为例，那么第 i 行只能是 BAB 或 BCB，方案数为 2；

第 i - 1 行是 ABA 类，第 i 行是 ABC 类：以 ABA 为例，那么第 i 行只能是 BAC 或 CAB，方案数为 2；
                     第 i 行是 ABA 类：以 ABA 为例，那么第 i 行只能是 BAB，BCB 或 CAC，方案数为 3;

dp数组中dp[i][0]存当前行双色数量 dp[i][1]存当前行三色数量 因此有如下公式：
dp[i][0] = dp[i-1][0]*3 + dp[i-1][1]*2;
dp[i][1] = dp[i-1][0]*2 + dp[i-1][1]*2;

第一行有6种三色 6种双色 作为初始行

*/
/*
int numOfWays(int n){
    if(n < 1)   return 0;
    if(n == 1)  return 12;

    int mod = 1000000007;
    
    long dp[n][2];// dp[][0]表示双色情况,dp[][1]表示三色情况

    dp[0][0] = 6; //双色组合有6种,ABC三色:ABA,ACA,BAB,BCB,CAC,CBC
    dp[0][1] = 6; //三色组合有6种,ABC三色:ABC,ACB,BAC,BCA,CAB,CBA

    for(int i=1;i<n;i++)
    {
        dp[i][0] = (dp[i-1][0]*3 + dp[i-1][1]*2)%mod;
        dp[i][1] = (dp[i-1][0]*2 + dp[i-1][1]*2)%mod;
    }
    return (int) ((dp[n-1][0]+dp[n-1][1])%mod);
}
*/

int numOfWays(int n){

    if(n < 1)   return 0;
    if(n == 1)  return 12;

    int mod = 1000000007;

    int dpi0 = 6, dpi1 = 6;
    for (int i=2; i<=n;i++) 
    {
        int new_dpi0 = (3LL * dpi0 + 2LL * dpi1) % mod;
        int new_dpi1 = (2LL * dpi0 + 2LL * dpi1) % mod; //注意！LL不能丢，表示longlong
        dpi0 = new_dpi0;
        dpi1 = new_dpi1;
    }
    return (dpi0 + dpi1) % mod;
}

int numOfWays(int n){
    if(n < 1)   return 0;
    if(n == 1)   return 12;

    int ABA = 6;
    int ABC = 6;

    for(int i=2;i<=n;i++)
    {
        int new_ABA = (ABA * 3LL + ABC * 2LL)%1000000007;
        int new_ABC = (ABA * 2LL + ABC * 2LL)%1000000007;
        ABA = new_ABA;
        ABC = new_ABC;
    }

    return (ABA + ABC)%1000000007;
}
