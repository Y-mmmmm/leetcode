#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


//字符串转十六进制
void StrToHex(char *pbDest, char *pbSrc, int nLen)
{
  char h1,h2;
  char s1,s2;
  int i;

    for (i=0; i<nLen/2; i++)
    {
        h1 = pbSrc[2*i];
        h2 = pbSrc[2*i+1];

        s1 = toupper(h1) - 0x30; //toupper 转换为大写字母
        if (s1 > 9)
            s1 -= 7;
        s2 = toupper(h2) - 0x30;
        if (s2 > 9)
            s2 -= 7;

        pbDest[i] = s1*16 + s2;
    }
}

//十六进制转字符串
void HexToStr(char *pszDest, char *pbSrc, int nLen)
{
    char    ddl, ddh;
    for (int i = 0; i < nLen; i++)
    {
        ddh = 48 + pbSrc[i] / 16;
        ddl = 48 + pbSrc[i] % 16;
        if (ddh > 57) ddh = ddh + 7;
        if (ddl > 57) ddl = ddl + 7;
        pszDest[i * 2] = ddh;
        pszDest[i * 2 + 1] = ddl;
    }
    pszDest[nLen * 2] = '\0';
}

uint16_t Hex2StringArray (uint8_t *pSrc,  uint16_t SrcLen, uint8_t *pObj)
{
    uint16_t i=0;

    for(i=0;    i<SrcLen;   i++)
    {
        sprintf((char *)(pObj + i * 2), "%02X", *(pSrc + i));
    }
    *(pObj + i * 2) = '\0';
    return  (i * 2);
}


//字符串转十进制 带负号
int my_atoi(const char *str)
{
    int value = 0;
    int flag = 1; //判断符号
    while (*str == ' ')  //跳过字符串前面的空格
    {
        str++;
    }
    if (*str == '-')  //第一个字符若是‘-’，说明可能是负数
    {
        flag = 0;
        str++;
    }
    else if (*str == '+') //第一个字符若是‘+’，说明可能是正数
    {
        flag = 1;
        str++;
    }//第一个字符若不是‘+’‘-’也不是数字字符，直接返回0
    else if (*str >= '9' || *str <= '0') 
    {
        return 0;    
    }
    //当遇到非数字字符或遇到‘\0’时，结束转化
    while (*str != '\0' && *str <= '9' && *str >= '0')
    {
        value = value * 10 + *str - '0'; //将数字字符转为对应的整形数
        str++;
    }
    if (flag == 0) //负数的情况
    {
        value = -value;
    }
    return value;
}
//不带负号
void StrtoDec(uint32_t *pbDest, char *pbSrc, int nLen)
{
    int i;
    int tmp=0;
    if(nLen > 10)
        *pbDest = 0;
    tmp = 1;
    *pbDest = 0;
    for (i=nLen-1; i>=0; i--)
    {
        *pbDest += tmp*(*(pbSrc+i)-'0');
        tmp = tmp*10;
    }
}


//带浮点数

//m^n函数
//返回值:m^n次方.
uint32_t NMEA_Pow(uint8_t m,uint8_t n)
{
    uint32_t result=1;    
    while(n--)result*=m;    
    return result;
}
//str转换为数字,以','或者'*'结束
//buf:数字存储区
//dx:小数点位数,返回给调用函数
//返回值:转换后的数值
int NMEA_Str2num(uint8_t *buf,uint8_t*dx)
{
    uint8_t *p=buf;
    uint32_t ires=0,fres=0;
    uint8_t ilen=0,flen=0,i;
    uint8_t mask=0;
    int res;
    while(1) //得到整数和小数的长度
    {
        if(*p=='-'){mask|=0X02;p++;}//是负数
        if(*p==','||(*p=='*'))break;//遇到结束了
        if(*p=='.'){mask|=0X01;p++;}//遇到小数点了
        else if(*p>'9'||(*p<'0'))   //有非法字符
        {   
            ilen=0;
            flen=0;
            break;
        }   
        if(mask&0X01)flen++;
        else ilen++;
        p++;
    }
    if(mask&0X02)buf++; //去掉负号
    for(i=0;i<ilen;i++) //得到整数部分数据
    {  
        ires+=NMEA_Pow(10,ilen-1-i)*(buf[i]-'0');
    }
    if(flen>5)flen=5;   //最多取5位小数
    *dx=flen;           //小数点位数
    for(i=0;i<flen;i++) //得到小数部分数据
    {  
        fres+=NMEA_Pow(10,flen-1-i)*(buf[ilen+1+i]-'0');
    } 
    res=ires*NMEA_Pow(10,flen)+fres;
    if(mask&0X02)res=-res;         
    return res;
} 

//十进制转字符串
uint16_t DectoStr (uint8_t *pSrc, uint16_t SrcLen, uint8_t *pObj)
{
    uint16_t i=0;

    for(i=0;    i<SrcLen;   i++)
    {
        sprintf((char *)(pObj + i * 2), "%02d", *(pSrc + i));
    }
    *(pObj + i * 2) = '\0';
    return  (i * 2);
}


//将u32数转换成u8数组
void U32ToU8Array(uint8_t *buf, uint32_t u32Value)
{
    buf[0] = ((u32Value >> 24) & 0xFF);
    buf[1] = ((u32Value >> 16) & 0xFF);
    buf[2] = ((u32Value >> 8) & 0xFF);
    buf[3] = (u32Value & 0xFF);
}

//u8数组转u32
void U8ArrayToU32(uint8_t *buf, uint32_t *u32Value)
{
    *u32Value = (buf[0] <<24) + (buf[1] <<16) + (buf[2] <<8) + (buf[3] <<0);
}

//大小端转换


//为大端：
pPack[0] = (uint8_t)((x >> 8) & 0xFF);
pPack[1] = (uint8_t)(x & 0xFF);

//为小端：
pPack[0] = (uint8_t)(x & 0xFF);
pPack[1] =  (uint8_t)((x >> 8) & 0xFF);
