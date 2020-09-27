#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int isLeapYear(int year)
{
    if((year%4 == 0 && year%100 != 0)|| year%400 == 0)
        return 1;
    else
        return 0;   
}

int whitchDay(int year,int month,int day)
{
    int leapMonth = 28 + isLeapYear(year);

    int res = 0;
    switch(month)
    {
        case 1:
            res = day;
            break;
        case 2:
            res = 31 + day;
            break;
        case 3:
            res = leapMonth + 31 + day;
            break;
        case 4:
            res = leapMonth + 62 + day;
            break;
        case 5:
            res = leapMonth + 92 + day;
            break;
        case 6:
            res = leapMonth + 123 + day;
            break;
        case 7:
            res = leapMonth + 153 + day;
            break;
        case 8:
            res = leapMonth + 184 + day;
            break;
        case 9:
            res = leapMonth + 215 + day;
            break;
        case 10:
            res = leapMonth + 245 + day;
            break;
        case 11:
            res = leapMonth + 276 + day;
            break;
        case 12:
            res = leapMonth + 306 + day;
            break;
        default:
            break;
    }
    
    return res;
}


int main()
{
    char s[20];
    while(gets(s))
    {

        int year = 0;
        int month = 0;
        int day = 0;
        
        int yearPos = 0;
        while(s[yearPos] != ' ')
        {
             year = year *10 + (s[yearPos]-0x30);
             yearPos++;
             
        }
        int monPos = yearPos+1;
        while(s[monPos]!=' ')
        {
            month = month *10 + (s[monPos]-0x30);
            monPos++;
        }
        int dayPos = monPos+1;
        while(s[dayPos]!='\0')
        {
            day = day *10 + (s[dayPos]-0x30);
            dayPos++;
        }

        printf("%d %d %d\n",year,month,day);

        printf("%d\n",whitchDay(year,month,day));
    }
    return 0;
}

