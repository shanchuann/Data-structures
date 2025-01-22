#ifndef SEQSTACK_HPP
#define SEQSTACK_HPP

#define TRUE    1
#define FALSE   0

#define OK      0
#define ERROR           -1
#define INFEASIBLE      -2
#define OVERFLOW        -3

typedef int Status;

#define STACK_INIT_SIZE 10
#define STACKINCREMENT  2
typedef int SElemType;
typedef struct
{
	SElemType* base; // 栈底指针
	SElemType* top;  // 栈顶指针
	int  stacksize;  // 栈的当前最大容量
}SeqStack;

//构造一个空栈 
Status InitStack(SeqStack* ps);
//销毁栈
void DestroyStack(SeqStack* ps);
//置为空栈
void ClearStack(SeqStack* ps);
//返回栈的元素个数，即栈的长度
int StackLength(const SeqStack* ps);
//若栈为空栈，则返回TRUE,否则返回FALSE
bool StackEmpty(const SeqStack* ps);
//若栈为满栈，则返回TRUE,否则返回FALSE
bool StackFull(const SeqStack* ps);
//入栈val , val为栈顶数据元素 
Status Push(SeqStack* ps, SElemType val);
//若栈不空，则用pVal返回栈顶元素，并返回OK,否则返回ERROR
Status GetTop(const SeqStack* ps, SElemType* pval);
//Status GetTop(const SeqStack *ps,ElemType &val);
//若栈不空，则删除栈顶元素，用pval返回其值,并返回OK,否则返回ERROR 
Status Pop(SeqStack* ps, SElemType* pval);
//Status Pop(SeqStack *ps,SElemType &val);
//打印栈元素
void PrintStack(const SeqStack* ps);
//实现两栈共享一连续存储空间的基本运算
//初始化两栈
Status InitStack2(SeqStack* ps);
//销毁两栈
void DestroyStack2(SeqStack* ps);
//置空两栈
void ClearStack2(SeqStack* ps, int stackNumber);
//返回两栈的元素个数，即两栈的长度
int StackLength2(const SeqStack* ps, int stackNumber);
//若两栈为空栈，则返回TRUE,否则返回FALSE
bool StackEmpty2(const SeqStack* ps, int stackNumber);
//若两栈为满栈，则返回TRUE,否则返回FALSE
bool StackFull2(const SeqStack* ps);
//入栈val , val为栈顶数据元素
Status Push2(SeqStack* ps, SElemType val, int stackNumber);
#endif 
