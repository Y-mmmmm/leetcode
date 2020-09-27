/*
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

 
示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"

提示：

    0 <= num < 231

*/

int translateNum(int num){
    if(num <10) return 1; //递归出口

    if(num%100 >9 && num%100 <26)
        return translateNum(num/10)+translateNum(num/100);
    else
        return translateNum(num/10);
}



//递归
int f(int num)
{
    if (num < 10)   return 1;//单个数字，直接计数1
        
    if (num % 100 < 26 && num % 100 > 9) //因为最多只能两位数翻译，所以直接对%100即可
        return f(num / 10) + f(num / 100); //如果数字在10-25之间，可以单个翻译也可以两个一起翻译
     else         
        return f(num / 10);//超出10-25只能拆开翻译
        
}

int translateNum(int num)
{
    if (num == 0)   return 1;
        
    return f(num);
}

//动态规划

int translateNum(int num)
{
    char str[20];
    
    int len = sprintf(str,"%d",num);

    if(len < 2) 
        return len;

    int dp[len+1];//表示前 i 个数字的翻译方法数
    dp[1] = 1;
    dp[0] = 1;
    for(int i = 2;i <= len;i++)
    {
        if(str[i-2] == '1' || (str[i-2] == '2' && str[i-1] <= '5')) 
            dp[i] = dp[i-2] + dp[i-1];//和前面的数一起翻译，前提是组合数在10-25之间
        else 
            dp[i] = dp[i-1];//只翻译自己
    }
        return dp[len];
}


