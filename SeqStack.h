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
	SElemType* base; // ջ��ָ��
	SElemType* top;  // ջ��ָ��
	int  stacksize;  // ջ�ĵ�ǰ�������
}SeqStack;

//����һ����ջ 
Status InitStack(SeqStack* ps);
//����ջ
void DestroyStack(SeqStack* ps);
//��Ϊ��ջ
void ClearStack(SeqStack* ps);
//����ջ��Ԫ�ظ�������ջ�ĳ���
int StackLength(const SeqStack* ps);
//��ջΪ��ջ���򷵻�TRUE,���򷵻�FALSE
bool StackEmpty(const SeqStack* ps);
//��ջΪ��ջ���򷵻�TRUE,���򷵻�FALSE
bool StackFull(const SeqStack* ps);
//��ջval , valΪջ������Ԫ�� 
Status Push(SeqStack* ps, SElemType val);
//��ջ���գ�����pVal����ջ��Ԫ�أ�������OK,���򷵻�ERROR
Status GetTop(const SeqStack* ps, SElemType* pval);
//Status GetTop(const SeqStack *ps,ElemType &val);
//��ջ���գ���ɾ��ջ��Ԫ�أ���pval������ֵ,������OK,���򷵻�ERROR 
Status Pop(SeqStack* ps, SElemType* pval);
//Status Pop(SeqStack *ps,SElemType &val);
//��ӡջԪ��
void PrintStack(const SeqStack* ps);
//ʵ����ջ����һ�����洢�ռ�Ļ�������
//��ʼ����ջ
Status InitStack2(SeqStack* ps);
//������ջ
void DestroyStack2(SeqStack* ps);
//�ÿ���ջ
void ClearStack2(SeqStack* ps, int stackNumber);
//������ջ��Ԫ�ظ���������ջ�ĳ���
int StackLength2(const SeqStack* ps, int stackNumber);
//����ջΪ��ջ���򷵻�TRUE,���򷵻�FALSE
bool StackEmpty2(const SeqStack* ps, int stackNumber);
//����ջΪ��ջ���򷵻�TRUE,���򷵻�FALSE
bool StackFull2(const SeqStack* ps);
//��ջval , valΪջ������Ԫ��
Status Push2(SeqStack* ps, SElemType val, int stackNumber);
#endif 
