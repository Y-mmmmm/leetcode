## DP题目集合

DP题目集合 && 解题报告

    DP 

简单dp

    递推
    
    hdu 2084 数塔 简单从上往下递推
    Gym - 101875E 滚动数组  https://blog.csdn.net/castomere/article/details/97630052
    Gym - 101201B https://blog.csdn.net/castomere/article/details/97773403
    hdu 2018 母牛的故事 简单递推计数
    hdu 2044 一只小蜜蜂... 简单递推计数（Fibonacci）
    hdu 2041 超级楼梯 Fibonacci
    hdu 2050 折线分割平面 找递推公式
    CF 429B B.Working out 四个角递推
    zoj 3747 Attack on Titans 带限制条件的计数递推dp
    uva 10328 Coin Toss 同上题
    hdu 4747 Mex 
    hdu 4489 The King's Ups and Downs
    hdu 4054 Number String
    
    背包
    
    hdu 2955 Robberies 01背包
    hdu 1864 最大报销额 01背包
    hdu 2602 Bone Collector 01背包
    hdu 2844 Coins 多重背包
    hdu 2159 FATE 完全背包
    woj 1537 A Stone-I  转化成背包
    woj 1538 B Stone-II 转化成背包
    poj 1170 Shopping Offers 状压+背包
    zoj 3769 Diablo III 带限制条件的背包
    zoj 3638 Fruit Ninja 背包的转化成组合数学
    hdu 3092 Least common multiple 转化成完全背包问题
    poj 1015 Jury Compromise 扩大区间+输出路径
    poj 1112 Team Them UP 图论+背包
    
    LIS最长上升子序列
    
    hdu 1003 Max Sum
    hdu 1087 Super Jumping!
    uva 10635 Prince and Princess LCS转化成LIS
    hdu 4352 XHXJ's LIS　数位dp+LIS思想
    srm div2 1000  状态压缩+LIS
    poj 1239 Increasing Sequence 两次dp
    
    LCS最长公共子序列
    
    hdu 1159 Common Subsequence
    uva 111 History Grading 要先排个序
    poj 1080 Human Gene Functions

区间dp

    通常是将区间二分，左右区间再合并
    poj 1141 Brackets Sequence 括号匹配并输出方案
    hdu 4745 Two Rabbits 转化成求回文串 
    zoj 3541 The Last Puzzle  贪心+区间dp
    poj 2955 Brackets
    hdu 4283 You Are the One  常见写法
    hdu 2476 String Printer 
    zoj 3537 Cake
    CF 149D Coloring Brackets
    zoj 3469 Food Delivery

树形dp

    从根节点 到 叶子节点， 或者叶子节点到根节点
    hdu 4123 Bob's Race 二分+树形dp+单调队列
    hdu 4514  求树的直径
    poj 1655 Balancing Act 
    hdu 4714 Tree2Cycle 思维
    hdu 4616 Game
    hdu 4126 Genghis Kehan the Conqueror MST+树形dp 比较经典
    hdu 3660 Alice and Bob's Trip 有点像对抗搜索
    CF 337D Book of Evil  树直径的思想 思维
    hdu 2196 Computer 搜两遍

数位dp

    主要用来解决统计满足某类特殊关系或有某些特点的区间内的数的个数，
    它是按位来进行计数统计的，可以保存子状态，速度较快
    数位dp做多了后，套路基本上都差不多，关键把要保存的状态给抽象出来，保存下来。
    HDU - 3555 和 HDU - 3652 两个模板题https://blog.csdn.net/castomere/article/details/98049786
    hdu 2089 不要62 简单数位dp
    hdu 3709 Balanced Number 比较简单
    CF 401D Roman and Numbers 状压+数位dp
    hdu 4398 X mod f(x) 把模数加进状态里面
    hdu 4734 F(x)  简单数位dp
    hdu 3693 Math teacher's homework 思维变换的数位dp
    hdu 4352 XHXJ's LIS　数位dp+LIS思想
    CF 55D Beautiful Numbers  比较巧妙的数位dp
    hdu 3565 Bi-peak Numbers 比较难想
    CF 258B Little Elephant and Elections 数位dp+组合数学+逆元

[概率] or [期望] dp

    一般来说概率正着推，期望逆着推。
    有环的一般要用到高斯消元解方程。
    期望可以分解成多个子期望的加权和，权为子期望发生的概率，即 E(aA+bB+...) = aE(A) + bE(B) +... 
    ural 1776 Anniversiry Firework 比较基础
    hdu 4418 Time travel  比较经典BFS+概率dp+高斯消元
    hdu 4586 Play the Dice 推公式比较水
    hdu 4487 Maximum Random Walk 
    jobdu 1546 迷宫问题 高斯消元+概率dp+BFS预处理
    hdu 3853 LOOPS 简单概率dp
    hdu 4405 Aeroplane chess 简单概率dp,比较直接
    hdu 4089 Activation 比较经典
    poj 2096 Collecting Bugs 题目比较难读懂
    hdu 4034 Maze 经典好题，借助树的概率dp
    hdu 4336 Card Collector 状态压缩+概率dp
    hdu 4326 Game  这个题状态有点难抽象

状态压缩dp

    TSP ， 插头dp
    HDU - 1074 https://blog.csdn.net/castomere/article/details/98085737
    hdu 1693 Eat the Trees  插头dp
    hdu 4568 Hunter 最短路+TSP
    hdu 4539  插头dp
    hdu 4529 状压dp
    poj 1185 炮兵阵地
    poj 2411 Mandriann's Dream 轮廓线dp
    hdu 3811 Permutation
    poj 1038
    poj 2441
    hdu 2167
    hdu 4026
    hdu 4281

二进制优化

    主要优化背包问题
    hdu 1059 Diving 
    hdu 1171 Big Event in Hdu
    poj 1048 Follow My Magic

单调队列优化

    hdu 3401 Trade  
    poj 3245 Sequece Partitioning 二分+单调队列优化

斜率优化

    hdu 3507 Print Article
    poj 1260 Pearls
    hdu 2829 Lawrence
    hdu 2993 Max Average Problem

四边不等式优化

    hdu 2952 Counting Sheep
    poj 1160 Post Office
    hdu 3480 Division
    hdu 3516 Tree Construction
    hdu 2829 Lawrence