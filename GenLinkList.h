#ifndef GENLINKLIST
#define GENLINKLIST

#define ElEMSIZE (sizeof(void*))
typedef struct GenListNode
{
	struct GenListNode* next;
	struct GenListNode* prev;
	void* data;
}GenListNode;

typedef struct
{
	GenListNode* head;
	int cursize;
	int elmsize;
}GenLinkList;

void InitGenLinkList(GenLinkList* plist, int elmsize);
void DestroyGenLinkList(GenLinkList* plist);
void ClearGenLinkList(GenLinkList* plist);
int GetSize(GenLinkList* plist);
bool Insert(GenLinkList* plist, GenListNode* ptr, void* pval);
bool Push_Back(GenLinkList* plist, void* pval);
bool Push_Front(GenLinkList* plist, void* pval);
bool Pop_Back(GenLinkList* plist);
bool Pop_Front(GenLinkList* plist);
#endif
