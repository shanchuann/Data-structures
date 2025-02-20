#include"Bank.h"
#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include<assert.h>
#include<time.h>
#include<stdio.h>

static EventNode* BuyEventNode()
{
	EventNode* s = (EventNode*)malloc(sizeof(EventNode));
	if (NULL == s) exit(1);
	memset(s, 0, sizeof(EventNode));
	return s;
}
static void FreeEventNode(EventNode* p)
{
	free(p);
}
void InitEventTable(OrderEventTable* pet)
{
	assert(pet != NULL);
	pet->head = BuyEventNode();
	pet->cursize = 0;
}
void DestroyEventTable(OrderEventTable* pet)
{
	assert(pet != NULL);
	while (pet->head != NULL)
	{
		EventNode* q = pet->head;
		pet->head = q->next;
		FreeEventNode(q);
	}
	pet->cursize = 0;
}
int GetSize(const OrderEventTable* pet)
{
	assert(pet != NULL);
	return pet->cursize;
}
bool EventEmpty(const OrderEventTable* pet)
{
	assert(pet != NULL);
	return GetSize(pet) == 0;
}
bool PopHeader(OrderEventTable* pet, Event* pev)
{
	assert(pet != NULL);
	if (EventEmpty(pet)) return false;
	if (NULL == pev) return false;
	EventNode* q = pet->head->next; //first; 
	pet->head->next = q->next;
	*pev = q->evdata;
	FreeEventNode(q);
	pet->cursize -= 1;
	return true;
}
bool InsertEvent(OrderEventTable* pet, Event eval)
{
	assert(pet != NULL);
	EventNode* s = BuyEventNode();
	s->evdata = eval;
	s->next = NULL;
	EventNode* pre = pet->head;
	EventNode* p = pet->head->next; // first;
	while (p != NULL && eval.OccurTime > p->evdata.OccurTime)
	{
		pre = p;
		p = p->next;
	}
	s->next = pre->next;
	pre->next = s;
	pet->cursize += 1;
	return true;
}

//---------------------
//typedef struct
//{
//	int ArrivalTime; //事件到达时刻  
//	int StartTime;   //办理事件开始时刻	  
//	int Duration;    //办理事务所需的时间
//}TranType;
//typedef struct TranNode
//{
//	TranType trandata;
//	struct TranNode *next;
//}TranNode;
//typedef struct
//{
//	struct TranNode *front;
//	struct TranNode *tail;
//	int cursize;
//	int LastTime;
//}WinQueue;

static TranNode* BuyTran()
{
	TranNode* s = (TranNode*)malloc(sizeof(TranNode));
	if (NULL == s) exit(1);
	memset(s, 0, sizeof(TranNode));
	return s;
}
static void FreeTran(TranNode* p)
{
	free(p);
}
void InitWinQueue(WinQueue* pw)
{
	assert(pw != NULL);
	pw->front = pw->tail = NULL;
	pw->LastTime = 0;
	pw->cursize = 0;
}
void DestroyWinQueue(WinQueue* pw)
{
	assert(pw != NULL);
	while (pw->front != NULL)
	{
		TranNode* q = pw->front;
		pw->front = q->next;
		FreeTran(q);
	}
	pw->front = pw->tail = NULL;
	pw->cursize = 0;
	pw->LastTime = 0;
}
int GetSize(const WinQueue* pw)
{
	assert(pw != NULL);
	return pw->cursize;
}
int GetLastTime(const WinQueue* pw)
{
	assert(pw != NULL);
	return pw->LastTime;
}
void SetLastTime(WinQueue* pw, int lastTime)
{
	assert(pw != NULL);
	pw->LastTime = lastTime;
}
bool QueueEmpty(const WinQueue* pw)
{
	assert(pw != NULL);
	return GetSize(pw) == 0;
}
bool GetFront(const WinQueue* pw, TranType* pt)
{
	assert(pw != NULL);
	if (NULL == pt) return false;
	if (QueueEmpty(pw)) return false;
	*pt = pw->front->trandata;
	return true;
}
bool PopFront(WinQueue* pw, TranType* pt)
{
	assert(pw != NULL);
	if (NULL == pt) return false;
	if (QueueEmpty(pw)) return false;
	*pt = pw->front->trandata;
	TranNode* q = pw->front;
	pw->front = q->next;
	if (NULL == pw->front)  pw->tail = NULL;
	pw->cursize -= 1;
	FreeTran(q);
	return true;
}
bool GetTial(const WinQueue* pw, TranType* pt)
{
	assert(pw != NULL);
	if (NULL == pt) return false;
	if (QueueEmpty(pw)) return false;
	*pt = pw->tail->trandata;
	return true;
}
bool InsertTail(WinQueue* pw, TranType val)
{
	assert(pw != NULL);
	TranNode* s = BuyTran();
	s->trandata = val;
	if (NULL == pw->tail)
	{
		pw->tail = pw->front = s;
	}
	else
	{
		pw->tail->next = s;
		s->next = NULL;
	}
	pw->cursize += 1;
	return true;
}

// ------------------
//typedef struct
//{
//	OrderEventTable evList;  //
//	WinQueue WinQue[WinSize + 1]; // 0; 
//	int TotalTime;// 累计客户逗留的时间
//	int curtNum;  // 客户总数
//}BankStat;
static int SelectMinLastTime(WinQueue win[])
{
	int minpos = 1;
	for (int i = 2; i <= WinSize; ++i)
	{
		if (win[minpos].LastTime > win[i].LastTime)
		{
			minpos = i;
		}
	}
	return minpos;
}
void InitBankStat(BankStat* pb)
{
	assert(pb != NULL);
	InitEventTable(&pb->evList);
	for (int i = 1; i <= WinSize; ++i)
	{
		InitWinQueue(&pb->WinQue[i]);
	}
	pb->TotalTime = 0;
	pb->curtNum = 0;
}
void DestroyBankStat(BankStat* pb)
{
	assert(pb != NULL);
	DestroyEventTable(&pb->evList);
	for (int i = 1; i <= WinSize; ++i)
	{
		DestroyWinQueue(&pb->WinQue[i]);
	}
	pb->curtNum = 0;
	pb->TotalTime = 0;
}
void BankOpen(BankStat* pb)
{
	srand(time(NULL));
	int cliNum = 20;//rand() % 1000;
	Event ev = { 0,0 };
	InsertEvent(&pb->evList, ev);
	for (int i = 1; i < cliNum; ++i)
	{
		if (EventEmpty(&pb->evList)) { break; }
		PopHeader(&pb->evList, &ev);
		if (0 == ev.EventType)
		{
			int CurDuration = rand() % 20 + 1;
			int NextCli = rand() % 20 + 1;
			Event nextCli{ ev.OccurTime + NextCli, 0 };
			InsertEvent(&pb->evList, nextCli);

			TranType TranCli = { ev.OccurTime,-1,CurDuration };
			int winIndex = SelectMinLastTime(pb->WinQue);
			int lastTime = GetLastTime(&pb->WinQue[winIndex]);
			if (lastTime > TranCli.ArrivalTime)
			{
				TranCli.StartTime = lastTime;
			}
			else
			{
				TranCli.StartTime = TranCli.ArrivalTime;
			}
			SetLastTime(&pb->WinQue[winIndex], lastTime + TranCli.Duration);
			InsertTail(&pb->WinQue[winIndex], TranCli);
			Event evCli = { TranCli.StartTime + TranCli.Duration,winIndex };
			InsertEvent(&pb->evList, evCli);
		}
		else
		{
			int winIndex = ev.EventType; // 0; // 1 2 3 4
			TranType tran;
			PopFront(&pb->WinQue[winIndex], &tran);
			pb->TotalTime += (tran.StartTime - tran.ArrivalTime + tran.Duration);
			pb->curtNum += 1;
		}

	}
}
void PrintAver(const BankStat* pb)
{
	assert(pb != NULL);
	printf("totalTime: %d , total curNum: %d \n", pb->TotalTime, pb->curtNum);
	printf("eval: %lf \n", (double)pb->TotalTime / pb->curtNum);
}
//----------------------------------------