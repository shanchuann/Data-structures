#include<assert.h>
#include<stdlib.h>  // malloc() free()
#include<string.h>
#include"RBTree.h"

static rb_node* Buynode()
{
	rb_node* s = (rb_node*)malloc(sizeof(rb_node));
	if (NULL == s) exit(1);
	memset(s, 0, sizeof(rb_node));
	s->color = RED;
	return s;
}
static void Freenode(rb_node* p)
{
	free(p);
}

static rb_node* RotateLeft(RBTree* ptree, rb_node* ptr)
{
	rb_node* newroot = ptr->rightchild; //1.1
	newroot->parent = ptr->parent;	//2.1
	ptr->rightchild = newroot->leftchild; //1.2
	if (newroot->leftchild != NULL)
	{
		newroot->leftchild->parent = ptr; //2.2
	}
	newroot->leftchild = ptr;	 //1.3
	if (ptr == ptree->root)
	{
		ptree->root = newroot;
	}
	else
	{
		if (ptr == ptr->parent->leftchild)
		{
			ptr->parent->leftchild = newroot;
		}
		else
		{
			ptr->parent->rightchild = newroot;
		}
	}
	ptr->parent = newroot;	//2.3
	return newroot;
}

static rb_node* RotateRight(RBTree* ptree, rb_node* ptr)
{
	rb_node* newroot = ptr->leftchild; //a
	newroot->parent = ptr->parent; //1 b
	ptr->leftchild = newroot->rightchild;  //a
	if (newroot->rightchild != NULL)
	{
		newroot->rightchild->parent = ptr; // 2	b
	}
	newroot->rightchild = ptr;	  //a

	if (ptr == ptree->root) 	 //c ptr->parent == NULL:
	{
		ptree->root = newroot;
	}
	else
	{
		if (ptr->parent->leftchild == ptr)
		{
			ptr->parent->leftchild = newroot;
		}
		else
		{
			ptr->parent->rightchild = newroot;
		}
	}
	ptr->parent = newroot; //b
	return newroot;
}
void InitRBTree(RBTree* ptree)
{
	assert(ptree != NULL);
	rb_node* s = Buynode();
	s->color = BLACK;
	ptree->root = ptree->NIL = s;
	ptree->cursize = 0;
}
void ClearRBTree(RBTree* ptree);
void DestroyRBTree(RBTree* ptree);
int GetSize(const RBTree* ptree)
{
	assert(ptree != NULL);
	return ptree->cursize;
}
bool IsEmpty(const RBTree* ptree)
{
	assert(ptree != NULL);
	return GetSize(ptree) == 0;
}
rb_node* FindKey(const RBTree* ptree, KeyType key)
{
	assert(ptree != NULL);
	rb_node* p = ptree->root;
	while (p != ptree->NIL && p->key != key)
	{
		p = key > p->key ? p->rightchild : p->leftchild;
	}
	if (p == ptree->NIL) { p = NULL; }
	return p;
}
static void Adjust_rb(RBTree* ptree, rb_node* ptr)
{
	while (ptr->parent != NULL && ptr->parent->color == RED)
	{
		// right
		rb_node* Y = NULL;
		if (ptr->parent->parent->rightchild == ptr->parent)
		{
			Y = ptr->parent->parent->leftchild;
			if (Y->color == RED)
			{
				Y->color = BLACK;
				ptr->parent->color = BLACK;
				ptr->parent->parent->color = RED;
				ptr = ptr->parent->parent;
			}
			else  // Y->color = BLACK
			{
				if (ptr->parent->leftchild == ptr)
				{
					ptr = ptr->parent;
					RotateRight(ptree, ptr);
				}
				ptr->parent->color = BLACK;
				ptr->parent->parent->color = RED;
				RotateLeft(ptree, ptr->parent->parent);
			}
		}
		else  // left;
		{

		}
	}
	ptree->root->color = BLACK;
}	// AVLTree => RBTree;
bool Insert(RBTree* ptree, KeyType key)
{
	assert(ptree != NULL);
	rb_node* pa = NULL;
	rb_node* p = ptree->root; //
	while (p != ptree->NIL && p->key != key)
	{
		pa = p;
		p = key > p->key ? p->rightchild : p->leftchild;
	}
	if (p != ptree->NIL && p->key == key) return false;
	rb_node* s = Buynode();  // RED;
	s->key = key;
	s->leftchild = s->rightchild = ptree->NIL;
	s->parent = pa;
	if (NULL == pa)
	{
		ptree->root = s;
		s->color = BLACK;
	}
	else
	{
		if (pa->key > s->key)
		{
			pa->leftchild = s;
		}
		else
		{
			pa->rightchild = s;
		}
	}
	Adjust_rb(ptree, s);
	ptree->cursize += 1;
	return true;
}
bool Remove(RBTree* ptree, KeyType key);
void NiceInOrder(RBTree* ptree);