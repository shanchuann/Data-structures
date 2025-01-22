#ifndef GEN_LIST_STACK_HPP
#define GEN_LIST_STACK_HPP

#include"GenDuLinkList.h"

typedef struct
{
	GenLinkList* plist;	   // GenLinkList gen;
}GenListStack;

extern void InitGenListStack(GenListStack* ps, size_t elemsize);
extern void DestroyGenListStack(GenListStack* ps);
extern void ClearGenListStack(GenListStack* ps);
extern int GetLength(const GenListStack* ps);
extern bool StackEmpty(const GenListStack* ps);
extern bool Push(GenListStack* ps, const void* pval);
extern bool GetTop(GenListStack* ps, void* pval);
extern bool Pop(GenListStack* ps, void* pval);

#endif 
