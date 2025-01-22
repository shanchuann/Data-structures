#ifndef SEQ_QUEUE_H
#define SEQ_QUEUE_H
#define MAXQUEUE 100

typedef struct
{
	char* base;
	int front;
	int rear;
	int cursize;
	int capacity;
	int elemsize; // int 
}GenSeqQueue;

void InitQueue(GenSeqQueue* sp, int elemsize);
void DestroyQueue(GenSeqQueue* sp);
void ClearQueue(GenSeqQueue* sp);
int  QueueLength(const GenSeqQueue* sp);
int QueueCapa(const GenSeqQueue* sp);
bool QueueEmpty(const GenSeqQueue* sp);
bool QueueFull(const GenSeqQueue* sp);
bool GetHead(const GenSeqQueue* sp, void* pval);
bool GetTail(const GenSeqQueue* sp, void* pval);
bool EnQueue(GenSeqQueue* sp, const void* pval);
bool DeQueue(GenSeqQueue* sp, void* pval);
void PrintQueue(const GenSeqQueue* sp, void(*print)(const void* pval));
#endif