#include "DuLinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

static DuLNode* BuyNode()
{
	DuLNode* s = (DuLNode*)malloc(sizeof(DuLNode));
	if (s == NULL) exit(EXIT_FAILURE);
	memset(s, 0, sizeof(DuLNode));
	return s;
}
static void FreeNode(DuLNode* p)  
{  
   free(p);  
}
void InitLinkList(DuLinkList *plist)
{
	assert(plist != NULL);
	DuLNode* p = BuyNode();
	if(p == NULL) return;
	p->next = p;
	p->prev = p;
	plist->head = p;
	plist->cursize = 0;
}
int GetSize(const DuLinkList* plist)
{
	assert(plist != NULL);
	return plist->cursize;
}
bool IsEmpty(const DuLinkList* plist)
{
	assert(plist != NULL);
	return plist->cursize == 0;
}
void DestroyLinkList(DuLinkList* plist)
{
	assert(plist != NULL);
	DuLNode* p = plist->head->next;
	while (p != plist->head)
	{
		DuLNode* q = p->next;
		FreeNode(p);
		p = q;
	}
	FreeNode(plist->head);
	plist->head = NULL;
	plist->cursize = 0;
}
bool InsertElem(DuLinkList* plist, DuLNode* ptr, ElemType val)
{   
	assert(plist != NULL);
	DuLNode* p = BuyNode();
	if (p == NULL) return false;
	p->data = val;
	p->next = ptr;
	p->prev = ptr->prev;
	ptr->prev->next = p;
	ptr->prev = p;
	plist->cursize++;
	return true;
}
bool Push_Front(DuLinkList* plist, ElemType val)
{
	assert(plist != NULL);
	return InsertElem(plist, plist->head->next, val);
}
bool Push_Back(DuLinkList* plist, ElemType val)
{
	assert(plist != NULL);
	return InsertElem(plist, plist->head, val);
}
void Print(const DuLinkList* plist)
{
	assert(plist != NULL);
	DuLNode* p = plist->head->next;
	while (p != plist->head)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
bool EraseNode(DuLinkList* plist, DuLNode* ptr)
{
	assert(plist != NULL);
	ptr->prev->next = ptr->next;
	ptr->next->prev = ptr->prev;
	FreeNode(ptr);
	plist->cursize--;
	return true;
}
bool Pop_Back(DuLinkList* plist)
{
	assert(plist != NULL);
	if (IsEmpty(plist)) return false;
	return EraseNode(plist, plist->head->prev);
}
bool Pop_Front(DuLinkList* plist)
{
	assert(plist != NULL);
	if (IsEmpty(plist)) return false;
	return EraseNode(plist, plist->head->next);
}
DuLNode* FindValue(DuLinkList* plist, ElemType val)
{
	assert(plist != NULL);
	DuLNode* p = plist->head->next;
	while (p != plist->head)
	{
		if (p->data == val) return p;
		p = p->next;
	}
	return NULL;
}
bool RemveElem(DuLinkList* plist, ElemType val)
{
	assert(plist != NULL);
	DuLNode* p = FindValue(plist, val);
	if (p == NULL) return false;
	return EraseNode(plist, p);
}
void ClearList(DuLinkList* plist)
{
	assert(plist != NULL);
	DuLNode* p = plist->head->next;
	while (p != plist->head)
	{
		DuLNode* q = p->next;
		FreeNode(p);
		p = q;
	}
	plist->head->next = plist->head;
	plist->head->prev = plist->head;
	plist->cursize = 0;
}