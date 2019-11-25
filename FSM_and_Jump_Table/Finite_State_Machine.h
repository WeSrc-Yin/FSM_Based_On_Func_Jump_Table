/*
*************************************************************
* �ļ�����Finite_State_Machine.c
* ��  �ߣ�wenzi
* ��  �ڣ�2019/11/24
* ��  ����V1.0
*************************************************************
*/

#ifndef __FINITE_STATE_MACHINE_H__
#define __FINITE_STATE_MACHINE_H__

/*С��Ŀǰ���ڵ�״̬*/
typedef enum
{
    WEAK = 0,
	SLEEP,
}KID_STAT;


/*С����ǰ����Ϊ*/
typedef enum
{
    EAT = 0,
	SMILE,
	PEE,
}KID_ACT;

/*����С����Ϊ�������ĺ���ָ��*/
typedef int (*Act_Handle)(int);

typedef struct
{
    KID_ACT act;   
	Act_Handle act_handle;
}action_st;

typedef struct
{
	KID_STAT stat;
	int act_num;
	action_st *action_hal;/*����Ϊָ���ԭ����Ϊ�˷����������ת���в����Ĵ���*/
}stat_st;

/*С���ĸ�����Ϊ*/
int eat(int status);
int sleep(int status);
int pee(int status);

int excute(int action);

extern int now_state;

#define status_num sizeof(status_hal)/sizeof(stat_st)

#endif