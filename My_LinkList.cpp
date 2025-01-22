
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "My_LinkList.h"

static ListNode* Buynode()
{
	ListNode* s = (ListNode*)malloc(sizeof(ListNode));
	if (NULL == s) exit(EXIT_FAILURE);
	memset(s, 0, sizeof(ListNode));
	return s;
}
static void Freenode(ListNode* s)
{
	free(s);
	s = NULL;
}
void InitList(LinkList* plist)
{
	assert(plist != NULL);
	ListNode* s = Buynode();
	s->next = NULL;
	plist->head = s;
	plist->cursize = 0;
}
int GetSize(const LinkList* plist)
{
	assert(plist != NULL);
	return plist->cursize;
}
bool IsEmpty(const LinkList* plist)
{
	assert(plist != NULL);
	return GetSize(plist) == 0;
}
// из╠Ь 0 
ListNode* FindPos(const LinkList* plist, int pos)
{
	assert(plist != NULL);
	if (pos < 0 || pos > plist->cursize)
	{
		return NULL;
	}
	int i = 0;
	ListNode* p = plist->head; // из╠Ь╫з╣Ц
	while (i < pos)
	{
		++i;
		p = p->next;
	}
	return p;
}
ListNode* PrevFindPos(const LinkList* plist, int pos)
{
	assert(plist);
	return FindPos(plist, pos - 1);
}

bool InsertNext(LinkList* plist, ListNode* ptr, ElemType val)
{
	assert(plist != NULL);
	if (NULL == ptr) return false;
	ListNode* s = Buynode();
	s->data = val;
	s->next = ptr->next; //1
	ptr->next = s;		 //2
	plist->cursize += 1;
	return true;
}
bool InsertPos(LinkList* plist, int pos, int val)
{
	assert(plist != NULL);
	return InsertNext(plist, PrevFindPos(plist, pos), val);
}
bool Push_Front(LinkList* plist, ElemType val)
{
	assert(plist != NULL);
	return InsertNext(plist, plist->head, val);
}

void PrintInfo(const LinkList* plist)
{
	assert(plist != NULL);
	ListNode* p = plist->head->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return;
}
bool Push_Back(LinkList* plist, ElemType val)
{
	assert(plist != NULL);
	return InsertNext(plist, FindPos(plist, GetSize(plist)), val);
}
bool DelNext(LinkList* plist, ListNode* ptr)
{
	assert(plist != NULL);
	if (NULL == ptr || NULL == ptr->next) return false;
	ListNode* q = ptr->next;
	ptr->next = q->next;
	Freenode(q);
	plist->cursize -= 1;
	return true;
}
bool DelPos(LinkList* plist, int pos)
{
	assert(plist != NULL);
	if(pos <= 0 || pos > plist->cursize) return false;
	return DelNext(plist, PrevFindPos(plist, pos));
}
bool Pop_Back(LinkList* plist)
{
	assert(plist != NULL);
	return DelPos(plist, GetSize(plist));
}
bool Pop_Front(LinkList* plist)
{
	assert(plist != NULL);
	return DelNext(plist, plist->head);
}
bool Remove(LinkList* plist, ElemType val)
{
	assert(plist != NULL);
	ListNode* p = plist->head;
	while (p->next != NULL)
	{
		if (p->next->data == val)
		{
			DelNext(plist, p);
		}
		else
		{
			p = p->next;
		}
	}
	return true;
}
void ClearList(LinkList* plist)
{
	assert(plist != NULL);
	while (plist->head->next != NULL)
	{
		DelNext(plist, plist->head);
	}
}
void DestroyList(LinkList* plist)
{
	assert(plist != NULL);
	ClearList(plist);
	Freenode(plist->head);
	plist->head = NULL;
	plist->cursize = 0;
}