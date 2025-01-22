#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "LinkStack.h"

//����һ����ջ
Status InitStack(LinkStack* ps)
{
	assert(ps != NULL);
	ps->top = NULL;
	ps->cursize = 0;
	return OK;
}
//����ջ
void DestroyStack(LinkStack* ps)
{
	assert(ps != NULL);
	ClearStack(ps);
}
//��Ϊ��ջ
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
//����ջ��Ԫ�ظ�������ջ�ĳ���
int StackLength(const LinkStack* ps)
{
	assert(ps != NULL);
	return ps->cursize;
}
//��ջΪ��ջ���򷵻�TRUE,���򷵻�FALSE
bool StackEmpty(const LinkStack* ps)
{
	assert(ps != NULL);
	return ps->cursize == 0;
}
//��ջval , valΪջ������Ԫ��
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
//��ջ���գ�����pVal����ջ��Ԫ�أ�������OK,���򷵻�ERROR
Status GetTop(const LinkStack* ps, SElemType* pval)
{
	assert(ps != NULL);
	if (StackEmpty(ps)) { return ERROR; }
	*pval = ps->top->data;
	return OK;
}
//��ջ���գ���ɾ��ջ��Ԫ�أ���pval������ֵ,������OK,���򷵻�ERROR
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