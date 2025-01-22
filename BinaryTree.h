#ifndef BINARY_TERR_H
#define BINARY_TERR_H
typedef char ElemType;
typedef struct BtNode
{
	BtNode* leftchild;
	BtNode* rightchild;
	ElemType data;
}BtNode, * BinaryTree;

void InitBinaryTree(BinaryTree* proot);
void DestroyBinaryTree(BinaryTree p);
void ClearBinaryTree(BinaryTree p);
int GetSize(const BinaryTree p);
int GetDepth(const BinaryTree p);
bool IsEmpty(const BinaryTree p);
BtNode* CreateBinTree();
void PreOrder(const BinaryTree p);
void InOrder(const BinaryTree p);
void LastOrder(const BinaryTree p);
void LevelOrder(const BinaryTree p);
#endif
//#ifndef BINARY_TERR_H
//#define BINARY_TERR_H
//typedef char ElemType;
//typedef struct BtNode
//{
//	BtNode* leftchild;
//	BtNode* rightchild;
//	ElemType data;
//}BtNode, *BinaryTree;
//
//void InitBinaryTree(BinaryTree *proot);
//void DestroyBinaryTree(BinaryTree p);
//void ClearBinaryTree(BinaryTree p);
//int GetSize(const BinaryTree p);
//int GetDepth(const BinaryTree p);
//bool IsEmpty(const BinaryTree p);
//BtNode* CreateBinTree();
//void PreOrder(const BinaryTree p);
//void InOrder(const BinaryTree p);
//void LastOrder(const BinaryTree p);
//void LevelOrder(const BinaryTree p);
//void Z_LevelOrder(const BinaryTree p);
//void NiceInOrder(const BinaryTree p);
//void NicePreOrder(const BinaryTree p);
//void NiceLastOrder(const BinaryTree p);
//void StkNiceLastOrder(const BinaryTree p);
//void StkNiceLastOrder(const BinaryTree p);
//bool IsFullBinaryTree(const BinaryTree p);
//bool IsCompBinaryTree(const BinaryTree p);
//bool IsBSTree(const BinaryTree p);
//bool IsBalanceBinaryTree(const BinaryTree p);
//BtNode* FindValue(const BinaryTree p, ElemType val);
//BtNode* FindParent(const BinaryTree p, const BtNode *ptr);
//BtNode* FindGParent(const BinaryTree p, const BtNode* pa,const BtNode *pb);
//BtNode* SeqCreateBinTree(const ElemType *ps);
//BtNode* CreatBinaryTreePI(const ElemType* pstr, const ElemType* istr, int n);
//BtNode* CreatBinaryTreeIL(const ElemType* pstr, const ElemType* istr, int n);
//#endif