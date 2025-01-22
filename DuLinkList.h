#ifndef DULINKLIST_H
#define DULINKLIST_H

typedef int ElemType;
typedef struct DuListNode
{
	ElemType data;
	struct DuListNode *prev;
	struct DuListNode *next;
}DuLNode,*pDuListNode;
typedef struct //不具名结构体：亚元结构
{
	DuLNode * head;
	int cursize;

}DuLinkList;

void InitLinkList(DuLinkList *plist);
void DestroyLinkList(DuLinkList *plist);
int GetSize(const DuLinkList *plist);
bool IsEmpty(const DuLinkList *plist);
bool InsertElem(DuLinkList *plist, DuLNode *ptr, ElemType val);
bool Push_Back(DuLinkList *plist, ElemType val);
bool Push_Front(DuLinkList *plist, ElemType val);
void Print(const DuLinkList *plist);
bool EraseNode(DuLinkList *plist, DuLNode *ptr);
bool Pop_Back(DuLinkList *plist);
bool Pop_Front(DuLinkList *plist);
DuLNode* FindValue(DuLinkList *plist, ElemType val);
bool RemveElem(DuLinkList *plist, ElemType val);
void ClearList(DuLinkList *plist);
#endif
