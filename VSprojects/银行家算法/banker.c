#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>
 
#include "banker.h"

#define PRONUM 80	//进程的最大数目
#define RESNUM 80	//资源的最大数目
#define RESLEN 80	//资源名的最大数目


//进程已分配资源量
typedef struct Max_Allocation
{
	char    proName[PRONUM];    //进程名
	int     iMax[RESNUM];       //最大需求量
	int     iAllocation[RESNUM];//进程已分配资源量
	int     need[RESNUM];       //需求量
}Max_Allocation;

struct course
{
	Max_Allocation	res;    //资源需求与分配信息
	int				finish; //是否访问的标志。（0未访问，1已经访问）
};


char    resName[RESNUM][RESLEN];    //资源名
int     work[RESNUM];               //可用资源数
int     request[RESNUM]={0};        //请求资源
char    safe_Array[RESNUM][RESLEN]; //资源名
int     available[RESNUM];          //可用资源
struct  course progress[80]; 

void health_Examination(int proNum, int resNum)
{
    return; 
}
 
///
//此处仅供调试方便
//
void test()
{
    progress[0].res.iMax[0] = 7;
	progress[0].res.iMax[1] = 5;
	progress[0].res.iMax[2] = 3;
	progress[0].res.iAllocation[0] = 0;
	progress[0].res.iAllocation[1] = 1;
	progress[0].res.iAllocation[2] = 0;
 
	progress[1].res.iMax[0] = 3;
	progress[1].res.iMax[1] = 2;
	progress[1].res.iMax[2] = 2;
	progress[1].res.iAllocation[0] = 2;
	progress[1].res.iAllocation[1] = 0;
	progress[1].res.iAllocation[2] = 0;
 
	progress[2].res.iMax[0] = 9;
	progress[2].res.iMax[1] = 0;
	progress[2].res.iMax[2] = 2;
	progress[2].res.iAllocation[0] = 3;
	progress[2].res.iAllocation[1] = 0;
	progress[2].res.iAllocation[2] = 2;
 
	progress[3].res.iMax[0] = 2;
	progress[3].res.iMax[1] = 2;
	progress[3].res.iMax[2] = 2;
	progress[3].res.iAllocation[0] = 2;
	progress[3].res.iAllocation[1] = 1;
	progress[3].res.iAllocation[2] = 1;
 
	progress[4].res.iMax[0] = 4;
	progress[4].res.iMax[1] = 3;
	progress[4].res.iMax[2] = 3;
	progress[4].res.iAllocation[0] = 0;
	progress[4].res.iAllocation[1] = 0;
	progress[4].res.iAllocation[2] = 2;
 
	strcpy(progress[0].res.proName, "P0");
	strcpy(progress[1].res.proName, "P1");
	strcpy(progress[2].res.proName, "P2");
	strcpy(progress[3].res.proName, "P3");
	strcpy(progress[4].res.proName, "P4");
 
	strcpy(resName[0], "A");
	strcpy(resName[1], "B");
	strcpy(resName[2], "C");
}

//访问标志初始化
void init_Flag(int proNum, int resNum) 
{
	int i = 0;
	for(i=0; i<proNum; i++)
    {
		progress[i].finish = 0;
	}
	return;
}


//初始化资源
void init_Resource(int proNum, int resNum)
{
    int i = 0, j = 0;
	for(i=0; i<proNum; i++)
    {
		for(j=0; j<resNum; j++)
        {
			progress[i].res.iMax[j] = 0;          //最大需求量，初始化为0
			progress[i].res.iAllocation[j] = 0;   //进程已分配资源量，初始化为0
		}
	}
	return;
}

//初始化需求量
void init_Need(int proNum, int resNum)
{
    int i = 0, j = 0;
	for(i=0 ; i<proNum; i++)
    {
		for(j=0 ; j<resNum; j++)
        {
			progress[i].res.need[j] = 0;
		}
	}
	return;
}


//初始化可用资源
void init_Available(int resNum) 
{
    int i = 0;
	for(i=0; i<resNum; i++)
    {
		available[i] = 0;
	}
	return;
}
 
//输入进程名，资源名，以及进程信息等
void input_info(int proNum, int resNum) 
{
	int i=0, j=0;
	for(i=0; i<proNum; i++)
    {
		printf("请输入第%d个进程名<共%d>: ", i+1, proNum);
		scanf("%s", progress[i].res.proName);
		for(j=0; j<resNum; j++)
        {
			if(i==0) 
            {
				printf("    请输入第%d个资源类型名<共%d>: ", j+1, resNum);
				scanf("%s", resName[j]);
			}
			printf("        请输入%s类资源的最大需求量: ", resName[j]);
			scanf("%d", &progress[i].res.iMax[j]);
			printf("        请输入%s类资源的当前已分配量: ", resName[j]);
			scanf("%d", &progress[i].res.iAllocation[j]);
			printf(" \n");
		}
		printf(" \n");
	}
	return;
}
 
//给need赋值
void voluation_Need(int proNum, int resNum) 
{
	int i=0,j=0;
	for(i=0; i<proNum; i++)
    {
		for(j=0; j<resNum; j++)
        {
			progress[i].res.need[j]=progress[i].res.iMax[j] - progress[i].res.iAllocation[j];
		}
	}
	return;
}


//对可用资源的输入
void input_Available( int resNum) 
{
	int i=0;
	for(i=0; i<resNum; i++)
    {
		printf("请输入%s类资源的可用数(按回车结束一类资源的输入): ", resName[i]);
		scanf("%d", &available[i]);
		/*
		if( available[i] == 'q' || available[i] == 'Q')//退出检测
		{
			printf("\n\n程序结束。\n");
			exit(0);
		}*/
	}
	return;
}


//初始化work
void init_Work( int resNum) 
{
	int i=0;
	for(i=0; i<resNum; i++){
		work[i]=*(available+i);
	}
	return;
}
//
//
//以下为整个程序的核心代码
//
///
//此处完成合法性的检查，判断系统是否安全
bool check_safety(int proNum, int resNum) 
{
	int i=0, j=0, Need=0, countPro=0, countFor=0, countLastPro=0, countFinish=0;//countFor统计循环的次数,countFinish统计已访问的次数
	int num=0;
	while(countPro < proNum ) 
    {
		for(i=0; i<proNum; i++){
			if ( progress[i].finish != 1)//判断该进程是否已经被访问
			{
				for(j=0; j<resNum; j++)
                {
					Need=progress[i].res.iMax[j] - progress[i].res.iAllocation[j]; 
					if( Need <= work[j] ) {continue; }
					else{break; }
				}
				if(j == resNum) 
                {
					for(j=0; j<resNum; j++)
                    {
						work[j]=work[j] + progress[i].res.iAllocation[j];//资源拥有量
					}
					strcpy(safe_Array[num++], progress[i].res.proName);
					progress[i].finish=1;//把已访问的进程置1
					countPro++;//统计访问进程的个数
				}
			}
		}
		//以下两个判断都能够满足安全性的检查
		//判断1，效率高
		if(countLastPro == countPro)
		{//判断上一次循环统计的进程个数是否等于本次循环的进程个数，
			//若相等则说明可用资源不能满足当前进程的运行
			return false;
		}
		else{//若相等把这次的进程个数赋给上一次统计的个数
			countLastPro = countPro; }
 
		//判断2，效率低
		countFor++;//统计循环的次数，若循环次数大于当前进程的个数，则说明可用资源不能满足当前进程的运行
		if(countFor > proNum)//此处proNum加1，是为了防止与countPro相悖
		{return false; }
	}
	return true;
}
//输入请求进程请求名
int input_Request_Name(int proNum) 
{
	int position=0;
	char reqProName[PRONUM];
	bool flag=true;
	int i=0;
	printf("\n***********************************\n");
	while(flag) {
		printf("按“q”、“Q”结束程序。\n");
		printf("请输入资源请求的进程名：");
		scanf("%s", reqProName);
		if( strcmp(reqProName, "q") ==0 || strcmp(reqProName, "Q") ==0)//退出检测
        {
			printf("\n\n程序结束。\n");
			exit(0);
		}
		for(i=0; i<proNum; i++)
        {
			if( strcmp(progress[i].res.proName, reqProName)==0 ) 
            {
				position=i;
				flag=false;
				break;
			}
		}
		if( proNum == i)
		{
            printf("\n您输入的进程不存在。\n");
        }
	}
	return position;
}
//输入各类资源请求数
bool input_Res_Num(int proNum, int resNum, int *available, int position) 
{
	bool flag=false;
	int need=0;
	int i=0, iflag=-1;
	//char over; 
	printf("\n*************************************\n");
	printf("请输入资源请求量共%d种。\n", resNum);
	for(i=0; i<resNum; i++)
    {
		printf("请输入第%s类资源请求: ", resName[i]);
		scanf("%d", &request[i]);
		/*if( request[i] == 89)//退出检测
		{
			printf("\n\n程序结束。\n");
			exit(0);
			break;
		}*/
	}
	//此处判断request<=Need 并且 request<=Available
	for(i=0; i<resNum; i++)
    {
		need=progress[position].res.iMax[i] - progress[position].res.iAllocation[i];
		if (request[i] > need  ) 
        {
			printf("资源请求量大于需求资源量，资源不分配\n");
			print_Info(proNum, resNum);//输出信息
			return false;
		}
		if ( request[i] > available[i] ) 
        {
			printf("资源请求量大于可用资源量，资源不分配\n");
			print_Info(proNum, resNum);//输出信息
			return false;
		}
	}
	print_Info(proNum, resNum);//输出信息
	return true; 
}


//请求资源
void request_Resource(int proNum, int resNum, int *available) 
{
	bool flag=false, allFlag=true;
	int position=0, need=0;
	int i=0; 
	while(!flag) 
    {
		position = input_Request_Name(proNum);//输入资源请求名
		flag = input_Res_Num(proNum, resNum, available, position);
	}
	init_Flag(proNum, resNum);
	init_Work(resNum);//初始化可用资源
	for(i=0; i<resNum; i++)
    {
		progress[position].res.iAllocation[i] += request[i];
		work[i] -= request[i];
	}
	if( check_safety(proNum, resNum) ) 
    {
		for(i=0; i<resNum; i++)//need值改变
		{
            progress[position].res.need[i] -= request[i]; 
        }
		for(i=0; i<resNum; i++)//available值改变
		{
            available[i] -= request[i]; 
        }
		printf("安全序列是：\n");
		printf("%s", safe_Array[0]);
		for(i=1; i<proNum; i++)
		{
            printf("->%s", safe_Array[i]); 
        }
		putchar('\n'); 
		printf("\n此状态安全。\n");
	}
	else
    {
		printf("\n此状态不安全，资源不分配。\n");
		for(i=0; i<resNum; i++)
		{
            progress[position].res.iAllocation[i] -= request[i]; 
        }
	}
	return;
}

//格式输出
void print_Info(int proNum, int resNum) 
{
	int i=0, j=0;
	printf("\n**************************************************************************************************\n");
	printf("********************                操作系统之银行家算法              ****************************\n");
	printf("**************************************************************************************************\n");
	printf("资源情况       Max\t     \t    Allocation\t      \t      Need\t      \t    Available\n");
	printf("进程");
	for(i=0; i<resNum; i++)
	{
        printf("\t%s", resName[i]); 
    }
	for(i=0; i<resNum; i++)
	{
        printf("\t%s", resName[i]);
    }
	for(i=0; i<resNum; i++)
	{
        printf("\t%s", resName[i]); 
    }
	for(i=0; i<resNum; i++)
	{
        printf("\t%s", resName[i]); 
    }
	printf("\n\n");
	for(i=0; i<proNum; i++)
	{
        printf("%s", progress[i].res.proName); 
		for(j=0; j<resNum; j++)
		{
            printf("\t%d", progress[i].res.iMax[j]); 
        }
		for(j=0; j<resNum; j++)
		{
            printf("\t%d", progress[i].res.iAllocation[j]); 
        }
		for(j=0; j<resNum; j++)
		{
            printf("\t%d", progress[i].res.need[j]); 
        }
		for(j=0; j<resNum && i==0; j++)
		{
            printf("\t%d", available[j]); 
        }
		printf(" \n");
	}
	printf(" \n**************************************************************************************************\n");
	return;
}
//初始化所有需初始化
void init_All(int proNum, int resNum)
{
	init_Flag(proNum, resNum);//初始化相应的信息
	init_Resource(proNum, resNum);//初始化资源
	init_Need(proNum, resNum);//need初始化
	init_Available(resNum);//初始化可用资源
	test();
	//input_info(proNum, resNum);//输入相应信息
	voluation_Need(proNum, resNum);//给need赋值
	print_Info(proNum, resNum);//输出相应信息
	input_Available(resNum);//可用资源
	init_Work(resNum);//初始化可用资源
}

int main(int argc,char* argv[])
{
	int proNum=5, resNum=3;
	char ch=' ';
	bool is_safe=false;
	int i=0;
	system("title 操作系统之银行家算法  作者：宋腾飞");
	system("mode con cols=100 lines=30 ");//
	while(!is_safe) 
    {
		//printf("请输入进程数及资源数：");
		//scanf("%d%c%d", &proNum, &ch, &resNum); 
		//health_Examination(proNum); 
		init_All(proNum, resNum); 
		if( check_safety(proNum, resNum) )
		{
            printf("\n此状态安全。\n");
			printf("安全序列是：\n");
			printf("%s", safe_Array[0]);
			for(i=1; i<proNum; i++)
			{
                printf("->%s", safe_Array[i]); 
            }
			putchar('\n'); 
			is_safe=true; 
			print_Info(proNum, resNum);
		}
		else
        {
			printf("\n此状态不安全。等待5秒钟后请重新输......\n");
			is_safe=false;
			Sleep(5000);
			//system("cls");
		}
	}
	printf("请等待5秒......\n");
	Sleep(5000); 
	do
	{//system("cls");
		request_Resource(proNum, resNum, available); 
	}while(1); 

	//print_Info(proNum, resNum);//输出相应信息
	return 0;
}