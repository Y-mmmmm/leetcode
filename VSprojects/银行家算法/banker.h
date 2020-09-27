#ifndef _BANKER_H
#define _BANKER_H




void test(void);
void init_Flag(int proNum, int resNum);
void init_Resource(int proNum, int resNum);
void init_Need(int proNum, int resNum);
void init_Available(int resNum);
void input_info(int proNum, int resNum);
void voluation_Need(int proNum, int resNum);
void input_Available( int resNum);
void init_Work( int resNum);
bool check_safety(int proNum, int resNum);
int input_Request_Name(int proNum);
bool input_Res_Num(int proNum, int resNum, int *available, int position);
void request_Resource(int proNum, int resNum, int *available);
void print_Info(int proNum, int resNum);
void init_All(int proNum, int resNum);
void health_Examination(int proNum, int resNum)







#endif




