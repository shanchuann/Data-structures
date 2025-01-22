#include"BinarySortTree.h"
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

static BstNode* Buynode()
{
	BstNode* s = (BstNode*)malloc(sizeof(BstNode));
	if (NULL == s) exit(1);
	memset(s, 0, sizeof(BstNode));
	return s;
}
static void Freenode(BstNode* p)
{
	free(p);
}

void InitBSTree(BSTree* ptree)
{
	assert(ptree != NULL);
	ptree->root = NULL;
	ptree->cursize = 0;
}

void DestroyBSTree(BSTree* ptree)
{
	assert(ptree != NULL);
	BstNode* p = ptree->root;
	while (p != NULL)
	{
		if (p->leftchild != NULL)
		{
			p = p->leftchild;
		}
		else if (p->rightchild != NULL)
		{
			p = p->rightchild;
		}
		else
		{
			BstNode* pa = p->parent;
			if (pa == NULL)
			{
				Freenode(p);
				ptree->root = NULL;
				ptree->cursize = 0;
				break;
			}
			if (p == pa->leftchild)
			{
				pa->leftchild = NULL;
			}
			else
			{
				pa->rightchild = NULL;
			}
			Freenode(p);
			p = pa;
		}
	}
}
void ClearBSTree(BSTree* ptree)
{
	DestroyBSTree(ptree);
	InitBSTree(ptree);
}
int GetSize(const BSTree* ptree)
{
	assert(ptree != NULL);
	return ptree->cursize;
}
bool IsEmpty(const BSTree* ptree)
{
	assert(ptree != NULL);
	return GetSize(ptree) == 0;
}
BstNode* FindValue(const BSTree* ptree, KeyType key)
{
	assert(ptree != NULL);
	BstNode* p = ptree->root;
	while (p != NULL && p->key != key)
	{
		p = (key > p->key) ? p->rightchild : p->leftchild;
	}
	return p;
}

bool Insert(BSTree* ptree, KeyType key)
{
	assert(ptree != NULL);
	if (NULL == ptree->root)
	{
		BstNode* s = Buynode();
		s->key = key;
		ptree->root = s;
		ptree->cursize = 1;
		return true;
	}
	BstNode* pa = NULL;
	BstNode* p = ptree->root;
	while (p != NULL && p->key != key)
	{
		pa = p;
		p = (key > p->key) ? p->rightchild : p->leftchild;
	}
	if (NULL != p && p->key == key) return false;
	BstNode* s = Buynode();
	s->key = key;
	s->parent = pa;
	if (s->key < pa->key)
	{
		pa->leftchild = s;
	}
	else
	{
		pa->rightchild = s;
	}
	ptree->cursize += 1;
	return true;
}

static BstNode* First(BstNode* p)
{
	if (p == NULL) return NULL;
	while (p->leftchild != NULL)
	{
		p = p->leftchild;
	}
	return p;
}
static BstNode* Next(BstNode* ptr)
{
	if (ptr == NULL) return NULL;
	if (ptr->rightchild != NULL)
	{
		return First(ptr->rightchild);
	}
	else
	{
		BstNode* pa = ptr->parent;
		while (pa != NULL && pa->leftchild != ptr)
		{
			ptr = pa;
			pa = pa->parent;
		}
		return pa;
	}
}
void NiceInOrder(const BSTree* ptree)
{
	assert(ptree != NULL);
	for (BstNode* p = First(ptree->root); p != NULL; p = Next(p))
	{
		printf("%d ", p->key);
	}
}
static BstNode* Last(BstNode* p)
{
	if (p == NULL) return NULL;
	while (p->rightchild != NULL)
	{
		p = p->rightchild;
	}
	return p;
}
static BstNode* Prev(BstNode* ptr)
{
	if (ptr == NULL) return NULL;
	if (ptr->leftchild != NULL)
	{
		return Last(ptr->leftchild);
	}
	else
	{
		BstNode* pa = ptr->parent;
		while (pa != NULL && pa->rightchild != ptr)
		{
			ptr = pa;
			pa = pa->parent;
		}
		return pa;
	}
}
void NiceResOrder(const BSTree* ptree)
{
	assert(ptree != NULL);
	for (BstNode* p = Last(ptree->root); p != NULL; p = Prev(p))
	{
		printf("%d ", p->key);
	}
}
bool Remove(BSTree* ptree, KeyType key)
{
	assert(ptree != NULL);
	if (NULL == ptree->root) return false;
	BstNode* p = FindValue(ptree,key);
	if (NULL == p) return false;
	if (p->leftchild == NULL && p->rightchild == NULL)
	{
		BstNode* pa = p->parent;
		if (p == pa->leftchild) pa->leftchild = NULL;
		else pa->rightchild = NULL;
		Freenode(p);
		ptree->cursize--;
		return true;
	}
	if (p->leftchild != NULL && p->rightchild != NULL)
	{
		BstNode* q = p->leftchild;
		while (q->rightchild != NULL)
		{
			q = q->rightchild;
		}
		p->key = q->key;
		BstNode* qa = q->parent;
		if (q == qa->leftchild) qa->leftchild = q->leftchild;
		else qa->rightchild = q->leftchild;
		if (q->leftchild != NULL) q->leftchild->parent = qa;
		Freenode(q);
		ptree->cursize--;
		return true;
	}
	if (p->leftchild != NULL || p->rightchild != NULL)
	{
		BstNode* pa = p->parent;
		BstNode* pc = (p->leftchild != NULL) ? p->leftchild : p->rightchild;
		if (p == pa->leftchild) pa->leftchild = pc;
		else pa->rightchild = pc;
		pc->parent = pa;
		Freenode(p);
		ptree->cursize--;
		return true;
	}
}