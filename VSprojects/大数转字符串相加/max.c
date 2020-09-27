#include <stdio.h>
#include <string.h>


/*
 在计算机中，由于处理器位宽限制，只能处理有限精度的十进制整数加减法，比如在32位宽处理器计算机中，
参与运算的操作数和结果必须在-2^31~2^31-1之间。如果需要进行更大范围的十进制整数加法，需要使用特殊
的方式实现，比如使用字符串保存操作数和结果，采取逐位运算的方式。如下：
9876543210 + 1234567890 = ?
让字符串 num1="9876543210"，字符串 num2="1234567890"，结果保存在字符串 result = "11111111100"。
-9876543210 + (-1234567890) = ?
让字符串 num1="-9876543210"，字符串 num2="-1234567890"，结果保存在字符串 result = "-11111111100"。



要求编程实现上述高精度的十进制加法。
要求实现方法：
public String add (String num1, String num2)
【输入】num1：字符串形式操作数1，如果操作数为负，则num1的前缀为符号位'-'
num2：字符串形式操作数2，如果操作数为负，则num2的前缀为符号位'-'
【返回】保存加法计算结果字符串，如果结果为负，则字符串的前缀为'-'
注：
(1)当输入为正数时，'+'不会出现在输入字符串中；当输入为负数时，'-'会出现在输入字符串中，且一定在输入字符串最左边位置；
(2)输入字符串所有位均代表有效数字，即不存在由'0'开始的输入字符串，比如"0012", "-0012"不会出现；
(3)要求输出字符串所有位均为有效数字，结果为正或0时'+'不出现在输出字符串，结果为负时输出字符串最左边位置为'-'。 
*/






int add(char *s1,char *s2,char *sum)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int carry = 0;
    
    int num1[1000] = {0};
    int num2[1000] = {0};
    
    int flag1 = 1;
    int flag2 = 1;
    
    int i,j;
    for(i=0;i<len1;i++)    
        num1[i] = s1[len1-1-i] - '0';
    if(s1[0] == '-')
    {
        num1[len1-1] = 0;
        flag1 = -1;
    }
    for(j=0;j<len2;j++)    
        num2[j] = s2[len2-1-j] - '0';
    if(s2[0] == '-')
    {
        num2[len2-1] = 0;
        flag2 = -1;
    }   
    
    int maxlen = len1>len2 ? len1:len2;
    int res = 0;
    int cnt = 0;
    for(i=0;i<maxlen;i++)
    {
        sum[cnt++] = (num1[i]+num2[i]+carry)%10 + '0';
        carry = (num1[i]+num2[i]+carry)>9?1:0;
    }
    if(carry == 1)
    {
        sum[cnt++] = '1';
    }
    
    if((flag1 == -1 && flag2 != -1)||(flag1 != -1 && flag2 == -1))
    {
        sum[cnt++] = '-';
    }
    
    return cnt;

}

int main()
{
    char s1[1000];
    char s2[1000];
    char sum[1005];
    while(scanf("%s",s1)!=EOF)
    {
        scanf("%s",s2);
        int len = add(s1,s2,sum);
        
        for(int i=0;i<len;i++)
        {
            printf("%c",sum[len-1-i]);
        }
        printf("\n");
    }
    return 0;
}

