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
ElemType MoveItem(BNode* ptr, int pos, BNode* rigthbro);

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
bool Remove(BTree* ptree, KeyType key);
void PrintInfo(const BTree* ptree)
{
	assert(ptree != NULL);
}

