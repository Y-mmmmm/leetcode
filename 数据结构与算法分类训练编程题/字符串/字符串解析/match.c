#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    gets(s);
    
    int len = strlen(s);
    int spaceCnt = 0;
    int quotationCnt = 0;
    
    for(int i=0;i<len;i++)
    {
        if(s[i] == '"')
        {
            quotationCnt++;
            
        }
        if(s[i] == ' ' && quotationCnt%2 == 0)
        {
            spaceCnt++;
        }    
    }
    printf("%d\n",spaceCnt+1);
    
    quotationCnt = 0;
    for(int i=0;i<len;i++)
    {
        if(s[i] == '"')
        {
            quotationCnt++;
        }
        else if(s[i] == ' ' && quotationCnt%2 == 0)
        {
            printf("\n");
        }
        else
        {
            putchar(s[i]);
        }           
    }
    return 0;
    
}