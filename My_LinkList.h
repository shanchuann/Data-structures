#ifndef LINKLIST_H
#define LINKLIST_H
typedef int ElemType;
typedef struct ListNode
{
	ElemType data;
	struct ListNode* next;
}ListNode;
// sizoef(ListNode); 8

typedef struct
{
	ListNode* head;
	int cursize;
}LinkList;
// sizeof(LinkList); 8

extern void InitList(LinkList* plist);
extern int GetSize(const LinkList* plist);
extern bool IsEmpty(const LinkList* plist);
extern ListNode* FindPos(const LinkList* plist, int pos);
extern ListNode* PrevFindPos(const LinkList* plist, int pos);
extern bool InsertNext(LinkList* plist, ListNode* ptr, ElemType val);
extern bool InsertPos(LinkList* plist, int pos, int val);
extern bool Push_Back(LinkList* plist, ElemType val);
extern bool Push_Front(LinkList* plist, ElemType val);
extern void PrintInfo(const LinkList* plist);

extern bool DelNext(LinkList* plist, ListNode* ptr);
extern bool DelPos(LinkList* plist, int pos);
extern bool Pop_Back(LinkList* plist);
extern bool Pop_Front(LinkList* plist); 
extern bool Remove(LinkList* plist, ElemType val);
extern void ClearList(LinkList* plist);
extern void DestroyList(LinkList* plist);

#endif 
