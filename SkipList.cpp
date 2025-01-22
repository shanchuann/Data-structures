#include"SkipList.h"
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
static int randomLevel()
{
	//MAX_LEVEL
	//return rand() % MAX_LEVEL + 1;// 0 5 
	srand(time(NULL));
	int level = 0;
	while (rand() < RAND_MAX / 2 && level < MAX_LEVEL)
	{
		++level;
	}
	return level;
}
static SkipListNode* Buynode(int level)
{
	size_t total = sizeof(SkipListNode) + sizeof(SkipListNode*) * (level + 1);
	SkipListNode* s = (SkipListNode*)malloc(total);
	if (NULL == s) exit(1);
	memset(s, 0, total);
	return s;
}
static void Freenode(SkipListNode* p)
{
	free(p);
}

void InitSkipList(SkipList* plist)
{
	assert(plist != NULL);
	plist->cursize = 0;
	plist->curLevel = 1;
	plist->maxLevel = MAX_LEVEL;
	plist->head = plist->tail = Buynode(plist->maxLevel);
}
void DestroySkipList(SkipList* plist)
{
	assert(plist != NULL);
}
void ClearSkipList(SkipList* plist)
{
	assert(plist != NULL);
}
int GetSize(const SkipList* plist)
{
	assert(plist != NULL);
	return plist->cursize;
}
bool IsEmpty(const SkipList* plist)
{
	assert(plist != NULL);
	return plist->cursize == 0;
}
SkipListNode* SearchKey(const SkipList* plist, KeyType key)
{
	assert(plist != NULL);
	SkipListNode* p = plist->head;
	for (int i = plist->curLevel; i >= 0; --i)
	{
		while (p->backward[i] != NULL && p->backward[i]->key < key)
		{
			p = p->backward[i];
		}
	}
	p = p->backward[0];
	if (p != NULL && p->key != key)
	{
		p = NULL;
	}
	return p;
}
bool InsertNode(SkipList* plist, KeyType key)
{
	assert(plist != NULL);
	bool res = false;
	SkipListNode* update[MAX_LEVEL + 1] = { 0 };
	SkipListNode* p = plist->head;
	for (int i = plist->curLevel; i >= 0; --i)
	{
		while (p->backward[i] != NULL && p->backward[i]->key < key)
		{
			p = p->backward[i];
		}
		update[i] = p;
	}
	p = p->backward[0];
	if (p == NULL || p->key != key)
	{
		int level = randomLevel();
		if (level > plist->curLevel)
		{
			for (int i = plist->curLevel + 1; i <= level; ++i)
			{
				update[i] = plist->head;
			}
			plist->curLevel = level;
		}
		SkipListNode * newnode = Buynode(level);
		newnode->key = key;
		for (int i = 0; i <= level; i++)
		{
			newnode->backward[i] = update[i]->backward[i];
			update[i]->backward[i] = newnode;
		}
		plist->cursize++;
		res = true;
	}
	return res;
}
bool RmoveNode(SkipList* plist, KeyType key)
{
	assert(plist != NULL);
	bool res = false;
	SkipListNode* update[MAX_LEVEL + 1] = { 0 };
	SkipListNode* p = plist->head;
	for (int i = plist->curLevel; i >= 0; --i)
	{
		while (p->backward[i] != NULL && p->backward[i]->key < key)
		{
			p = p->backward[i];
		}
		update[i] = p;
	}
	p = p->backward[0];
	if (p != NULL && p->key == key)
	{
		for (int i = 0; i <= plist->curLevel; i++)
		{
			if (update[i]->backward[i] == p)
			{
				update[i]->backward[i] = p->backward[i];
			}
		}
		Freenode(p);
		while (plist->curLevel > 1 && plist->head->backward[plist->curLevel] == NULL)
		{
			--plist->curLevel;
		}
		plist->cursize--;
		res = true;
	}
	return res;
}
void PrintSkip(const SkipList* plist)
{
	assert(plist != NULL);
	for (int i = 0; i <= plist->curLevel; i++)
	{
		SkipListNode* p = plist->head->backward[i];
		printf("level %d: ", i);
		while (p != NULL)
		{
			printf("%d ", p->key);
			p = p->backward[i];
		}
		printf("\n");
	}
}