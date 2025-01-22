#ifndef BINARYSORTTREE_H
#define BINARYSORTTREE_H
typedef int KeyType;
typedef struct BstNode // BinartSortTreeNode
{
	struct BstNode* leftchild;
	struct BstNode* parent;
	struct BstNode* rightchild;
	KeyType key;
}BstNode;
typedef struct
{
	BstNode* root;
	int cursize;
}BSTree;

void InitBSTree(BSTree* ptree);
void DestroyBSTree(BSTree* ptree);
void ClearBSTree(BSTree* ptree);
int GetSize(const BSTree* ptree);
bool IsEmpty(const BSTree* ptree);
BstNode* FindValue(const BSTree* ptree,KeyType key);
bool Insert(BSTree* ptree, KeyType key);
bool Remove(BSTree* ptree, KeyType key);
void NiceInOrder(const BSTree* ptree);
void NiceResOrder(const BSTree* ptree);
#endif 