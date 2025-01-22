#ifndef GENLISTQUEUE_H
#define GENLISTQUEUE_H
#include"GenDuLinkList.h"

typedef struct
{
	GenLinkList* plist;
}GenListQueue;

void InitGenListQueue(GenListQueue* pq, int elemsize);
void DestroyGenListQueue(GenListQueue* pq);
void ClearGenListQueue(GenListQueue* pq);
int QueueSize(const GenListQueue* pq);
bool QueueEmpty(const GenListQueue* pq);
bool GetHead(const GenListQueue* pq, void* pval);
bool GetTail(const GenListQueue* pq, void* pval);
bool EnQueue(GenListQueue* pq, const void* pval);
bool DeQueue(GenListQueue* pq, void* pval);

#endif