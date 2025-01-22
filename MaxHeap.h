#ifndef MAXHEAP_H
#define MAXHEAP_H

#define MAXHEAPSIZE  8
#define INCSIZE      2
typedef int ElemType;
typedef struct
{
	ElemType* data;
	int cursize;
	int capacity;
}MaxHeap;

void InitMaxHeap(MaxHeap* ph);
void DestroyMaxHeap(MaxHeap* ph);
void ClearMaxHeap(MaxHeap* ph);
int GetSize(const MaxHeap* ph);
int GetCapa(const MaxHeap* ph);
bool IsEmpty(const MaxHeap* ph);
bool IsFull(const MaxHeap* ph);
bool PushBack(MaxHeap* ph, ElemType val);
bool GetTop(const MaxHeap* ph, ElemType* pval);
bool PopTop(MaxHeap* ph, ElemType* pval);
void HeapSort(MaxHeap* hp);

#endif 
