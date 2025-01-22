#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"GenDuLinkList.h"

static GenListNode* Buynode(size_t size)
{
	size_t total = sizeof(GenListNode) + sizeof(char) * size;
	GenListNode* s = (GenListNode*)malloc(total);
	if (NULL == s) exit(EXIT_FAILURE);
	memset(s, 0, total);
	//memset(&s, 0,sizeof(void*));
	return s;
}
static void Freenode(GenListNode* p)
{
	free(p);
}
void InitGenDuLinkList(GenLinkList* plist, int elemsize)
{
	assert(plist != NULL);
	GenListNode* s = Buynode(0);
	s->next = s->prev = s;
	plist->head = s;
	plist->elemsize = elemsize;
	plist->cursize = 0;
}
void DestroyGenLinkList(GenLinkList* plist)
{
	assert(plist);
	ClearGenLinkList(plist);
	Freenode(plist->head);
	plist->head = NULL;
	plist->elemsize = -1;
}
void ClearGenLinkList(GenLinkList* plist)
{
	assert(plist != NULL);
	while (plist->head->next != plist->head)
	{
		GenListNode* q = plist->head->next;
		//plist->head->next = q->next;
		q->next->prev = q->prev;
		q->prev->next = q->next;
		Freenode(q);
	}
	//plist->head->prev = plist->head;
	plist->cursize = 0;
}
int GetSize(const GenLinkList* plist)
{
	assert(plist != NULL);
	return plist->cursize;
}
bool IsEmpty(const GenLinkList* plist)
{
	assert(plist != NULL);
	return GetSize(plist) == 0;
}
int InserPrevElem(GenLinkList* plist, GenListNode* ptr, const void* pval)   // 
{
	assert(plist != NULL);
	if (NULL == ptr) return 1;
	if (NULL == pval) return 2;
	GenListNode* s = Buynode(plist->elemsize);
	memmove(s->data, pval, plist->elemsize);
	//s->data = pval; // error;
	s->prev = ptr->prev;
	s->next = ptr;
	ptr->prev = s;
	s->prev->next = s;
	plist->cursize += 1;
	return 0;
}

bool Push_Back(GenLinkList* plist,const void* pval)
{
	assert(plist != NULL);
	return InserPrevElem(plist, plist->head, pval);

}
bool Push_Front(GenLinkList* plist, const void* pval)
{
	assert(plist != NULL);
	return InserPrevElem(plist, plist->head->next, pval);
}
void PrintInfo(const GenLinkList* plist, void (*print)(const void*))
{
	assert(plist != NULL);
	GenListNode* p = plist->head->next;
	while (p != plist->head)
	{
		print(p->data);
		p = p->next;
	}
	printf("\n");
}
GenListNode* FindValue(const GenLinkList* plist, const  void* pval)
{
	assert(plist != NULL);
	if (NULL == pval) return NULL;
	GenListNode* pos = NULL;
	GenListNode* p = plist->head->next; // first data;
	while (p != plist->head)
	{
		if (memcmp(p->data, pval, plist->elemsize) == 0)
		{
			pos = p;
			break;
		}
		p = p->next;
	}
	return pos;
}

GenListNode* FindElem(const GenLinkList* plist, const  void* pval,
	bool (*cmp)(const void*, const void*))
{
	assert(plist != NULL);
	if (NULL == pval || NULL == cmp) return NULL;
	GenListNode* pos = NULL;
	GenListNode* p = plist->head->next; // first data;
	while (p != plist->head)
	{
		if (cmp(p->data, pval))
		{
			pos = p;
			break;
		}
		p = p->next;
	}
	return pos;
}

bool EraseNode(GenLinkList* plist, GenListNode* ptr)
{
	assert(plist != NULL);
	if (NULL == ptr || ptr == plist->head) return false;
	ptr->prev->next = ptr->next;
	ptr->next->prev = ptr->prev;
	Freenode(ptr);
	plist->cursize -= 1;
	return true;
}
void Pop_Back(GenLinkList* plist)
{
	assert(plist != NULL);
	EraseNode(plist, plist->head->prev);
}
void Pop_Front(GenLinkList* plist)
{
	assert(plist != NULL);
	EraseNode(plist, plist->head->next);
}
void RemoveValue(GenLinkList* plist, const  void* pval)
{
	assert(plist != NULL);
	EraseNode(plist, FindValue(plist, pval));
}
void RemoveElem(GenLinkList* plist, const  void* pval, bool (*cmp)(const void*, const void*))
{
	assert(plist != NULL);
	EraseNode(plist, FindElem(plist, pval, cmp));
}

bool GetBack(const GenLinkList* plist, void* pval)
{
	assert(plist != NULL);
	if (NULL == pval || IsEmpty(plist))  return false;
	//*pval = plist->head->prev->data;
	memmove(pval, plist->head->prev->data, plist->elemsize);
	return true;
}
bool GetFront(const GenLinkList* plist, void* pval)
{
	assert(plist != NULL);
	if (NULL == pval || IsEmpty(plist))  return false;
	//*pval = plist->head->prev->data;
	memmove(pval, plist->head->next->data, plist->elemsize);
	return true;
}