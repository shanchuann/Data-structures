#ifndef MBTREE_H
#define MBTREE_H
#define M 5   // 
#define MAXELEM (M-1)  //4
#define MINELEM (M/2)  //2  brch leaf  2 ... 4
typedef char KeyType;
typedef struct {} Record;
typedef struct
{
	KeyType key;
	Record* recptr;
}ElemType; // { key : recptr }

typedef struct BNode
{
	int num;  // key num;
	struct BNode* parent;
	ElemType data[M + 1];
	struct BNode* sub[M + 1];
}BNode;
typedef struct
{
	BNode* root;
	int cursize;
}BTree;

typedef struct
{
	BNode* pnode;
	int index;
	bool tag; // true; false;
}Result;

extern void InitBTree(BTree* ptree);
extern void DestroyBTree(BTree* ptree);
extern void ClearBTree(BTree* ptree);
extern int GetSize(const BTree* ptree);
extern bool IsEmpty(const BTree* ptree);
extern Result FindValue(const BTree* ptree, KeyType key);
extern bool Insert(BTree* ptree, ElemType val);
extern bool Remove(BTree* ptree, KeyType key);
extern void PrintInfo(const BTree* ptree);

#endif 