#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* replaceSpace(char* s){
    int oglen = 0;
    int space_cnt = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    while(s[k] != '\0')
    {
        oglen++;
        if(s[k] == ' ')
        {
            space_cnt++;
        }
        k++;
    }
    
    int newlen = oglen + space_cnt*2 + 1;

    char *str = (char *)calloc(newlen,sizeof(char));
    if(str == NULL)
        return NULL;

    while(s[i] != '\0')
    {       
        if(s[i] == ' ')
        {
            str[j++] = '%';
            str[j++] = '2';
            str[j++] = '0';
        }
        else
        {
            str[j++] = s[i];           
        }
        i++;
    }
    str[j] = '\0';
    return str;

}




void main()
{
    char *ss = "we are happy.";
    puts(replaceSpace(ss));

}
