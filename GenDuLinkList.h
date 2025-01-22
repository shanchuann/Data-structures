#ifndef GENDULINKLIST_HPP
#define GENDULINKLIST_HPP
typedef struct GenListNode
{
	struct GenListNode* prev;
	struct GenListNode* next;
	char data[0];            // void *data;
}GenListNode;

typedef struct
{
	GenListNode* head;
	int elemsize;  // 4 8 
	int cursize;
}GenLinkList;

extern void InitGenDuLinkList(GenLinkList* plist, int elemsize);
extern void DestroyGenLinkList(GenLinkList* plist);
extern void ClearGenLinkList(GenLinkList* plist);
extern int GetSize(const GenLinkList* plist);
extern bool IsEmpty(const GenLinkList* plist);
extern int InserPrevElem(GenLinkList* plist, GenListNode* ptr, const void* pval);
extern bool Push_Back(GenLinkList* plist,const void* pval);
extern bool Push_Front(GenLinkList* plist, const  void* pval);

extern bool GetBack(const GenLinkList* plist, void* pval);
extern bool GetFront(const GenLinkList* plist, void* pval);
extern void PrintInfo(const GenLinkList* plist, void (*print)(const void*));
extern GenListNode* FindValue(const GenLinkList* plist, const  void* pval);
extern GenListNode* FindElem(const GenLinkList* plist, const  void* pval,
	bool (*cmp)(const void*, const void*));

extern bool EraseNode(GenLinkList* plist, GenListNode* ptr);
extern void Pop_Back(GenLinkList* plist);
extern void Pop_Front(GenLinkList* plist);
extern void RemoveValue(GenLinkList* plist, void* pval); // int double;
extern void RemoveElem(GenLinkList* plist, void* pval,
	bool (*cmp)(const void*, const void*));

#endif 