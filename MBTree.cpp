#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"MBTree.h"
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
	s->sub[1] = rightsub;
	if (leftsub != NULL) leftsub->parent = s;
	if (rightsub != NULL) rightsub->parent = s;
	return s;
}
static void InsertElem(BNode* ptr, int pos, ElemType val, BNode* rightsub)
{
	for (int i = ptr->num; i > pos; --i)
	{
		ptr->data[i + 1] = ptr->data[i];
		ptr->sub[i + 1] = ptr->sub[i];
	}
	ptr->data[pos + 1] = val;
	ptr->sub[pos + 1] = rightsub;
	if (rightsub != NULL) rightsub->parent = ptr;
	ptr->num++;
}
ElemType MoveItem(BNode* ptr, int pos, BNode* rightbro)
{
	ElemType val = ptr->data[pos];
	if (rightbro != NULL)
	{
		rightbro->num = MINELEM;
		for (int i = 1; i <= MINELEM; ++i)
		{
			rightbro->data[i] = ptr->data[i + MINELEM];
			rightbro->sub[i] = ptr->sub[i + MINELEM];
			if (rightbro->sub[i] != NULL)
			{
				rightbro->sub[i]->parent = rightbro;
			}
		}
	}
	ptr->num = MINELEM;
	return val;
}
static BNode* Splice(BNode* ptr)
{
	BNode* rightbro = Buynode();
	ElemType val = MoveItem(ptr, MINELEM + 1, rightbro);
	BNode* parent = ptr->parent;
	if (parent == NULL)
	{
		return MakeRoot(val, ptr, rightbro);
	}
	int pos = parent->num;
	while (pos > 0 && parent->sub[pos] != ptr) { --pos; }
	InsertElem(parent, pos, val, rightbro);
	if (parent->num > MAXELEM)
	{
		return Splice(parent);
	}
	return NULL;
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
	return true;
}
bool Remove(BTree* ptree, KeyType key)
{
	assert(ptree != NULL);
}
void PrintInfo(const BTree* ptree)
{
	assert(ptree != NULL);
}