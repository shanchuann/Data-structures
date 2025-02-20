#ifndef AVLTREE_H
#define AVLTREE_H

typedef int KeyType;
typedef struct AVLNode
{
	struct AVLNode* leftchild;
	struct AVLNode* parent;
	struct AVLNode* rightchild;
	int balance;  // -1, 0, 1;
	KeyType key;
}AVLNode;
typedef struct
{
	AVLNode* root;
	int cursize;
}AVLTree;

extern void InitAVLTree(AVLTree* ptree);
extern void DestroyAVLTree(AVLTree* ptree);
extern void ClearAVLTree(AVLTree* ptree);
extern int GetSize(const AVLTree* ptree);
extern bool IsEmpty(const AVLTree* ptree);
extern AVLNode* FindValue(const AVLTree* ptree, KeyType kx);
extern bool Insert(AVLTree* ptree, KeyType key);
extern bool Remove(AVLTree* ptree, KeyType key);
extern void NiceInOrder(const AVLTree* ptree);
extern void NiceResInOrder(const AVLTree* ptree);

#endif