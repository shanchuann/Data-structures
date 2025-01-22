#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"GenListQueue.h"

void InitGenListQueue(GenListQueue* pq, int elemsize)
{
	assert(pq != NULL);
	pq->plist = (GenLinkList*)malloc(sizeof(GenLinkList));
	if (NULL == pq->plist) exit(EXIT_FAILURE);
	InitGenDuLinkList(pq->plist, elemsize);
}
void DestroyGenListQueue(GenListQueue* pq)
{
	assert(pq != NULL);
	DestroyGenLinkList(pq->plist);
	free(pq->plist);
	pq->plist = NULL;
}
void ClearGenListQueue(GenListQueue* pq)
{
	assert(pq != NULL);
	ClearGenLinkList(pq->plist);
}
int QueueSize(const GenListQueue* pq)
{
	assert(pq != NULL);
	return GetSize(pq->plist);
}
bool QueueEmpty(const GenListQueue* pq)
{
	assert(pq != NULL);
	return IsEmpty(pq->plist);
}
bool GetHead(const GenListQueue* pq, void* pval)
{
	assert(pq != NULL);
	return GetFront(pq->plist, pval);
}
bool GetTail(const GenListQueue* pq, void* pval)
{
	assert(pq != NULL);
	return GetBack(pq->plist, pval);
}
bool EnQueue(GenListQueue* pq, const void* pval)
{
	assert(pq != NULL);
	return Push_Back(pq->plist, pval);
}
bool DeQueue(GenListQueue* pq, void* pval)
{
	assert(pq != NULL);
	bool res = false;
	if (GetFront(pq->plist, pval))
	{
		Pop_Front(pq->plist);
		res = true;
	}
	return res;
}