#include"SeqList.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

static void Swap(ElemType* pa, ElemType* pb)
{
	assert(pa != NULL && pb != NULL);
	ElemType tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
static bool IncMem(SeqList* plist)
{
	assert(plist != NULL);
	int newtotal = plist->capacity * SEQ_INC_SIZE * sizeof(ElemType);
	ElemType* newdata = (ElemType*)realloc(plist->data, newtotal);
	if (NULL == newdata) return false;
	plist->data = newdata;
	plist->capacity = plist->capacity * SEQ_INC_SIZE;
	return true;
}
void InitSeqList(SeqList* plist)
{
	assert(plist != NULL);
	int total = sizeof(ElemType) * SEQ_INIT_SIZE;
	plist->data = (ElemType*)malloc(total);
	if (NULL == plist->data)
	{
		exit(EXIT_FAILURE);
	}
	plist->capacity = SEQ_INIT_SIZE;
	plist->cursize = 0;
}
void DestroySeqList(SeqList* plist)
{
	assert(plist != NULL);
	free(plist->data);
	plist->data = NULL;
	plist->capacity = 0;
	plist->cursize = 0;
}
int GetCapa(const SeqList* plist)
{
	assert(plist != NULL);
	return plist->capacity;
}
int GetSize(const SeqList* plist)
{
	assert(plist != NULL);
	return plist->cursize;
}
bool IsEmpty(const SeqList* plist)
{
	assert(plist != NULL);
	return GetSize(plist) == 0;
}
bool IsFull(const SeqList* plist)
{
	assert(plist != NULL);
	return GetSize(plist) == GetCapa(plist);
}
bool InsertElem(SeqList* plist, int pos, ElemType val)
{
	assert(plist != NULL);
	if (pos < 0 || pos > plist->cursize)
	{
		return false;
	}
	if (IsFull(plist) && !IncMem(plist))
	{
		return false;
	}
	for (int i = plist->cursize; i > pos; --i)
	{
		plist->data[i] = plist->data[i - 1];
	}
	plist->data[pos] = val;
	plist->cursize += 1;
	return true;
}
bool Push_Back(SeqList* plist, ElemType val)
{
	assert(plist != NULL);
	return InsertElem(plist, plist->cursize, val);
}
bool Push_Front(SeqList* plist, ElemType val)
{
	assert(plist != NULL);
	return InsertElem(plist, 0, val);
}
void PrintInfo(const SeqList* plist)
{
	assert(plist != NULL);
	printf("capa : %d  cur : %d \n", plist->capacity, plist->cursize);
	for (int i = 0; i < plist->cursize; ++i)
	{
		printf("%4d ", plist->data[i]);
	}
	printf("\n");
}
int FindValue(const SeqList* plist, ElemType val)
{
	assert(plist != NULL);
	int pos = plist->cursize - 1;
	while (pos >= 0 && plist->data[pos] != val)
	{
		--pos;
	}
	return pos;
}
bool ErasePos(SeqList* plist, int index)
{
	assert(plist != NULL);
	if (index < 0 || index > plist->cursize - 1)
	{
		return false;
	}
	for (int i = index; i < plist->cursize - 1; ++i)
	{
		plist->data[i] = plist->data[i + 1];
	}
	plist->cursize -= 1;
	return true;
}
bool RemoveElem(SeqList* plist, ElemType val)
{
	assert(plist != NULL);
	return ErasePos(plist, FindValue(plist, val));
}
bool RemoveElemAll(SeqList* plist, ElemType val)
{
	assert(plist != NULL);
	bool res = false;
	int j = -1;
	for (int i = 0; i < plist->cursize; ++i)
	{
		if (plist->data[i] != val)
		{
			j += 1;
			plist->data[j] = plist->data[i];
			res = true;
		}
	}
	plist->cursize = j + 1;
	return res;
}
bool Pop_Back(SeqList* plist)
{
	assert(plist != NULL);
	return ErasePos(plist, plist->cursize - 1);
}
bool Pop_Front(SeqList* plist)
{
	assert(plist != NULL);
	return ErasePos(plist, 0);
}
void BubbleSort(SeqList* plist)
{
	assert(plist != NULL);
	if (plist->cursize < 2) return;
	for (int i = 1; i < plist->cursize; ++i)
	{
		bool tag = true;
		for (int j = 0; j < plist->cursize - i; ++j)
		{
			if (plist->data[j] > plist->data[j + 1])
			{
				Swap(&plist->data[j], &plist->data[j + 1]);
				tag = false;
			}
		}
		if (tag) break;
	}
}
void InsertSort(SeqList* plist)
{
	assert(plist != NULL);
	if (plist->cursize < 2) return;
	for (int i = 1; i < plist->cursize; ++i)
	{
		if (plist->data[i] < plist->data[i - 1])
		{
			int j = i - 1;
			ElemType tmp = plist->data[i];
			do
			{
				plist->data[j + 1] = plist->data[j];
				--j;
			} while (j >= 0 && plist->data[j] > tmp);
			plist->data[j + 1] = tmp;
		}
	}
}
void SelectSort(SeqList* plist)
{
	assert(plist != NULL);
	if (plist->cursize < 2) return;
	for (int i = 0; i < plist->cursize - 1; ++i)
	{
		int minpos = i;
		for (int j = i + 1; j < plist->cursize; ++j)
		{
			if (plist->data[minpos] > plist->data[j])
			{
				minpos = j;
			}
		}
		if (minpos != i)
		{
			Swap(&plist->data[i], &plist->data[minpos]);
		}
	}
}
int BinFindValue(const SeqList* plist, ElemType val)
{
	assert(plist != NULL);
	int left = 0, right = plist->cursize - 1;
	int pos = -1;
	while (left <= right)
	{
		int mid = ((right - left) >> 1) + left;
		if (val < plist->data[mid])
		{
			right = mid - 1;
		}
		else if (val > plist->data[mid])
		{
			left = mid + 1;
		}
		else
		{
			if (mid > left && plist->data[mid - 1] == val)
			{
				right = mid - 1;
			}
			else
			{
				pos = mid;
				break;
			}
		}
	}
	return pos;
}
bool GetElem(const SeqList* plist, int index, ElemType* pval)
{
	assert(plist != NULL);
	if (NULL == pval) return false;
	if (index < 0 || index > plist->cursize - 1) return false;
	*pval = plist->data[index];
	return true;
}
bool Back(const SeqList* plist, ElemType* pval)
{
	assert(plist != NULL);
	return GetElem(plist, plist->cursize - 1, pval);
}
bool Front(const SeqList* plist, ElemType* pval)
{
	assert(plist != NULL);
	return GetElem(plist, 0, pval);
}
void ClearSeqList(SeqList* plist)
{
	assert(plist != NULL);
	plist->cursize = 0;

}