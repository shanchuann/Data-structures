#ifndef BANK_H
#define BANK_H
const int WinSize = 4;
typedef struct
{
	int OccurTime;     // �¼�������ʱ��
	int EventType;     // �¼����ͣ� 0 �ͻ���� 1��2��3��4
}Event;
typedef struct EventNode
{
	Event evdata;
	EventNode* next;
}EventNode;

typedef struct
{
	EventNode* head;
	int cursize;
}OrderEventTable;

extern void InitEventTable(OrderEventTable* pet);
extern void DestroyEventTable(OrderEventTable* pet);
extern int GetSize(const OrderEventTable* pet);
extern bool EventEmpty(const OrderEventTable* pet);
extern bool PopHeader(OrderEventTable* pet, Event* pev);
extern bool InsertEvent(OrderEventTable* pet, Event eval);

//---------------------
typedef struct
{
	int ArrivalTime; //�¼�����ʱ��  
	int StartTime;   //�����¼���ʼʱ��	  
	int Duration;    //�������������ʱ��
}TranType;
typedef struct TranNode
{
	TranType trandata;
	struct TranNode* next;
}TranNode;
typedef struct
{
	struct TranNode* front;
	struct TranNode* tail;
	int cursize;
	int LastTime;
}WinQueue;

extern void InitWinQueue(WinQueue* pw);
extern void DestroyWinQueue(WinQueue* pw);
extern int GetSize(const WinQueue* pw);
extern int GetLastTime(const WinQueue* pw);
extern void SetLastTime(WinQueue* pw, int lastTime);
extern bool QueueEmpty(const WinQueue* pw);
extern bool GetFront(const WinQueue* pw, TranType* pt);
extern bool PopFront(WinQueue* pw, TranType* pt);
extern bool GetTial(const WinQueue* pw, TranType* pt);
extern bool InsertTail(WinQueue* pw, TranType val);

// ------------------
typedef struct
{
	OrderEventTable evList;  //
	WinQueue WinQue[WinSize + 1]; // 0; 
	int TotalTime;// �ۼƿͻ�������ʱ��
	int curtNum;  // �ͻ�����
}BankStat;
extern void InitBankStat(BankStat* pb);
extern void DestroyBankStat(BankStat* pb);
extern void BankOpen(BankStat* pb);
extern void PrintAver(const BankStat* pb);
//----------------------------------------

#endif 
