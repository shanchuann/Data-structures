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

//构造一个空栈 
Status InitStack(SeqStack* ps)
{
	assert(ps != NULL);
	int total = sizeof(SElemType) * STACK_INIT_SIZE;
	ps->base = ps->top = BuyMem(total);
	ps->stacksize = STACK_INIT_SIZE;
	return OK;
}
//销毁栈
void DestroyStack(SeqStack* ps)
{
	assert(ps != NULL);
	FreeMem(ps->base); // FreeMem(ps->top);	 // error
	ps->base = ps->top = NULL;
	ps->stacksize = 0;
}
//置为空栈
void ClearStack(SeqStack* ps)
{
	assert(ps != NULL);
	ps->top = ps->base;
}
//返回栈的元素个数，即栈的长度
int StackLength(const SeqStack* ps)
{
	assert(ps != NULL);
	return ps->top - ps->base;
}
//若栈为空栈，则返回TRUE,否则返回FALSE
bool StackEmpty(const SeqStack* ps)
{
	assert(ps != NULL);
	return StackLength(ps) == 0;
}
//若栈为满栈，则返回TRUE,否则返回FALSE
bool StackFull(const SeqStack* ps)
{
	assert(ps != NULL);
	return StackLength(ps) == ps->stacksize;
}
//入栈val , val为栈顶数据元素 
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
//若栈不空，则用pVal返回栈顶元素，并返回OK,否则返回ERROR
Status GetTop(const SeqStack* ps, SElemType* pval)
{
	assert(ps != NULL);
	if (StackEmpty(ps)) { return ERROR; }
	*pval = *(ps->top - 1);
	return OK;
}
//Status GetTop(const SeqStack *ps,ElemType &val);
//若栈不空，则删除栈顶元素，用pval返回其值,并返回OK,否则返回ERROR 
Status Pop(SeqStack* ps, SElemType* pval)
{
	assert(ps != NULL);
	if (StackEmpty(ps)) { return ERROR; }
	*pval = *(ps->top - 1);
	ps->top -= 1;
	return OK;
}
//Status Pop(SeqStack *ps,SElemType &val);
//打印栈元素
void PrintStack(const SeqStack* ps)
{
	assert(ps != NULL);
	for (SElemType* p = ps->base; p < ps->top; p++)
	{
		printf("%d ", *p);
	}
	printf("\n");
}
//实现两栈共享一连续存储空间的基本运算
//初始化两栈
Status InitStack2(SeqStack* ps)
{
	assert(ps != NULL);
	int total = sizeof(SElemType) * STACK_INIT_SIZE * 2;
	ps->base = ps->top = BuyMem(total);
	ps->stacksize = STACK_INIT_SIZE * 2;
	return OK;
}
//销毁两栈
void DestroyStack2(SeqStack* ps)
{
	assert(ps != NULL);
	FreeMem(ps->base); // FreeMem(ps->top);	 // error
	ps->base = ps->top = NULL;
	ps->stacksize = 0;
}
//置空两栈
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
//返回两栈的元素个数，即两栈的长度
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
//若两栈为空栈，则返回TRUE,否则返回FALSE
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
//若两栈为满栈，则返回TRUE,否则返回FALSE
bool StackFull2(const SeqStack* ps)
{
	assert(ps != NULL);
	return StackLength2(ps, 1) == ps->stacksize / 2;
}
//入栈val , val为栈顶数据元素
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