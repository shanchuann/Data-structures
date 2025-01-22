#include"SeqStack.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

static SElemType* BuyMem(size_t size)  // size_t =>unsigned int;
{
	SElemType* s = (SElemType*)calloc(1,size);
	if (NULL == s) exit(EXIT_FAILURE); // EXIT_FAILURE:
	return s;
}
static void FreeMem(SElemType* p)
{
	free(p);
}
static bool IncMem(SeqStack* ps)
{
	assert(ps != NULL);
	int total = ps->stacksize * sizeof(SElemType) * STACKINCREMENT;
	SElemType* newdata = (SElemType*)realloc(ps->base, total);
	if (NULL == newdata) return false;
	ps->base = newdata;
	ps->top = newdata + ps->stacksize;
	ps->stacksize = ps->stacksize * STACKINCREMENT;
	return true;
}

//����һ����ջ 
Status InitStack(SeqStack* ps)
{
	assert(ps != NULL);
	int total = sizeof(SElemType) * STACK_INIT_SIZE;
	ps->base = ps->top = BuyMem(total);
	ps->stacksize = STACK_INIT_SIZE;
	return OK;
}
//����ջ
void DestroyStack(SeqStack* ps)
{
	assert(ps != NULL);
	FreeMem(ps->base); // FreeMem(ps->top);	 // error
	ps->base = ps->top = NULL;
	ps->stacksize = 0;
}
//��Ϊ��ջ
void ClearStack(SeqStack* ps)
{
	assert(ps != NULL);
	ps->top = ps->base;
}
//����ջ��Ԫ�ظ�������ջ�ĳ���
int StackLength(const SeqStack* ps)
{
	assert(ps != NULL);
	return ps->top - ps->base;
}
//��ջΪ��ջ���򷵻�TRUE,���򷵻�FALSE
bool StackEmpty(const SeqStack* ps)
{
	assert(ps != NULL);
	return StackLength(ps) == 0;
}
//��ջΪ��ջ���򷵻�TRUE,���򷵻�FALSE
bool StackFull(const SeqStack* ps)
{
	assert(ps != NULL);
	return StackLength(ps) == ps->stacksize;
}
//��ջval , valΪջ������Ԫ�� 
Status Push(SeqStack* ps, SElemType val)
{
	if (StackFull(ps) && !IncMem(ps))
	{
		return ERROR;
	}
	*ps->top = val;
	ps->top += 1;
	return OK;
}
//��ջ���գ�����pVal����ջ��Ԫ�أ�������OK,���򷵻�ERROR
Status GetTop(const SeqStack* ps, SElemType* pval)
{
	assert(ps != NULL);
	if (StackEmpty(ps)) { return ERROR; }
	*pval = *(ps->top - 1);
	return OK;
}
//Status GetTop(const SeqStack *ps,ElemType &val);
//��ջ���գ���ɾ��ջ��Ԫ�أ���pval������ֵ,������OK,���򷵻�ERROR 
Status Pop(SeqStack* ps, SElemType* pval)
{
	assert(ps != NULL);
	if (StackEmpty(ps)) { return ERROR; }
	*pval = *(ps->top - 1);
	ps->top -= 1;
	return OK;
}
//Status Pop(SeqStack *ps,SElemType &val);
//��ӡջԪ��
void PrintStack(const SeqStack* ps)
{
	assert(ps != NULL);
	for (SElemType* p = ps->base; p < ps->top; p++)
	{
		printf("%d ", *p);
	}
	printf("\n");
}
//ʵ����ջ����һ�����洢�ռ�Ļ�������
//��ʼ����ջ
Status InitStack2(SeqStack* ps)
{
	assert(ps != NULL);
	int total = sizeof(SElemType) * STACK_INIT_SIZE * 2;
	ps->base = ps->top = BuyMem(total);
	ps->stacksize = STACK_INIT_SIZE * 2;
	return OK;
}
//������ջ
void DestroyStack2(SeqStack* ps)
{
	assert(ps != NULL);
	FreeMem(ps->base); // FreeMem(ps->top);	 // error
	ps->base = ps->top = NULL;
	ps->stacksize = 0;
}
//�ÿ���ջ
void ClearStack2(SeqStack* ps, int stackNumber)
{
	assert(ps != NULL);
	if (stackNumber == 1)
	{
		ps->top = ps->base + ps->stacksize / 2;
	}
	else if (stackNumber == 2)
	{
		ps->top = ps->base + ps->stacksize;
	}
}
//������ջ��Ԫ�ظ���������ջ�ĳ���
int StackLength2(const SeqStack* ps, int stackNumber)
{
	assert(ps != NULL);
	if (stackNumber == 1)
	{
		return ps->top - ps->base;
	}
	else if (stackNumber == 2)
	{
		return ps->base + ps->stacksize - ps->top;
	}
	return -1;
}
//����ջΪ��ջ���򷵻�TRUE,���򷵻�FALSE
bool StackEmpty2(const SeqStack* ps, int stackNumber)
{
	assert(ps != NULL);
	if (stackNumber == 1)
	{
		return StackLength2(ps, 1) == 0;
	}
	else if (stackNumber == 2)
	{
		return StackLength2(ps, 2) == 0;
	}
	return false;
}
//����ջΪ��ջ���򷵻�TRUE,���򷵻�FALSE
bool StackFull2(const SeqStack* ps)
{
	assert(ps != NULL);
	return StackLength2(ps, 1) == ps->stacksize / 2;
}
//��ջval , valΪջ������Ԫ��
Status Push2(SeqStack* ps, SElemType val, int stackNumber)
{
	if (StackFull2(ps) && !IncMem(ps))
	{
		return ERROR;
	}
	if (stackNumber == 1)
	{
		*ps->top = val;
		ps->top += 1;
	}
	else if (stackNumber == 2)
	{
		*(ps->top) = val;
		ps->top -= 1;
	}
	return OK;
}