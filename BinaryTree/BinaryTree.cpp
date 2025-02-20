#define _CRT_SECURE_NO_WARNINGS
#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化二叉树
void InitBinaryTree(BinaryTree* proot) {
    *proot = NULL;
}

// 销毁二叉树
void DestroyBinaryTree(BinaryTree p) {
    if (p != NULL) {
        DestroyBinaryTree(p->leftchild);
        DestroyBinaryTree(p->rightchild);
        free(p);
    }
}

// 清空二叉树
void ClearBinaryTree(BinaryTree p) {
    if (p != NULL) {
        ClearBinaryTree(p->leftchild);
        ClearBinaryTree(p->rightchild);
        p->leftchild = p->rightchild = NULL;
    }
}

// 获取二叉树节点个数
int GetSize(const BinaryTree p) {
    if (p == NULL) return 0;
    return GetSize(p->leftchild) + GetSize(p->rightchild) + 1;
}

// 获取二叉树深度
int GetDepth(const BinaryTree p) {
    if (p == NULL) return 0;
    int leftDepth = GetDepth(p->leftchild);
    int rightDepth = GetDepth(p->rightchild);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// 判断二叉树是否为空
bool IsEmpty(const BinaryTree p) {
    return p == NULL;
}

// 创建二叉树（前序遍历方式）
BtNode* CreateBinTree() {
    char ch;
    scanf(" %c", &ch);  // 注意空格，用于跳过空白字符
    if (ch == '#') return NULL;

    BtNode* node = (BtNode*)malloc(sizeof(BtNode));
    if (node == NULL) {
        printf("内存分配失败！\n");
        exit(1);
    }
    node->data = ch;
    node->leftchild = CreateBinTree();
    node->rightchild = CreateBinTree();
    return node;
}

// 前序遍历
void PreOrder(const BinaryTree p) {
    if (p != NULL) {
        printf("%c ", p->data);
        PreOrder(p->leftchild);
        PreOrder(p->rightchild);
    }
}

// 中序遍历
void InOrder(const BinaryTree p) {
    if (p != NULL) {
        InOrder(p->leftchild);
        printf("%c ", p->data);
        InOrder(p->rightchild);
    }
}

// 后序遍历
void LastOrder(const BinaryTree p) {
    if (p != NULL) {
        LastOrder(p->leftchild);
        LastOrder(p->rightchild);
        printf("%c ", p->data);
    }
}

// 层序遍历（使用数组模拟队列）
#define MAX_QUEUE_SIZE 100
void LevelOrder(const BinaryTree p) {
    if (p == NULL) return;

    BinaryTree queue[MAX_QUEUE_SIZE];
    int front = 0, rear = 0;

    queue[rear++] = p;

    while (front < rear) {
        BinaryTree current = queue[front++];
        printf("%c ", current->data);

        if (current->leftchild)
            queue[rear++] = current->leftchild;
        if (current->rightchild)
            queue[rear++] = current->rightchild;
    }
}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//#include<string.h>
//#include "BinaryTree.h"
//#include "GenLinkStack.h"
//#include "SeqQueue.h"
//static BtNode* BuyNode(ElemType val)
//{
//	BtNode* s = (BtNode*)malloc(sizeof(BtNode));
//	assert(s != NULL);
//	s->data = val;
//	s->leftchild = NULL;
//	s->rightchild = NULL;
//	return s;
//}
//void InitBinaryTree(BinaryTree* proot)
//{
//	assert(proot != NULL);
//	*proot = NULL;
//}
//void DestroyBinaryTree(BinaryTree p)
//{
//	if (p == NULL) return;
//	DestroyBinaryTree(p->leftchild);
//	DestroyBinaryTree(p->rightchild);
//	free(p);
//}
//void ClearBinaryTree(BinaryTree p)
//{
//	if (p == NULL) return;
//	ClearBinaryTree(p->leftchild);
//	ClearBinaryTree(p->rightchild);
//	free(p);
//	p = NULL;
//}
//int GetSize(const BinaryTree p)
//{
//	if (p == NULL) return 0;
//	else return 1 + GetSize(p->leftchild) + GetSize(p->rightchild);
//}
//static int Max(int a, int b)
//{
//	return a > b ? a : b;
//}
//int GetDepth(const BinaryTree p)
//{
//	if (p == NULL) return 0;
//	else return 1 + Max(GetDepth(p->leftchild), GetDepth(p->rightchild));
//}
//bool IsEmpty(const BinaryTree p)
//{
//	return p == NULL;
//}
//static BtNode* SeqCBTree(const ElemType* ps)
//{
//	BtNode* s = NULL;
//	if ('#' != *ps)
//	{
//		s = BuyNode(*ps);
//		s->leftchild = SeqCBTree(ps + 1);
//		s->rightchild = SeqCBTree(ps + 1);
//	}
//	return s;
//}
//BtNode* SeqCreateBinTree(const ElemType* ps)
//{
//	if (NULL == ps || '\0' == *ps) return NULL;
//	else return SeqCBTree(ps);
//}
//BtNode* CreateBinTree()
//{
//	BtNode* s = NULL;
//	ElemType ch;
//	scanf("%c", &ch);
//	if (ch != '#')
//	{
//		s = BuyNode(ch); 
//		s->leftchild = CreateBinTree();
//		s->rightchild = CreateBinTree();
//	}
//	return s;
//}
//void PreOrder(const BinaryTree p)
//{
//	if (p != NULL)
//	{
//		printf("%c ", p->data);
//		PreOrder(p->leftchild);
//		PreOrder(p->rightchild);
//	}
//}
//void InOrder(const BinaryTree p)
//{
//	if (p != NULL)
//	{
//		InOrder(p->leftchild);
//		printf("%c ", p->data);
//		InOrder(p->rightchild);
//	}
//}
//void LastOrder(const BinaryTree p)
//{
//	if (p != NULL)
//	{
//		LastOrder(p->leftchild);
//		LastOrder(p->rightchild);
//		printf("%c ", p->data);
//	}
//}
//void LevelOrder(const BinaryTree p)
//{
//	if (p == NULL) return;
//	GenSeqQueue mys;
//	InitQueue(&mys, sizeof(BtNode*));
//	BtNode* ptr = p;
//	EnQueue(&mys, &ptr);
//	while (!QueueEmpty(&mys))
//	{
//		DeQueue(&mys, &ptr);
//		printf("%c ", ptr->data);
//		if (ptr->leftchild != NULL) EnQueue(&mys, &ptr->leftchild);
//		if (ptr->rightchild != NULL) EnQueue(&mys, &ptr->rightchild);
//	}
//	DestroyQueue(&mys);
//}
//void Z_LevelOrder(const BinaryTree p)
//{
//	if (p == NULL) return;
//	GenSeqQueue mys;
//	InitQueue(&mys, sizeof(BtNode*));
//	BtNode* ptr = p;
//	EnQueue(&mys, &ptr);
//	bool flag = true;
//	while (!QueueEmpty(&mys))
//	{
//		int n = QueueLength(&mys);
//		for (int i = 0; i < n; i++)
//		{
//			DeQueue(&mys, &ptr);
//			printf("%c ", ptr->data);
//			if (flag)
//			{
//				if (ptr->leftchild != NULL) EnQueue(&mys, &ptr->leftchild);
//				if (ptr->rightchild != NULL) EnQueue(&mys, &ptr->rightchild);
//			}
//			else
//			{
//				if (ptr->rightchild != NULL) EnQueue(&mys, &ptr->rightchild);
//				if (ptr->leftchild != NULL) EnQueue(&mys, &ptr->leftchild);
//			}
//		}
//		if (flag) printf("\n");
//		else printf("\n");
//		flag = !flag;
//	}
//	DestroyQueue(&mys);
//}
//void NiceInOrder(const BinaryTree p)
//{
//	if (NULL == p) return;
//	GenListStack mys;
//	InitGenListStack(&mys, sizeof(BtNode*));
//	BtNode* ptr = p;
//	while (ptr != NULL || !StackEmpty(&mys))
//	{
//		while (ptr != NULL)
//		{
//			Push(&mys, &ptr);
//			ptr = ptr->leftchild;
//		}
//		Pop(&mys, &ptr);
//		printf("%c ", ptr->data);
//		ptr = ptr->rightchild;
//	}
//	printf("\n");
//	DestroyGenListStack(&mys);
//}
//void NicePreOrder(const BinaryTree p)
//{
//	if (NULL == p) return;
//	GenListStack mys;
//	InitGenListStack(&mys, sizeof(BtNode*));
//	BtNode* ptr = p;
//	while (ptr != NULL || !StackEmpty(&mys))
//	{
//		while (ptr != NULL)
//		{
//			printf("%c ", ptr->data);
//			Push(&mys, &ptr);
//			ptr = ptr->leftchild;
//		}
//		Pop(&mys, &ptr);
//		ptr = ptr->rightchild;
//	}
//	printf("\n");
//	DestroyGenListStack(&mys);
//}
//void NiceLastOrder(const BinaryTree p)
//{
//	if (p == NULL) return;
//	GenListStack mys;
//	InitGenListStack(&mys, sizeof(BtNode*));
//	BtNode* ptr = p;
//	BtNode* tag = NULL;
//	while (ptr != NULL || !StackEmpty(&mys))
//	{
//		while (ptr != NULL)
//		{
//			Push(&mys, &ptr);
//			ptr = ptr->leftchild;
//		}
//		Pop(&mys, &ptr);
//		if (ptr->rightchild == NULL || ptr->rightchild == tag)
//		{
//			printf("%c ", ptr->data);
//			tag = ptr;
//			ptr = NULL;
//		}
//		else
//		{
//			Push(&mys, &ptr);
//			ptr = ptr->rightchild;
//		}
//		printf("%c ", ptr->data);
//		ptr = ptr->rightchild;
//	}
//	printf("\n");
//	DestroyGenListStack(&mys);
//}
//bool IsFullBinaryTree(const BinaryTree p)
//{
//	if (p == NULL) return true;
//	if (p->leftchild == NULL && p->rightchild == NULL) return true;
//	if (p->leftchild != NULL && p->rightchild != NULL)
//	{
//		return IsFullBinaryTree(p->leftchild) && IsFullBinaryTree(p->rightchild);
//	}
//	return false;
//}
//bool IsCompBinaryTree(const BinaryTree p)
//{
//	bool ret = true;
//	if (NULL == p) return ret;
//	GenSeqQueue  myq;
//	InitQueue(&myq, sizeof(struct BtNode*));
//	struct BtNode* ps = NULL;
//	EnQueue(&myq, &p);
//	while (!QueueEmpty(&myq))
//	{
//		DeQueue(&myq, &ps);
//		if (ps == NULL) break;
//		EnQueue(&myq, &ps->leftchild);
//		EnQueue(&myq, &ps->rightchild);
//	}
//	while (!QueueEmpty(&myq))
//	{
//		DeQueue(&myq, &ps);
//		if (ps != NULL) ret = false;
//	}
//	DestroyQueue(&myq);
//	return ret;
//
//}
//bool IsBSTree(const BinaryTree p)
//{
//	if (NULL == p) return true;
//	GenListStack mys;
//	InitGenListStack(&mys, sizeof(BtNode*));
//	BtNode* ptr = p;
//	BtNode* tag = NULL;
//	ElemType pre = '\0';
//	while (ptr != NULL || !StackEmpty(&mys))
//	{
//		while (ptr != NULL)
//		{
//			Push(&mys, &ptr);
//			ptr = ptr->leftchild;
//		}
//		Pop(&mys, &ptr);
//		if (tag != NULL && ptr->data < tag->data) return false;
//		tag = ptr;
//		ptr = ptr->rightchild;
//	}
//	DestroyGenListStack(&mys);
//	return true;
//}
//bool IsBalanceBinaryTree(const BinaryTree p)
//{
//	if (NULL == p) return true;
//	int lh = GetDepth(p->leftchild);
//	int rh = GetDepth(p->rightchild);
//	if (lh - rh > 1 || rh - lh > 1) return false;
//	return IsBalanceBinaryTree(p->leftchild) && IsBalanceBinaryTree(p->rightchild);
//}
//BtNode* FindValue(const BinaryTree p, ElemType val)
//{
//	if (NULL == p) return NULL;
//	if (p->data == val) return p;
//	BtNode* ptr = FindValue(p->leftchild, val);
//	if (ptr != NULL) return ptr;
//	return FindValue(p->rightchild, val);
//}
//BtNode* FindParent(const BinaryTree p, const BtNode* ptr)
//{
//	if (NULL == p || NULL == ptr) return NULL;
//	if (p == ptr) return NULL;
//	GenListStack mys;
//	InitGenListStack(&mys, sizeof(BtNode*));
//	BtNode* tag = NULL;
//	BtNode* parent = NULL;
//	BtNode* temp = p;
//	while (temp != NULL || !StackEmpty(&mys))
//	{
//		while (temp != NULL)
//		{
//			Push(&mys, &temp);
//			temp = temp->leftchild;
//		}
//		Pop(&mys, &temp);
//		if (temp->rightchild == NULL || temp->rightchild == tag)
//		{
//			tag = temp;
//			if (temp->leftchild == ptr || temp->rightchild == ptr)
//			{
//				parent = temp;
//				break;
//			}
//			temp = NULL;
//		}
//		else
//		{
//			Push(&mys, &temp);
//			temp = temp->rightchild;
//		}
//	}
//	DestroyGenListStack(&mys);
//	return parent;
//}
//BtNode* FindGParent(const BinaryTree p, const BtNode* pa, const BtNode* pb)
//{
//	if (NULL == p || NULL == pa || NULL == pb) return NULL;
//	if (pa == pb) return NULL;
//	GenListStack mys;
//	InitGenListStack(&mys, sizeof(BtNode*));
//	BtNode* ptr = p;
//	BtNode* tag = NULL;
//	BtNode* parent = NULL;
//	while (ptr != NULL || !StackEmpty(&mys))
//	{
//		while (ptr != NULL)
//		{
//			Push(&mys, &ptr);
//			ptr = ptr->leftchild;
//		}
//		Pop(&mys, &ptr);
//		if (ptr->rightchild == NULL || ptr->rightchild == tag)
//		{
//			tag = ptr;
//			if (ptr == pa || ptr == pb)
//			{
//				if (parent == NULL) parent = ptr;
//				else return parent;
//			}
//			ptr = NULL;
//		}
//		else
//		{
//			Push(&mys, &ptr);
//			ptr = ptr->rightchild;
//		}
//	}
//	DestroyGenListStack(&mys);
//	return NULL;
//}
//static int FindIstr(const ElemType* istr, int n, ElemType val)
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (val == istr[i]) return i;
//	}
//	return -1;
//}
//static BtNode* CreatPI(const ElemType* pstr, const ElemType* istr, int n)
//{
//	BtNode* s = NULL;
//	s = BuyNode(*pstr);
//	if (n > 0)
//	{
//		s = BuyNode(pstr[0]);
//		int pos = FindIstr(istr,n,pstr[0]);
//		if (-1 == pos) exit(1);
//		s->leftchild = CreatPI(pstr + 1, istr, pos);
//		s->rightchild = CreatPI(pstr + pos + 1, istr + pos + 1, n - pos - 1);
//	}
//	return s;
//}
//BtNode* CreatBinaryTreePI(const ElemType* pstr, const ElemType* istr, int n)
//{
//	if (NULL == pstr || NULL == istr || n <= 0) return NULL;
//	else return CreatPI(pstr, istr, n);
//}
//static BtNode* CreatIL(const ElemType* Istr, const ElemType* Lstr, int n)
//{
//	BtNode* s = NULL;
//	s = BuyNode(Lstr[n - 1]);
//	if (n > 0)
//	{
//		int pos = FindIstr(Istr, n, Lstr[n - 1]);
//		if (-1 == pos) exit(1);
//		s->leftchild = CreatIL(Istr, Lstr, pos);
//		s->rightchild = CreatIL(Istr + pos + 1, Lstr + pos, n - pos - 1);
//	}
//	return s;
//}
//BtNode* CreatBinaryTreeIL(const ElemType* Istr, const ElemType* Lstr, int n)
//{
//	if (NULL == Istr || NULL == Lstr || n <= 0) return NULL;
//	else return CreatIL(Istr, Lstr, n);
//}
//struct StkNode
//{
//	struct BtNode* pnode;
//	int num;
//};
//void StkNiceLastOrder(const BinaryTree p)
//{
//	if (NULL == p) return;
//	GenListStack mys;
//	InitGenListStack(&mys, sizeof(struct StkNode));
//	struct StkNode node = { p,0 };
//	Push(&mys, &node);
//	while (!StackEmpty(&mys))
//	{
//		Pop(&mys, &node);
//		if (++node.num == 3)
//		{
//			printf("%c ", node.pnode->data);
//		}
//		else
//		{
//			Push(&mys, &node);
//			if (node.num == 1 && node.pnode->leftchild != NULL)
//			{
//				struct StkNode leftnode = { node.pnode->leftchild,0 };
//				Push(&mys, &leftnode);
//			}
//			else if (node.num == 2 && node.pnode->rightchild != NULL)
//			{
//				struct StkNode rightnode = { node.pnode->rightchild , 0 };
//				Push(&mys, &rightnode);
//			}
//		}
//	}
//	printf("\n");
//}
//void StkNiceInOrder(const BinaryTree p)
//{
//	if (NULL == p) return;
//	GenListStack mys;
//	InitGenListStack(&mys, sizeof(struct StkNode));
//	struct StkNode node = { p,0 };
//	Push(&mys, &node);
//	while (!StackEmpty(&mys))
//	{
//		Pop(&mys, &node);
//		if (++node.num == 2)
//		{
//			printf("%c ", node.pnode->data);
//		}
//		else
//		{
//			Push(&mys, &node);
//			if (node.num == 1 && node.pnode->leftchild != NULL)
//			{
//				struct StkNode leftnode = { node.pnode->leftchild,0 };
//				Push(&mys, &leftnode);
//			}
//			else if (node.num == 2 && node.pnode->rightchild != NULL)
//			{
//				struct StkNode rightnode = { node.pnode->rightchild , 0 };
//				Push(&mys, &rightnode);
//			}
//		}
//	}
//	printf("\n");
//}