#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "SeqQueue.h"

void InitQueue(GenSeqQueue* sp, int elemsize)
{
	assert(sp != NULL);
	sp->base = (char*)malloc(elemsize * MAXQUEUE);
	if (sp->base == NULL) exit(EXIT_FAILURE);
	sp->front = 0;
	sp->rear = 0;
	sp->cursize = 0;
	sp->capacity = MAXQUEUE;
	sp->elemsize = elemsize;
}
void DestroyQueue(GenSeqQueue* sp)
{
	assert(sp != NULL);
	
}
void ClearQueue(GenSeqQueue* sp)
{
	assert(sp != NULL);
	sp->front = 0;
	sp->rear = 0;
	sp->cursize = 0;

}
int  QueueLength(const GenSeqQueue* sp)
{
	assert(sp != NULL);
	return sp->cursize;
}
int QueueCapa(const GenSeqQueue* sp)
{
	assert(sp != NULL);
	return sp->capacity;
}
bool QueueEmpty(const GenSeqQueue* sp)
{
	assert(sp != NULL);
	return QueueLength(sp) == 0;
}
bool QueueFull(const GenSeqQueue* sp)
{
	assert(sp != NULL);
	return QueueLength(sp) == sp->capacity;
}
bool GetHead(const GenSeqQueue* sp, void* pval)
{
	assert(sp != NULL);
	if (QueueEmpty(sp)) return false;
	int index = sp->front * sp->elemsize;
	memmove(pval, &sp->base[index], sp->elemsize);
	return true;
}
bool GetTail(const GenSeqQueue* sp, void* pval)
{
	assert(sp != NULL);
	if (QueueEmpty(sp)) return false;
	int index = ((sp->rear + sp->capacity - 1 ) % sp->capacity) * sp->elemsize;
	memmove(pval, &sp->base[index], sp->elemsize);
	return true;
}
bool EnQueue(GenSeqQueue* sp, const void* pval)
{
	assert(sp != NULL);
	if (QueueFull(sp)) return false;
	if (pval == NULL) return false;
	int index = sp->rear * sp->elemsize;
	memmove(&sp->base[index], pval, sp->elemsize);
	sp->rear = (sp->rear + 1) % sp->capacity;
	sp->cursize++;
	return true;
}
bool DeQueue(GenSeqQueue* sp, void* pval)
{
	assert(sp != NULL);
	if (QueueEmpty(sp)) return false;
	if (pval == NULL) return false;
	int index = sp->front * sp->elemsize;
	memmove(pval, &sp->base[index], sp->elemsize);
	sp->front = (sp->front + 1) % sp->capacity;
	sp->cursize--;
	return true;
}

void PrintQueue(const GenSeqQueue* sp, void(*print)(const void* pval))
{
	assert(sp != NULL);
	if (print == NULL) return;
	for (int i = sp->front; i != sp->rear; i = (i + 1) % sp->capacity)
	{
		print(&sp->base[i * sp->elemsize]);
	}
}
