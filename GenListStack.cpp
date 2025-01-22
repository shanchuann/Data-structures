#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include"GenListStack.h"

void InitGenListStack(GenListStack* ps, size_t elemsize)
{
	assert(ps != NULL);
	ps->plist = (GenLinkList*)malloc(sizeof(GenLinkList));
	if (NULL == ps->plist) exit(EXIT_FAILURE);
	InitGenDuLinkList(ps->plist, elemsize);
}
void DestroyGenListStack(GenListStack* ps)
{
	assert(ps != NULL);
	DestroyGenLinkList(ps->plist);
	free(ps->plist);
	ps->plist = NULL;
}
void ClearGenListStack(GenListStack* ps)
{
	assert(ps != NULL);
	ClearGenLinkList(ps->plist);
}
int GetLength(const GenListStack* ps)
{
	assert(ps != NULL);
	return GetSize(ps->plist);
}
bool StackEmpty(const GenListStack* ps)
{
	assert(ps != NULL);
	return IsEmpty(ps->plist);
}
bool Push(GenListStack* ps,const void* pval)
{
	assert(ps != NULL);
	return Push_Back(ps->plist, pval);

}
bool GetTop(GenListStack* ps, void* pval)
{
	assert(ps != NULL);
	return GetBack(ps->plist, pval);

}
bool Pop(GenListStack* ps, void* pval)
{
	assert(ps != NULL);
	bool res = false;
	if (GetBack(ps->plist, pval))
	{
		Pop_Back(ps->plist);
		res = true;
	}
	return res;
}

