# BinarySortTree.h

### BinarySortTree.h 文件

这个头文件主要定义了二叉排序树的数据结构和相关函数的声明，起到了对外接口的作用。

```cpp
#ifndef BINARYSORTTREE_H
#define BINARYSORTTREE_H

// 定义键值类型为整型
typedef int KeyType;

// 定义二叉排序树的节点结构
typedef struct BstNode // BinartSortTreeNode
{
    struct BstNode* leftchild;  // 左子节点指针
    struct BstNode* parent;     // 父节点指针
    struct BstNode* rightchild; // 右子节点指针
    KeyType key;                // 节点存储的键值
} BstNode;

// 定义二叉排序树结构
typedef struct
{
    BstNode* root;  // 根节点指针
    int cursize;    // 当前树中节点的数量
} BSTree;

// 以下是二叉排序树操作函数的声明
void InitBSTree(BSTree* ptree);
void DestroyBSTree(BSTree* ptree);
void ClearBSTree(BSTree* ptree);
int GetSize(const BSTree* ptree);
bool IsEmpty(const BSTree* ptree);
BstNode* FindValue(const BSTree* ptree, KeyType key);
bool Insert(BSTree* ptree, KeyType key);
bool Remove(BSTree* ptree, KeyType key);
void NiceInOrder(const BSTree* ptree);
void NiceResOrder(const BSTree* ptree);

#endif
```

### BinarySortTree.cpp 文件

这个源文件实现了 `BinarySortTree.h` 中声明的所有函数，包含了二叉排序树的各种操作的具体实现。

```cpp
#include"BinarySortTree.h"
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

// 静态函数，用于创建一个新的二叉排序树节点
static BstNode* Buynode()
{
    BstNode* s = (BstNode*)malloc(sizeof(BstNode));
    if (NULL == s) exit(1);  // 若内存分配失败，程序退出
    memset(s, 0, sizeof(BstNode));  // 将节点内存清零
    return s;
}

// 静态函数，用于释放一个二叉排序树节点的内存
static void Freenode(BstNode* p)
{
    free(p);
}

// 初始化二叉排序树
void InitBSTree(BSTree* ptree)
{
    assert(ptree != NULL);  // 确保传入的指针不为空
    ptree->root = NULL;     // 根节点置为空
    ptree->cursize = 0;     // 当前节点数量置为0
}

// 销毁二叉排序树
void DestroyBSTree(BSTree* ptree)
{
    assert(ptree != NULL);
    BstNode* p = ptree->root;
    while (p != NULL)
    {
        if (p->leftchild != NULL)
        {
            p = p->leftchild;
        }
        else if (p->rightchild != NULL)
        {
            p = p->rightchild;
        }
        else
        {
            BstNode* pa = p->parent;
            if (pa == NULL)
            {
                Freenode(p);
                ptree->root = NULL;
                ptree->cursize = 0;
                break;
            }
            if (p == pa->leftchild)
            {
                pa->leftchild = NULL;
            }
            else
            {
                pa->rightchild = NULL;
            }
            Freenode(p);
            p = pa;
        }
    }
}

// 清空二叉排序树
void ClearBSTree(BSTree* ptree)
{
    DestroyBSTree(ptree);  // 先销毁树
    InitBSTree(ptree);     // 再初始化树
}

// 获取二叉排序树中节点的数量
int GetSize(const BSTree* ptree)
{
    assert(ptree != NULL);
    return ptree->cursize;
}

// 判断二叉排序树是否为空
bool IsEmpty(const BSTree* ptree)
{
    assert(ptree != NULL);
    return GetSize(ptree) == 0;
}

// 在二叉排序树中查找指定键值的节点
BstNode* FindValue(const BSTree* ptree, KeyType key)
{
    assert(ptree != NULL);
    BstNode* p = ptree->root;
    while (p != NULL && p->key != key)
    {
        p = (key > p->key) ? p->rightchild : p->leftchild;
    }
    return p;
}

// 向二叉排序树中插入一个键值
bool Insert(BSTree* ptree, KeyType key)
{
    assert(ptree != NULL);
    if (NULL == ptree->root)
    {
        BstNode* s = Buynode();
        s->key = key;
        ptree->root = s;
        ptree->cursize = 1;
        return true;
    }
    BstNode* pa = NULL;
    BstNode* p = ptree->root;
    while (p != NULL && p->key != key)
    {
        pa = p;
        p = (key > p->key) ? p->rightchild : p->leftchild;
    }
    if (NULL != p && p->key == key) return false;
    BstNode* s = Buynode();
    s->key = key;
    s->parent = pa;
    if (s->key < pa->key)
    {
        pa->leftchild = s;
    }
    else
    {
        pa->rightchild = s;
    }
    ptree->cursize += 1;
    return true;
}

// 静态函数，查找以p为根的子树中最左边的节点（即最小键值节点）
static BstNode* First(BstNode* p)
{
    if (p == NULL) return NULL;
    while (p->leftchild != NULL)
    {
        p = p->leftchild;
    }
    return p;
}

// 静态函数，查找指定节点的后继节点
static BstNode* Next(BstNode* ptr)
{
    if (ptr == NULL) return NULL;
    if (ptr->rightchild != NULL)
    {
        return First(ptr->rightchild);
    }
    else
    {
        BstNode* pa = ptr->parent;
        while (pa != NULL && pa->leftchild != ptr)
        {
            ptr = pa;
            pa = pa->parent;
        }
        return pa;
    }
}

// 中序遍历二叉排序树并输出节点键值
void NiceInOrder(const BSTree* ptree)
{
    assert(ptree != NULL);
    for (BstNode* p = First(ptree->root); p != NULL; p = Next(p))
    {
        printf("%d ", p->key);
    }
}

// 静态函数，查找以p为根的子树中最右边的节点（即最大键值节点）
static BstNode* Last(BstNode* p)
{
    if (p == NULL) return NULL;
    while (p->rightchild != NULL)
    {
        p = p->rightchild;
    }
    return p;
}

// 静态函数，查找指定节点的前驱节点
static BstNode* Prev(BstNode* ptr)
{
    if (ptr == NULL) return NULL;
    if (ptr->leftchild != NULL)
    {
        return Last(ptr->leftchild);
    }
    else
    {
        BstNode* pa = ptr->parent;
        while (pa != NULL && pa->rightchild != ptr)
        {
            ptr = pa;
            pa = pa->parent;
        }
        return pa;
    }
}

// 逆中序遍历二叉排序树并输出节点键值
void NiceResOrder(const BSTree* ptree)
{
    assert(ptree != NULL);
    for (BstNode* p = Last(ptree->root); p != NULL; p = Prev(p))
    {
        printf("%d ", p->key);
    }
}

// 从二叉排序树中删除指定键值的节点
bool Remove(BSTree* ptree, KeyType key)
{
    assert(ptree != NULL);
    if (NULL == ptree->root) return false;
    BstNode* p = FindValue(ptree, key);
    if (NULL == p) return false;
    if (p->leftchild == NULL && p->rightchild == NULL)
    {
        BstNode* pa = p->parent;
        if (p == pa->leftchild) pa->leftchild = NULL;
        else pa->rightchild = NULL;
        Freenode(p);
        ptree->cursize--;
        return true;
    }
    if (p->leftchild != NULL && p->rightchild != NULL)
    {
        BstNode* q = p->leftchild;
        while (q->rightchild != NULL)
        {
            q = q->rightchild;
        }
        p->key = q->key;
        BstNode* qa = q->parent;
        if (q == qa->leftchild) qa->leftchild = q->leftchild;
        else qa->rightchild = q->leftchild;
        if (q->leftchild != NULL) q->leftchild->parent = qa;
        Freenode(q);
        ptree->cursize--;
        return true;
    }
    if (p->leftchild != NULL || p->rightchild != NULL)
    {
        BstNode* pa = p->parent;
        BstNode* pc = (p->leftchild != NULL) ? p->leftchild : p->rightchild;
        if (p == pa->leftchild) pa->leftchild = pc;
        else pa->rightchild = pc;
        pc->parent = pa;
        Freenode(p);
        ptree->cursize--;
        return true;
    }
}
```

这些代码实现了二叉排序树的基本操作，包括初始化、插入、删除、查找、遍历等功能。

### 主要功能说明

- **初始化**：`InitBSTree` 函数用于初始化一个二叉排序树，将根节点置为空，节点数量置为 0。
- **销毁**：`DestroyBSTree` 函数用于销毁二叉排序树，释放所有节点的内存。
- **插入**：`Insert` 函数用于向二叉排序树中插入一个键值，如果键值已存在则插入失败。
- **删除**：`Remove` 函数用于从二叉排序树中删除指定键值的节点。
- **查找**：`FindValue` 函数用于在二叉排序树中查找指定键值的节点。
- **遍历**：`NiceInOrder` 函数实现了中序遍历，`NiceResOrder` 函数实现了逆中序遍历。

### 静态函数说明

- `Buynode`：用于创建一个新的二叉排序树节点。
- `Freenode`：用于释放一个二叉排序树节点的内存。
- `First`：查找以某个节点为根的子树中最左边的节点（即最小键值节点）。
- `Next`：查找指定节点的后继节点。
- `Last`：查找以某个节点为根的子树中最右边的节点（即最大键值节点）。
- `Prev`：查找指定节点的前驱节点。