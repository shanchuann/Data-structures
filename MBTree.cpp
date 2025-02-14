#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdio.h>
#include"MBTree.h"
#include"SeqQueue.h"
static BNode* Buynode()
{
	BNode* s = (BNode*)malloc(sizeof(BNode));
	if (NULL == s) exit(EXIT_FAILURE);
	memset(s, 0, sizeof(BNode));
	return s;
}
static void Freenode(BNode* p)
{
	free(p);
}
static  BNode* MakeRoot(ElemType val, BNode* leftsub, BNode* rightsub)
{
	BNode* s = Buynode();
	s->parent = NULL;
	s->num = 1;
	s->data[1] = val;
	s->sub[0] = leftsub;
	if (NULL != leftsub) leftsub->parent = s;
	s->sub[1] = rightsub;
	if (NULL != rightsub) rightsub->parent = s;
	return s;
}
static void InsertElem(BNode* ptr, int pos, ElemType  val, BNode* rightsub)
{
	for (int i = ptr->num; i > pos; --i)
	{
		ptr->data[i + 1] = ptr->data[i];
		ptr->sub[i + 1] = ptr->sub[i];
	}
	ptr->data[pos + 1] = val;
	ptr->sub[pos + 1] = rightsub;
	if (NULL != rightsub)// leaf brch;
	{
		rightsub->parent = ptr;
	}
	ptr->num += 1;
}
static ElemType MoveElem(BNode* ptr, int pos, BNode* rightbro)
{
	for (int i = 0, j = pos + 1; j <= ptr->num; ++i, ++j)
	{
		rightbro->data[i] = ptr->data[j];
		rightbro->sub[i] = ptr->sub[j];
		if (ptr->sub[j] != NULL)
		{
			ptr->sub[j]->parent = rightbro;
		}
	}
	rightbro->parent = ptr->parent;
	ptr->num = rightbro->num = pos;
	return rightbro->data[0];
}
static BNode* Splice(BNode* ptr)
{
	BNode* rightbro = Buynode();
	ElemType val = MoveElem(ptr, MINELEM, rightbro);
	if (ptr->parent == NULL)
	{
		return MakeRoot(val, ptr, rightbro);
	}
	BNode* pa = ptr->parent;
	int pos = pa->num;
	pa->data[0] = val;

	while (val.key < pa->data[pos].key) { --pos; }

	InsertElem(pa, pos, val, rightbro);
	if (pa->num > MAXELEM)
	{
		return Splice(pa);
	}
	else
	{
		return NULL;
	}
}
void InitBTree(BTree* ptree)
{
	assert(ptree != NULL);
	ptree->root = NULL;
	ptree->cursize = 0;
}
void DestroyBTree(BTree* ptree)
{
	assert(ptree != NULL);
}
void ClearBTree(BTree* ptree)
{
	assert(ptree != NULL);
}
int GetSize(const BTree* ptree)
{
	assert(ptree != NULL);
	return ptree->cursize;
}
bool IsEmpty(const BTree* ptree)
{
	assert(ptree != NULL);
	return GetSize(ptree) == 0;
}
Result FindValue(const BTree* ptree, KeyType key)
{
	assert(ptree != NULL);
	Result res = { NULL,-1,false };
	BNode* p = ptree->root;
	while (p != NULL)
	{
		p->data[0].key = key;
		int i = p->num;
		while (key < p->data[i].key) { --i; }
		res.pnode = p;
		res.index = i;
		if (i > 0 && p->data[i].key == key)
		{
			res.tag = true;
			break;
		}
		p = p->sub[i];
	}
	return res;
}
bool Insert(BTree* ptree, ElemType val)
{
	assert(ptree != NULL);
	if (IsEmpty(ptree))
	{// Create Root Node;
		ptree->root = MakeRoot(val, NULL, NULL);
		ptree->cursize = 1;
		return true;
	}
	Result res = FindValue(ptree, val.key);
	if (res.tag) { return false; }
	BNode* ptr = res.pnode;
	int pos = res.index;
	InsertElem(ptr, pos, val, NULL);
	if (ptr->num > MAXELEM)
	{
		BNode* newroot = Splice(ptr);
		if (newroot != NULL)
		{
			ptree->root = newroot;
		}
	}
	ptree->cursize += 1;
	return true;
}
void PrintLevel(const BTree* ptree)
{
	assert(ptree != NULL);
	if (IsEmpty(ptree)) return;
	GenSeqQueue myq;
	int level = 1;
	InitQueue(&myq, sizeof(BNode*));
	EnQueue(&myq, &ptree->root);
	while (!QueueEmpty(&myq))
	{
		printf("level : %d ", level++);
		int n = QueueLength(&myq);
		for (int i = 0; i < n; ++i)
		{
			BNode* ptr = NULL;
			DeQueue(&myq, &ptr);
			printf("num: %d ", ptr->num);
			if (ptr->sub[0] != NULL)
			{
				EnQueue(&myq, &ptr->sub[0]);
			}
			for (int j = 1; j <= ptr->num; ++j)
			{
				if (ptr->sub[j] != NULL)
				{
					EnQueue(&myq, &ptr->sub[j]);
				}
				printf("%c ", ptr->data[j].key);
			}
			printf(" | ");
		}
		printf("\n");
	}
	printf("\n-----------------------------------------\n");
	DestroyQueue(&myq);
}
static BNode* GetLeftSub(BNode* ptr)
{
	while (ptr != NULL && ptr->sub[ptr->num] != NULL) {
		ptr = ptr->sub[ptr->num];
	}
	return ptr;
}
static BNode* GetRightSub(BNode* ptr)
{
	while (ptr != NULL && ptr->sub[0] != NULL) {
		ptr = ptr->sub[0];
	}
	return ptr;
}
static void Del_Brch_Elem(BNode* ptr, int pos)
{
	for (int i = pos; i < ptr->num; ++i)
	{
		ptr->data[i] = ptr->data[i + 1];
		ptr->sub[i] = ptr->sub[i + 1];
	}
	ptr->num -= 1;
}
static void Del_Leaf_Elem(BNode* ptr, int pos)
{
	for (int i = pos; i < ptr->num; ++i)
	{
		ptr->data[i] = ptr->data[i + 1];
		ptr->sub[i] = ptr->sub[i + 1];
	}
	ptr->num -= 1;
}
static BNode* Adjust_Leaf(BNode* ptr)
{
	BNode* pa = ptr->parent;
	int pos = pa->num;
	while (ptr->num < MINELEM)
	{
		while (pos > 0 && pa->sub[pos] != ptr) { --pos; }
		if (pos > 0 && pa->sub[pos - 1]->num > MINELEM)
		{
			BNode* leftbro = pa->sub[pos - 1];
			InsertElem(ptr, 0, leftbro->data[leftbro->num], GetRightSub(leftbro));
			pa->data[pos] = leftbro->data[leftbro->num];
			Del_Brch_Elem(leftbro, leftbro->num);
		}
		else if (pos < pa->num && pa->sub[pos + 1]->num > MINELEM)
		{
			BNode* rightbro = pa->sub[pos + 1];
			InsertElem(ptr, ptr->num, rightbro->data[1], GetLeftSub(rightbro));
			pa->data[pos + 1] = rightbro->data[1];
			Del_Brch_Elem(rightbro, 1);
		}
		else if (pos > 0)
		{
			BNode* leftbro = pa->sub[pos - 1];
			ElemType val = MoveElem(leftbro, leftbro->num, ptr);
			pa->data[pos] = val;
			ptr = leftbro;
		}
		else if (pos < pa->num)
		{
			BNode* rightbro = pa->sub[pos + 1];
			ElemType val = MoveElem(ptr, 1, rightbro);
			pa->data[pos + 1] = val;
		}
		else
		{
			break;
		}
	}
	if (pa->num < MINELEM)
	{
		return Adjust_Leaf(pa);
	}
	else
	{
		return NULL;
	}
}
bool Remove(BTree* ptree, KeyType key)
{
	if (NULL == ptree) return false;
	Result res = FindValue(ptree, key);
	if (!res.tag) return false;
	BNode* ptr = res.pnode;
	int pos = res.index;
	BNode* leftsub = GetLeftSub(ptr->sub[pos - 1]);
	BNode* rightsub = GetRightSub(ptr->sub[pos]);
	if (leftsub != NULL && leftsub->num > MINELEM)
	{
		ptr->data[pos] = leftsub->data[leftsub->num];
		ptr = leftsub;
		pos = leftsub->num;
	}
	else if (rightsub != NULL && rightsub->num > MINELEM)
	{
		ptr->data[pos] = rightsub->data[1];
		ptr = rightsub;
		pos = 1;
	}
	else if (leftsub != NULL)
	{
		ptr->data[pos] = leftsub->data[leftsub->num];
		ptr = leftsub;
		pos = leftsub->num;

	}
	else if (rightsub != NULL)
	{
		ptr->data[pos] = rightsub->data[1];
		ptr = rightsub;
		pos = 1;
	}
	Del_Leaf_Elem(ptr, pos);
	if (ptr->parent == NULL && ptr->num == 0)
	{
		Freenode(ptr);
		ptree->root = NULL;
	}
	else if (ptr->parent != NULL && ptr->num < MINELEM)
	{
		BNode* newroot = Adjust_Leaf(ptr);
		if (newroot != NULL)
		{
			ptree->root = newroot;
		}
	}
	ptree->cursize -= 1;
	return true;
}
void PrintInfo(const BTree* ptree)
{
	assert(ptree != NULL);
}

