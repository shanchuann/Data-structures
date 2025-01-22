#ifndef LINKSTACK_H
#define LINKSTACK_H

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int SElemType;
typedef struct StackNode
{
	SElemType data;
	struct StackNode* next;
}StackNode, * PStackNode;
typedef struct
{
	PStackNode top; //栈顶指针
	int cursize; //数据元素个数
}LinkStack;

//构造一个空栈
Status InitStack(LinkStack* ps);
//销毁栈
void DestroyStack(LinkStack* ps);
//置为空栈
void ClearStack(LinkStack* ps);
//返回栈的元素个数，即栈的长度
int StackLength(const LinkStack* ps);
//若栈为空栈，则返回TRUE,否则返回FALSE
bool StackEmpty(const LinkStack* ps);
//入栈val , val为栈顶数据元素
Status Push(LinkStack* ps, SElemType val);
//若栈不空，则用pVal返回栈顶元素，并返回OK,否则返回ERROR
Status GetTop(const LinkStack* ps, SElemType* pval);
//若栈不空，则删除栈顶元素，用pval返回其值,并返回OK,否则返回ERROR
Status Pop(LinkStack* ps, SElemType* pval);

#endif