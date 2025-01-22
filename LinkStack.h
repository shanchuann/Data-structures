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
	PStackNode top; //ջ��ָ��
	int cursize; //����Ԫ�ظ���
}LinkStack;

//����һ����ջ
Status InitStack(LinkStack* ps);
//����ջ
void DestroyStack(LinkStack* ps);
//��Ϊ��ջ
void ClearStack(LinkStack* ps);
//����ջ��Ԫ�ظ�������ջ�ĳ���
int StackLength(const LinkStack* ps);
//��ջΪ��ջ���򷵻�TRUE,���򷵻�FALSE
bool StackEmpty(const LinkStack* ps);
//��ջval , valΪջ������Ԫ��
Status Push(LinkStack* ps, SElemType val);
//��ջ���գ�����pVal����ջ��Ԫ�أ�������OK,���򷵻�ERROR
Status GetTop(const LinkStack* ps, SElemType* pval);
//��ջ���գ���ɾ��ջ��Ԫ�أ���pval������ֵ,������OK,���򷵻�ERROR
Status Pop(LinkStack* ps, SElemType* pval);

#endif