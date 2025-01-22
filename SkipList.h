#ifndef SKIP_LIST_HPP
#define SKIP_LIST_HPP
#define MAX_LEVEL 6
typedef int KeyType;
typedef struct SkipListNode
{
	KeyType key;
	struct SkipListNode* backward[];// 1 
}SkipListNode;	 // sizeof(SkipListNode);
typedef struct
{
	struct SkipListNode* head, * tail;
	int cursize;
	int maxLevel;
	int curLevel;
}SkipList;

void InitSkipList(SkipList* plist);
void DestroySkipList(SkipList* plist);
void ClearSkipList(SkipList* plist);
int GetSize(const SkipList* plist);
bool IsEmpty(const SkipList* plist);
SkipListNode* SearchKey(const SkipList* plist, KeyType key);
bool InsertNode(SkipList* plist, KeyType key);
bool RmoveNode(SkipList* plist, KeyType key);
void PrintSkip(const SkipList* plist);


#endif 
