#include "stdio.h"
#include "stdbool.h"

struct boolStr{
 char bit0:1;
 char bit1:1;
 char bit2:1;
 char bit3:1;
 char bit4:1;
 char bit5:1;
 char bit6:1;
 char bit7:1;  //一共声明了8个位段，每个位段1bit，就是位宽1
};

int main(void)
{
 struct boolStr bitStr;

 char temp = 0;

 bitStr.bit0 = 1;
 bitStr.bit4 = 1; //位操作

 temp = *(char *)&bitStr; //取结构体地址强制转换为char指针再取值，类似STM32库函数的操作

 printf("size:%d %d\n",sizeof(bitStr),sizeof(temp));
 printf("temp:%#x\n",temp);

 return (0);

} 

