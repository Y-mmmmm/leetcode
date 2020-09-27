#include <stdio.h>




void *my_memcpy(void *dest,void *src,int n)
{
    if(dest == NULL || src == NULL || n <= 0)   return NULL;
    int wordSize = n/4;
    int restSize = n%4;

    int *pdest = (int *)dest;
    int *psrc = (int *)src;

    while(wordSize--)   *pdest++ = *psrc++;
    while(restSize--)   *((char *)pdest++) = *((char *)psrc++);

    return dest;

}
