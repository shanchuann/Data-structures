#ifndef NOTHEAD_HPP
#define NOTHEAD_HPP
typedef int ElemType;
typedef struct ListNode
{
	ElemType data;
	struct ListNode* next;
}ListNode, * LinkList;

extern bool Push_Front(LinkList* phead, ElemType val);
extern bool Push_Back(LinkList* phead, ElemType val);
extern void PrintList(LinkList head);
extern ListNode* FindBackCount(LinkList head, int k);
extern ListNode* FindMid(LinkList head);
extern void ResList(LinkList* phead);
extern void MergeList(LinkList* pheadA, LinkList* pheadB, LinkList* pheadC);

#endif