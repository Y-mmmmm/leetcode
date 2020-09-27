#include <stdio.h>
#include <string.h>

int mp3_player(int n,char *cmd)
{
    int len = strlen(cmd);
    int cursor = 1;
    int pageTop = 1;
    int pageBotton = 0;
   
    //歌曲小于4
    if(n <= 4)
    {
        pageTop = 1;
        pageBotton = n; //页面就显示n个

        for(int i=0;i<len;i++)
        {
            if(cmd[i] == 'U')
            {
                if(cursor == 1)    cursor = n;//光标在第一首歌时，摁up，光标直接跳转到最后一首n
                else    cursor--; //否则直接向上
            }
            else if(cmd[i] == 'D')
            {
                if(cursor == n)    cursor = 1;//光标在最后一首歌时，摁down，光标直接跳转到第一首
                else    cursor++;//否则直接向下
            }
        }
    }
    else //歌曲大于4
    {
        pageTop = 1;
        pageBotton = 4; //初始化当前窗口
        for(int i=0;i<len;i++)
        {    
            if(cmd[i] == 'U')
            {
                if(cursor == 1) //特殊翻页，当前光标在第一首，摁up时，光标切换到最后一首n，同时页面窗口也要更新
                {
                    cursor = n;
                    pageBotton = n;
                    pageTop = pageBotton-3;
                }
                else if(cursor == pageTop)//当前光标在窗口顶部，向上翻页时窗口也要减
                {
                    cursor--;
                    pageTop--;
                    pageBotton--;
                }
                else //普通翻页，当前光标在窗口内，直接向上，页面窗口不用更新
                {
                    cursor--;
                }
            }
            else if(cmd[i] == 'D')
            {
                if(cursor == n) //特殊翻页，当前光标在第n首，摁down，光标切换到第一首，页面窗口也更新
                {
                    cursor = 1;
                    pageTop = 1;
                    pageBotton = pageTop+3;
                }
                else if(cursor == pageBotton)//当前光标在窗口底部，向下翻页时窗口也要减
                {
                    cursor++;
                    pageTop++;
                    pageBotton++;
                }
                else //普通翻页，当前光标在窗口内，直接向下，窗口不用刷新
                {
                    cursor++;
                }
            }
        }
        
    }
    //更新窗口
    for(int i=pageTop;i<pageBotton;i++)
        printf("%d ",i);
    printf("%d\n",pageBotton);
    
    return cursor;
}


int main()
{
    int n;
    char CMD[1000];
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s",CMD);
        
        int song = mp3_player(n,CMD);
        
        printf("%d\n",song);
    }
    return 0;
}
