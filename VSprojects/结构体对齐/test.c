#include <stdio.h> 

/*

结构体对齐测试
1.编译器默认优化，以字节最大的进行对齐
2.可以指定对齐方式
3.可以取校编译器优化

*/


#pragma pack(1)
typedef struct S1 
{
    int i:8;
    char j:4;
    int a:4;
    double b; 
}S1_t;
#pragma pack()


typedef struct S2 
{
    int i:8;
    char j:4;
    double b;
    int a:4;
}__attribute__((packed)) S2_t; //取消编译器优化对齐



typedef struct S3 
{
    int i;    
    char j;    
    double b;    
    int a; 
}__attribute__((aligned(4))) S3_t;

int main() 
{
    S1_t s1;
    S2_t s2;
    S3_t s3;
    printf("%d\n",sizeof(s1)); //17 ，1字节对齐了

    //24，不对其的话，以最大元素对齐，4+4+8+8，其中char要占4字节和int合并正好和double对齐，但是后面的int也要和double对齐
    //取校对齐就是17
    printf("%d\n",sizeof(s2)); 

    printf("%d\n",sizeof(s3)); //24  
    return 0; 
}
