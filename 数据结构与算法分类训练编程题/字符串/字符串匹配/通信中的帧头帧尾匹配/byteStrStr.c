 
#include <stdio.h>
 
typedef unsigned char uint8_t;
typedef unsigned int  uint16_t;

uint8_t Head[3] = {0x01,0x02,0x03};
uint8_t Buff[10] = {0x01,0x01,0x01,0x02,0x02,
                     0x01,0x02,0x03,0x02,0x02};
 
uint8_t* Bytestrstr(const uint8_t *s1 ,uint16_t len1, uint8_t *s2, uint16_t len2)
{
    uint16_t n;
    uint16_t cnt;

    if(*s2 != '\0' || len2 != 0) 
    {
        for(cnt = 0;cnt < len1;cnt ++)//len1结束了还没匹配到，直接返回空
        {
            for(n=0;*(s1+n)==*(s2+n);n++)
            {
                if(n == (len2-1)) //s2结束了
                    return (uint8_t*)s1;
            }
            s1++;
        }
        return NULL;
    }
    else
        return (char*)s1;
}

int main(int argc, char *argv[]) {

    printf("  %d\n",Bytestrstr(Buff,10,Head,3) - Buff);
    printf("\n");
    return 0;
}
