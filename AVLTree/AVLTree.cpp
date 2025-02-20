#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdio.h>
#include<stdbool.h>
#include"AVLTree.h"

static AVLNode* Buynode()
{
	AVLNode* newnode = (AVLNode*)malloc(sizeof(AVLNode));
	if (newnode == NULL)
	{
		fprintf(stderr, "malloc failed\n");
		exit(1);
	}
	memset(newnode, 0, sizeof(AVLNode));
	return newnode;
}
static void Freenode(AVLNode* ptr)
{
	free(ptr);
}
static AVLNode* RotateLeft(AVLTree* ptree, AVLNode* ptr)
{
	assert(ptree != NULL);
	AVLNode* newroot = ptr->rightchild;//1.1
	newroot->parent = ptr->parent;	//2.1
	ptr->rightchild = newroot->leftchild; //1.2
	if (newroot->leftchild != NULL)
	{
		newroot->leftchild->parent = ptr;//2.2
	}
	newroot->leftchild = ptr;	 //1.3
	if (ptr == ptree->root)
	{
		ptree->root = newroot;
	}
	else
	{
		if (ptr == ptr->parent->leftchild)
		{
			ptr->parent->leftchild = newroot;
		}
		else
		{
			ptr->parent->rightchild = newroot;
		}
	}
	ptr->parent = newroot;	 // 2.3
	return newroot;
}
static AVLNode* RotateRight(AVLTree* ptree, AVLNode* ptr)
{
	assert(ptree != NULL);
	AVLNode* newroot = ptr->leftchild;
	newroot->parent = ptr->parent;
	ptr->leftchild = newroot->rightchild;
	if (newroot->rightchild != NULL)
	{
		newroot->rightchild->parent = ptr;
	}
	newroot->rightchild = ptr;
	if (ptr == ptree->root)
	{
		ptree->root = newroot;
	}
	else
	{
		if (ptr == ptr->parent->leftchild)
		{
			ptr->parent->leftchild = newroot;
		}
		else
		{
			ptr->parent->rightchild = newroot;
		}
	}
	ptr->parent = newroot;
	return newroot;
}

static void LeftBalance(AVLTree* ptree, AVLNode* ptr)
{
	AVLNode* subleft = ptr->leftchild, * subright = NULL;
	switch (subleft->balance)
	{
	case 0:
		fprintf(stderr, "left balance \n");
		break;
	case -1:
		ptr->balance = 0;
		subleft->balance = 0;
		RotateRight(ptree, ptr);
		break;
	case 1:
		subright = subleft->rightchild;
		switch (subright->balance)
		{
		case 0:
			ptr->balance = 0;
			subleft->balance = 0;
			break;
		case 1:
			ptr->balance = 0;
			subleft->balance = -1;
			break;
		case -1:
			ptr->balance = 1;
			subleft->balance = 0;
			break;
		}
		subright->balance = 0;
		RotateLeft(ptree, ptr->leftchild);
		RotateRight(ptree, ptr);
		break;
	}
}
static void RightBalance(AVLTree* ptree, AVLNode* ptr)
{
	AVLNode* subright = ptr->rightchild, * subleft = NULL;
	switch (subright->balance)
	{
	case 0:
		fprintf(stderr, "right balance \n");
		break;
	case 1:
		ptr->balance = 0;
		subright->balance = 0;
		RotateLeft(ptree, ptr);
		break;
	case -1:
		subleft = subright->leftchild;
		switch (subleft->balance)
		{
		case 0:
			ptr->balance = 0;
			subright->balance = 0;
			break;
		case -1:
			ptr->balance = 0;
			subright->balance = 1;
			break;
		case 1:
			ptr->balance = -1;
			subright->balance = 0;
			break;
		}
		subleft->balance = 0;
		RotateRight(ptree, ptr->rightchild);
		RotateLeft(ptree, ptr);
		break;
	}
}
static void ADjust_AVL(AVLTree* ptree, AVLNode* ptr)
{
	assert(ptree != NULL);
	AVLNode* pa = ptr->parent;
	bool tag = 1;
	while (pa != NULL && tag)
	{
		if (pa->leftchild == ptr)
		{
			switch(pa->balance)
			{
			case 0:
				pa->balance = -1;
				break;
			case 1:
				pa->balance = 0;
				tag = 0;
				break;
			case -1:
				LeftBalance(ptree, pa);
				tag = 0;
				break;
			}
		}
		else
		{
			switch(pa->balance)
			{
			case 0:
				pa->balance = 1;
				break;
			case -1:
				pa->balance = 0;
				tag = 0;
				break;
			case 1:
				RightBalance(ptree, pa);
				tag = 0;
				break;
			}
		}
		ptr = pa;
		pa = pa->parent;
	}
}

void InitAVLTree(AVLTree* ptree)
{
	assert(ptree != NULL);
	ptree->root = NULL;
	ptree->cursize = 0;
}

void DestroyAVLTree(AVLTree* ptree);

void ClearAVLTree(AVLTree* ptree);

int GetSize(const AVLTree* ptree);

bool IsEmpty(const AVLTree* ptree);

AVLNode* FindValue(const AVLTree* ptree, KeyType kx)
{
	assert(ptree != NULL);
	AVLNode* p = ptree->root;
	while (p != NULL && p->key != kx)
	{
		if (kx < p->key)
		{
			p = p->leftchild;
		}
		else
		{
			p = p->rightchild;
		}
	}
	return p;
}
bool Insert(AVLTree* ptree, KeyType key)
{
	assert(ptree != NULL);
	AVLNode* pa = NULL;
	AVLNode* p = ptree->root;
	while (p != NULL && p->key != key)
	{
		pa = p;
		if (key < p->key)
		{
			p = p->leftchild;
		}
		else
		{
			p = p->rightchild;
		}
	}
	if (p != NULL && p->key == key)
	{
		return false;
	}
	AVLNode* s = Buynode();
	s->key = key;
	s->parent = pa;
	s->balance = 0;
	if (pa == NULL)
	{
		ptree->root = s;
	}
	else
	{
		if (key < pa->key)
		{
			pa->leftchild = s;
		}
		else
		{
			pa->rightchild = s;
		}
		s->parent = pa;
	}
	ptree->cursize++;
	ADjust_AVL(ptree, s);
	return true;
}
enum LRTag { DELLEFT, DELRIGHT };
void Del_Adjust(AVLTree* ptree, AVLNode* pa, LRTag tag)
{
	if (NULL == ptree || NULL == pa) return;
	bool shorter = true;
	AVLNode* q = NULL;
	AVLNode* r = NULL;
	while (pa != NULL)
	{
		if (tag == DELLEFT)
		{
			switch (pa->balance)
			{
			case 0: pa->balance = 1; shorter = false; break;
			case -1: pa->balance = 0; break;
			case 1:
				q = pa->rightchild;
				switch (q->balance)
				{
				case 0:
					q->balance = -1;
					pa = RotateLeft(ptree, pa);
					shorter = false;
					break;
				case 1:
					pa->balance = 0;
					q->balance = 0;
					pa = RotateLeft(ptree, pa);
					break;
				case -1:
					r = q->leftchild;
					switch (r->balance)
					{
					case 0: pa->balance = 0; q->balance = 0; break;
					case 1: pa->balance = -1; q->balance = 0; break;
					case -1: pa->balance = 0; q->balance = 1; break;
					}
					r->balance = 0;
					RotateRight(ptree, q);
					pa = RotateLeft(ptree, pa);
					break;
				}

				break;
			}
		}
		else
		{
			switch (pa->balance)
			{
			case 0: pa->balance = -1; shorter = false; break;
			case 1: pa->balance = 0; break;
			case -1:
				break;
			}
		}
		if (!shorter || NULL == pa->parent)	  break;
		else
		{
			if (pa->parent->leftchild == pa)
			{
				tag = DELLEFT;
			}
			else
			{
				tag = DELRIGHT;
			}
			pa = pa->parent;
		}
	}
}
AVLNode* Next(AVLNode* p)
{
	assert(p != NULL);
	AVLNode* q = p->rightchild;
	while (q->leftchild != NULL)
	{
		q = q->leftchild;
	}
	return q;
}
bool Remove(AVLTree* ptree, KeyType key)
{
	assert(ptree != NULL);
	LRTag tag{};
	if (ptree->root == NULL) return false;
	AVLNode* p = FindValue(ptree, key);
	if (NULL == p) return false;
	if (p->leftchild != NULL && p->rightchild != NULL)
	{
		AVLNode* pnx = Next(p);
		p->key = pnx->key;
		p = pnx;
	}
	// p leaf  p one brch;
	AVLNode* pa = p->parent;
	AVLNode* child = (p->leftchild != NULL) ? p->leftchild : p->rightchild;
	if (NULL != child)  child->parent = pa;
	if (NULL == pa)
	{
		ptree->root = child;
	}
	else
	{
		if (pa->leftchild == p)
		{
			pa->leftchild = child;
			tag = DELLEFT;
		}
		else
		{
			pa->rightchild = child;
			tag - DELRIGHT;
		}
	}
	Del_Adjust(ptree, pa, tag);
	Freenode(p);
	ptree->cursize -= 1;
	return true;
}

void NiceInOrder(const AVLTree* ptree)
{
	assert(ptree != NULL);
	AVLNode* p = ptree->root;
	while (p != NULL)
	{
		while (p->leftchild != NULL)
		{
			p = p->leftchild;
		}
		printf("%d ", p->key);
		while (p->rightchild == NULL)
		{
			p = p->parent;
			if (p == NULL) return;
			printf("%d ", p->key);
		}
		p = p->rightchild;
	}
}
