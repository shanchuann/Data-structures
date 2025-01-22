#include "GenLinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static GenLinkList* BuyNode(){
	GenLinkList* p = (GenLinkList*)malloc(sizeof(GenLinkList));
	if (p == NULL) exit(EXIT_FAILURE);
	memset(p, 0, sizeof(GenLinkList));
	return p;
}
static GenLinkList* FreeNode(GenLinkList* p) {
	free(p);
}
void InitGenLinkList(GenLinkList* plist, int elmsize)
{
	assert(plist != NULL);
	GenLinkList* p = BuyNode();
}
void DestroyGenLinkList(GenLinkList* plist);
void ClearGenLinkList(GenLinkList* plist);
int GetSize(GenLinkList* plist);
bool Insert(GenLinkList* plist, GenListNode* ptr, void* pval);
bool Push_Back(GenLinkList* plist, void* pval);
bool Push_Front(GenLinkList* plist, void* pval);
bool Pop_Back(GenLinkList* plist);
bool Pop_Front(GenLinkList* plist);
