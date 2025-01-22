#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "LinkStack.h"

//构造一个空栈
Status InitStack(LinkStack* ps)
{
	assert(ps != NULL);
	ps->top = NULL;
	ps->cursize = 0;
	return OK;
}
//销毁栈
void DestroyStack(LinkStack* ps)
{
	assert(ps != NULL);
	ClearStack(ps);
}
//置为空栈
void ClearStack(LinkStack* ps)
{
	assert(ps != NULL);
	while (ps->top != NULL)
	{
		PStackNode p = ps->top;
		ps->top = p->next;
		free(p);
	}
	ps->cursize = 0;
}
//返回栈的元素个数，即栈的长度
int StackLength(const LinkStack* ps)
{
	assert(ps != NULL);
	return ps->cursize;
}
//若栈为空栈，则返回TRUE,否则返回FALSE
bool StackEmpty(const LinkStack* ps)
{
	assert(ps != NULL);
	return ps->cursize == 0;
}
//入栈val , val为栈顶数据元素
Status Push(LinkStack* ps, SElemType val)
{
	PStackNode p = (PStackNode)malloc(sizeof(StackNode));
	if (p == NULL)
	{
		return OVERFLOW;
	}
	p->data = val;
	p->next = ps->top;
	ps->top = p;
	ps->cursize++;
	return OK;
}
//若栈不空，则用pVal返回栈顶元素，并返回OK,否则返回ERROR
Status GetTop(const LinkStack* ps, SElemType* pval)
{
	assert(ps != NULL);
	if (StackEmpty(ps)) { return ERROR; }
	*pval = ps->top->data;
	return OK;
}
//若栈不空，则删除栈顶元素，用pval返回其值,并返回OK,否则返回ERROR
Status Pop(LinkStack* ps, SElemType* pval)
{
	assert(ps != NULL);
	if (StackEmpty(ps)) { return ERROR; }
	PStackNode p = ps->top;
	*pval = p->data;
	ps->top = p->next;
	free(p);
	ps->cursize--;
	return OK;
}