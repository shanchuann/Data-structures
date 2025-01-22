#include "NotHead.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

bool Push_Front(LinkList* phead, ElemType val)
{
	assert(phead != NULL);
	ListNode* s = (ListNode*)calloc(1, sizeof(ListNode));
	if (NULL == s) exit(1);
	s->data = val;
	s->next = *phead;
	*phead = s;
	return true;
}
bool Push_Back(LinkList* plist, ElemType val)
{
	assert(plist != NULL);
	ListNode* s = (ListNode*)malloc(sizeof(ListNode));
	if (s == NULL) return false;
	s->data = val;
	s->next = NULL;
	if (*plist == NULL)
	{
		*plist = s;
	}
	else
	{
		ListNode* p = *plist;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = s;
	}
	return true;
}  
void PrintList(LinkList* plist)
{
	assert(plist != NULL);
	ListNode* p = *plist;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
ListNode* FindBackCount(LinkList head, int k)
{
	assert(head != NULL);
	ListNode* fast = head;
	ListNode* slow = head;
	while (k--)
	{
		if (fast == NULL) return NULL;
		fast = fast->next;
	}
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}
void PrintList(LinkList head)
{
	assert(head != NULL);
	ListNode* p = head;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
}
ListNode* FindMid(LinkList head)
{
	assert(head != NULL);
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
void ResList(LinkList* phead)
{
	assert(phead != NULL);
	ListNode* p = *phead;
	ListNode* q = NULL;
	while (p != NULL)
	{
		ListNode* s = p->next;
		p->next = q;
		q = p;
		p = s;
	}
	*phead = q;
}
void MergeList(LinkList* pheadA, LinkList* pheadB, LinkList* pheadC)
{
	assert(pheadA != NULL && pheadB != NULL && pheadC != NULL);
	ListNode* p = *pheadA;
	ListNode* q = *pheadB;
	ListNode* r = *pheadC;
	while (p != NULL && q != NULL)
	{
		if (p->data < q->data)
		{
			r->next = p;
			r = p;
			p = p->next;
		}
		else
		{
			r->next = q;
			r = q;
			q = q->next;
		}
	}
	if (p != NULL)
	{
		r->next = p;
	}
	if (q != NULL)
	{
		r->next = q;
	}
}