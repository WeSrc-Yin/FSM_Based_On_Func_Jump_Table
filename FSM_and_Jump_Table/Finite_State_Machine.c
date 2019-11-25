/*
*************************************************************
* �ļ�����Finite_State_Machine.c
* ��  �ߣ�wenzi
* ��  �ڣ�2019/11/24
* ��  ����V1.0
*************************************************************
*/


#include "Finite_State_Machine.h"
#include "stdio.h"

/*С���ѵ�ʱ�����ת��*/
action_st action_weak[] = 
{
	{EAT,eat},
	{SMILE,sleep},
	{PEE,pee},
};

/*С��˯��ʱ�����ת��*/
action_st action_sleep[] =
{
	{SMILE,sleep},
	{PEE,pee},
};

/*С�����ڲ�ͬ״̬����ת��*/
stat_st status_hal[] = 
{
	{WEAK, sizeof(action_weak)/sizeof(action_st), action_weak},
	{SLEEP,sizeof(action_sleep)/sizeof(action_st),action_sleep},
};


/*С���Է�����Ϊ*/
int eat(int status)
{
    printf("kids eat\n");
	return SLEEP;
}

/*С��΢Ц����Ϊ*/
int sleep(int status)
{
	printf("kids sleep\n");
	return status;
}

/*С���������Ϊ*/
int pee(int status)
{
    printf("kid pee\n");
	return WEAK;
}

#if 0
int excute(int action)
{
     int next_state;
	 int act_id;
	 //status_hal[action].
	 next_state = status_hal[now_state].action_hal[action].act_handle(action);
     now_state = next_state;
	 printf("The kids now status is %d\n",now_state);
}

#else

/*
************************************************************
* ��������excute
* ��  �ܣ�ת������㣬���ݲ���ѡ���Ӧ�ĺ�������ִ��
* ��  �Σ�int action��С����Ŀǰ����Ϊ
* ����ֵ��now_state:Ŀǰ��״̬
************************************************************
*/
int excute(int action)
{
    int next_state;
	int act_id;
	int act_num;
	action_st *action_handle;

	action_handle = status_hal[now_state].action_hal;
	act_num = status_hal[now_state].act_num;
	next_state = 0;

	if(now_state >= status_num)
	{
	    printf("unknown status!\n");
		return;
	}

	/*��������ת�������������뵱ǰ�趨ֵ���ʱ���˳�ѭ��*/
	for(act_id = 0;act_id < act_num;act_id++)
	{
		if(action_handle[act_id].act == action)
		{
			next_state = action_handle[act_id].act_handle(action);
			break;
		}
	}

	if(act_id == act_num)
	{
		printf("Do Not Find action %d",action_handle[act_id]);
		printf(" in status %d\n",now_state);
	}
	now_state = next_state;
	printf("Next Status is:%d\n",now_state);
	return now_state;
}


#endif