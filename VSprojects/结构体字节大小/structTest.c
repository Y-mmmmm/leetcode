#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



typedef struct test1
{
    uint16_t a;
    uint16_t b;
    uint32_t c;
}S1_t;

typedef struct test2
{
    S1_t s1; //8
    char a;  //4 ->以模数对齐
    uint32_t b; //4  
    uint32_t c; //4
    uint32_t d; //4
    //uint32_t *p; //8

}S2_t;

typedef struct S3   
{
    char a; //2
    short b; //2
    char c; //4 
    int d; //4
    char e;   //4 
}S3_t; 

typedef struct 
{ 
    int a; //4
    char b; //4   
}S4_t; 
typedef struct
{    
    S4_t a;//8
    char b;//4  ->以模数对齐
}S41_t;

typedef struct
{ 
    short a; //2
    char b;  //2  
}S5_t;
typedef struct    
{       
    S5_t a; //4
    char b;//2   ->以模数对齐
}S51_t; 
  

typedef struct    
{ 
    int e_int1; //4
    union        
    { 
        char ue_chars[9]; 
        int ue_int;        
    }u; //12 

    double e_double; //8
    int e_int2;    //8  ->以模数对齐
}SU2;





#define ENDIANNESS ((char)endian_test.l)

int main()
{
    S2_t s2;
    S3_t s3;
    S41_t s4;
    S51_t s5;
    SU2 su;

    static union 
    { 
        char c[4]; 
        unsigned long l;     
    }endian_test = { { 'l', '?', '?', 'b' } };

    printf("ENDIANNESS: %c\n", ENDIANNESS);

    printf("%d\n",sizeof(s2));//24
    printf("%d\n",sizeof(s3));//16
    printf("%d\n",sizeof(s4));//12
    printf("%d\n",sizeof(s5));//6
    printf("%d\n",sizeof(su));//32

    return 0;
}
