#ifndef RBTREE_H
#define RBTREE_H

typedef enum { BLACK, RED } ColorType;
typedef int KeyType;
typedef struct rb_node
{
	rb_node* leftchild;
	rb_node* parent;
	rb_node* rightchild;
	ColorType color;  // 0 1
	KeyType key;
}rb_node;
typedef struct
{
	rb_node* root; //BLACK;
	rb_node* NIL;  //BLACK;
	int cursize;
}RBTree;

void InitRBTree(RBTree* ptree);
void ClearRBTree(RBTree* ptree);
void DestroyRBTree(RBTree* ptree);
int GetSize(const RBTree* ptree);
bool IsEmpty(const RBTree* ptree);
rb_node* FindKey(const RBTree* ptree, KeyType key);
bool Insert(RBTree* ptree, KeyType key);
bool Insert(RBTree* ptree, KeyType key);
bool Remove(RBTree* ptree, KeyType key);
void NiceInOrder(RBTree* ptree);
#endif