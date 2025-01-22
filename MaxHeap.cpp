#include<stdlib.h>
#include<assert.h>
#include<string.h>
#include"MaxHeap.h"

static void FilterDown(ElemType* nums, const int start, const int end)
{
	assert(nums != NULL);
	int pa = start, child = pa * 2 + 1;
	int tmp = nums[pa];
	while (child <= end)
	{
		if (child < end && nums[child] < nums[child + 1]) ++child;
		if (nums[child] <= tmp) break;
		nums[pa] = nums[child];
		pa = child;
		child = pa * 2 + 1;
	}
	nums[pa] = tmp;
}
static void FilterUp(ElemType* nums, const int start)
{
	assert(nums != NULL);
	int child = start, pa = (child - 1) / 2;
	int tmp = nums[child];
	while (child > 0)
	{
		if (tmp <= nums[pa]) break;
		nums[child] = nums[pa];
		child = pa;
		pa = (child - 1) / 2;
	}
	nums[child] = tmp;
}
static ElemType* GetMem(size_t size)
{
	ElemType* s = (ElemType*)malloc(size);
	if (NULL == s) exit(1);
	memset(s, 0, size);
	return s;
}
static void FreeMem(ElemType* p)
{
	free(p);
}
static bool IncCapa(MaxHeap* ph)
{
	size_t newcapa = ph->capacity * INCSIZE * sizeof(ElemType);
	ElemType* newdata = (ElemType*)realloc(ph->data, newcapa);
	if (NULL == newdata) return false;
	//free(ph->data); error;
	ph->data = newdata;
	ph->capacity = ph->capacity * INCSIZE;
	return true;
}
void InitMaxHeap(MaxHeap* ph)
{
	assert(ph != NULL);
	ph->capacity = MAXHEAPSIZE;
	ph->cursize = 0;
	ph->data = GetMem(ph->capacity * sizeof(ElemType));
}
void DestroyMaxHeap(MaxHeap* ph)
{
	assert(ph != NULL);
	FreeMem(ph->data);
	ph->data = NULL;
	ph->cursize = 0;
	ph->capacity = 0;
}
void ClearMaxHeap(MaxHeap* ph)
{
	assert(ph != NULL);
	ph->cursize = 0;
}
int GetSize(const MaxHeap* ph)
{
	assert(ph != NULL);
	return ph->cursize;
}
int GetCapa(const MaxHeap* ph)
{
	assert(ph != NULL);
	return ph->capacity;
}
bool IsEmpty(const MaxHeap* ph)
{
	assert(ph != NULL);
	return GetSize(ph) == 0;
}
bool IsFull(const MaxHeap* ph)
{
	assert(ph != NULL);
	return GetSize(ph) == GetCapa(ph);
}
bool PushBack(MaxHeap* ph, ElemType val)
{
	assert(ph != NULL);
	if (IsFull(ph) && !IncCapa(ph))
	{
		return false;
	}
	ph->data[ph->cursize] = val;
	FilterUp(ph->data, ph->cursize);
	ph->cursize += 1;
	return true;
}
bool GetTop(const MaxHeap* ph, ElemType* pval)
{
	assert(ph != NULL);
	if (NULL == pval) return false;
	if (IsEmpty(ph)) return false;
	*pval = ph->data[0];
	return true;
}
bool PopTop(MaxHeap* ph, ElemType* pval)
{
	assert(ph != NULL);
	if (NULL == pval) return false;
	if (IsEmpty(ph)) return false;
	*pval = ph->data[0];
	ph->cursize -= 1;
	ph->data[0] = ph->data[ph->cursize];
	FilterDown(ph->data, 0, ph->cursize - 1);
	return true;
}

void HeapSort(MaxHeap* hp)
{
	assert(hp != NULL);
	int last = hp->cursize - 1;
	while (last > 0)
	{
		int val;
		int tmp = GetTop(hp, &val);
		hp->data[0] = hp->data[last];
		hp->data[last] = val;
		last--;
		FilterDown(hp->data, 0, last);
		
	}
}