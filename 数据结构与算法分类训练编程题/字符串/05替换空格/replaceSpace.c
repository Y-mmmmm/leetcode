#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//双指针法
char* replaceSpace1(char* s)
{
    char* ch = (char *)malloc(sizeof(char) * 100000);//也浪费啊

    char string[4] = "%20"; 
    char* tmp = s;

    ch[0] = '\0';
    for(int i = 0; s[i] != '\0'; i++) 
    {
        if(s[i] != ' ') 
            continue;
        s[i] = '\0';
        strcat(ch, tmp);
        strcat(ch, string);
        tmp = s + i + 1;
    }
    strcat(ch, tmp);
    return ch;
}

//先calloc一个当前s如果全为空格的最大字符串，遍历s，如果是空格就依次输入%20，是其他数组就输入s本身，返回该字符串。
char* replaceSpace2(char* s)
{
    char *returned=calloc(strlen(s)*3+1,sizeof(char));
    int i=0,k=0;
    while(s[i]!='\0')
    {
        if(s[i]==' ')
        {
            returned[k++]='%';
            returned[k++]='2';
            returned[k++]='0';
            i++;
        }
        else
        {
            returned[k++]=s[i];
            i++;
        }
    }
    return returned;
}


char* replaceSpace3(char* s)
{
    if(s == NULL) 
    {
        return NULL;
    }

    int i, j, s_len = strlen(s), space_count = 0;
    char *ret;
    
    for(i = 0; i < s_len; i++) 
    {
        if(s[i] == ' ') 
        {
            space_count ++; //计算空格长度
        } 
    }

    ret = (char *)malloc(s_len + 1 + space_count * 2);
    if(ret == NULL) 
    {
        return NULL;
    }

    for(i = 0, j = 0; i < s_len; i++) 
    {
        if(s[i] == ' ') 
        {
            ret[j++] = '%';
            ret[j++] = '2';
            ret[j++] = '0';
        } else 
        {
            ret[j++] = s[i];
        }
    }
    ret[j] = 0;

    return ret;
}


char* replaceSpace4(char* s)
{
    if(s == NULL)return NULL;
    
    char pStr[10000] = {0}; //静态分配，效率低，浪费大
    char *pNewStr = pStr;   //标记字符串首地址
    int i = 0;
    while(*s != '\0')
    {
        pStr[i] = *s;
        if(*s == ' ')
        {
            //遇到空格，申请空间
            pStr[i] = '%';
            i++;
            pStr[i] = '2';
            i++;
            pStr[i] = '0';
            i++;
            s++;

        }
        else
        {
            i++;
            s++;
        }
       
       
    }
    return pNewStr;
}

//题目中给定的字符串长度默认为strlen(s)+1，最后一个字符为'\0'，但通常不会写在题目里；
//动态开辟字符指针存放字符串时，需要多开辟一个字符的空间，用来存放'\0'。

char* replaceSpace5(char* s)
{
    int i = 0, a = 0, b = 0, len = strlen(s), n = 0, tmp = 0; //在strlen求字符串时，与下面找空格个数代码重复了，可以合并
    for (i = 0; i < len; i++) 
    {
        if (s[i] == ' ') 
        {
            n++;
        }
    }
    char *res = NULL;
    res = malloc(sizeof(char) * (len + 2 * n + 1));
    memset(res, 0, sizeof(char) * (len + 2 * n + 1));
    for (i = 0; i < len + 1; i++) 
    {
        if (s[i] == ' ' || s[i] == '\0') 
        {
            memcpy(&res[b], &s[a], i - a);
            if (s[i] == ' ') 
            {
                memcpy(&res[b + i - a], "%20", 3);
            }
            tmp++;
            a = i + 1;
            b = a + 2 * tmp;
        }
    }
    return res;
}



//官方思路：在原序列倒序复制
//本地运行失败，不知道为什么
char* replaceSpace6(char* s)
{
    if(s==NULL)
        return 0;
    int originalLength=0;
    int numberOfBlank=0;
    int i=0;
    while(s[i]!='\0')
    {   
        originalLength++;
        if(s[i]==' ')
        {
            numberOfBlank++;
        }      
        i++;
    }
    int newLength = originalLength+2*numberOfBlank; //空格*2而不是*3的原因在于原来的空格就占了1个，替换后再增加2个就行了

    int p = originalLength;
    int q = newLength;
    s=(char*)realloc(s,sizeof(char)*(q+1));//realloc 重新分配内存，+1的目的在于添加一个'\0'

    while(p>=0 && q>p)
    {
        if(s[p]==' ')
        {
            s[q--]='0';
            s[q--]='2';
            s[q--]='%';
      
        }
        else s[q--]=s[p];
        p--;  
    } 
    return s;
}


void main()
{
    char *ss = "we are happy.";
//    printf("%s\n",replaceSpace1(ss));//false
 //   printf("%s\n",replaceSpace2(ss));
 //   printf("%s\n",replaceSpace3(ss));
 //   printf("%s\n",replaceSpace4(ss));
//    printf("%s\n",replaceSpace5(ss));

 //   printf("%s\n",replaceSpace6(ss)); //false
    
}

