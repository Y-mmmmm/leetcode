#include <stdio.h>



#define mal(x,y) (x*y)
int main()
{
    int i = 3;
    int a;
    char **b[5][6];//二维指针数组，5*6*8=240，64位指针8字节（也有人认为为了兼容32位，这里设置为4字节）

    a = mal(i++, sizeof(b) + 5);//a = i++ * sizeof(b) + 5 = 3*240 +5 =725 ;注意，这里i++先是3参与运算后再自增，宏展开并不是原本的意思

    printf("%d", a);
    return 0;
}

