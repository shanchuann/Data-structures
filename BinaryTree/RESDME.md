# BinaryTree.h

### 1. `BinaryTree.h` 文件

这是一个头文件，主要用于定义二叉树的结构以及声明相关操作的函数。

```cpp
#ifndef BINARY_TERR_H
#define BINARY_TERR_H

// 定义二叉树节点存储的数据类型
typedef char ElemType;

// 定义二叉树节点结构
typedef struct BtNode
{
    BtNode* leftchild;  // 左子节点指针
    BtNode* rightchild; // 右子节点指针
    ElemType data;      // 节点存储的数据
}BtNode, * BinaryTree;

// 以下是各种操作二叉树的函数声明

// 初始化二叉树
void InitBinaryTree(BinaryTree* proot);
// 销毁二叉树
void DestroyBinaryTree(BinaryTree p);
// 清空二叉树
void ClearBinaryTree(BinaryTree p);
// 获取二叉树的节点数量
int GetSize(const BinaryTree p);
// 获取二叉树的深度
int GetDepth(const BinaryTree p);
// 判断二叉树是否为空
bool IsEmpty(const BinaryTree p);
// 创建二叉树
BtNode* CreateBinTree();
// 前序遍历二叉树
void PreOrder(const BinaryTree p);
// 中序遍历二叉树
void InOrder(const BinaryTree p);
// 后序遍历二叉树
void LastOrder(const BinaryTree p);
// 层序遍历二叉树
void LevelOrder(const BinaryTree p);

#endif
```

### 2. `BinaryTree.cpp` 文件

这是实现文件，包含了头文件中声明的函数的具体实现。

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

// 初始化二叉树
void InitBinaryTree(BinaryTree* proot) {
    *proot = NULL;
}

// 销毁二叉树
void DestroyBinaryTree(BinaryTree p) {
    if (p != NULL) {
        DestroyBinaryTree(p->leftchild);
        DestroyBinaryTree(p->rightchild);
        free(p);
    }
}

// 清空二叉树
void ClearBinaryTree(BinaryTree p) {
    if (p != NULL) {
        ClearBinaryTree(p->leftchild);
        ClearBinaryTree(p->rightchild);
        p->leftchild = p->rightchild = NULL;
    }
}

// 获取二叉树的节点数量
int GetSize(const BinaryTree p) {
    if (p == NULL) return 0;
    return GetSize(p->leftchild) + GetSize(p->rightchild) + 1;
}

// 获取二叉树的深度
int GetDepth(const BinaryTree p) {
    if (p == NULL) return 0;
    int leftDepth = GetDepth(p->leftchild);
    int rightDepth = GetDepth(p->rightchild);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// 判断二叉树是否为空
bool IsEmpty(const BinaryTree p) {
    return p == NULL;
}

// 创建二叉树
BtNode* CreateBinTree() {
    char ch;
    scanf(" %c", &ch);  // 注意忽略空格和回车等空白字符
    if (ch == '#') return NULL;

    BtNode* node = (BtNode*)malloc(sizeof(BtNode));
    if (node == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    node->data = ch;
    node->leftchild = CreateBinTree();
    node->rightchild = CreateBinTree();
    return node;
}

// 前序遍历二叉树
void PreOrder(const BinaryTree p) {
    if (p != NULL) {
        printf("%c ", p->data);
        PreOrder(p->leftchild);
        PreOrder(p->rightchild);
    }
}

// 中序遍历二叉树
void InOrder(const BinaryTree p) {
    if (p != NULL) {
        InOrder(p->leftchild);
        printf("%c ", p->data);
        InOrder(p->rightchild);
    }
}

// 后序遍历二叉树
void LastOrder(const BinaryTree p) {
    if (p != NULL) {
        LastOrder(p->leftchild);
        LastOrder(p->rightchild);
        printf("%c ", p->data);
    }
}

// 层序遍历二叉树，使用队列实现
#define MAX_QUEUE_SIZE 100
void LevelOrder(const BinaryTree p) {
    if (p == NULL) return;

    BinaryTree queue[MAX_QUEUE_SIZE];
    int front = 0, rear = 0;

    queue[rear++] = p;

    while (front < rear) {
        BinaryTree current = queue[front++];
        printf("%c ", current->data);

        if (current->leftchild)
            queue[rear++] = current->leftchild;
        if (current->rightchild)
            queue[rear++] = current->rightchild;
    }
}
```

### 主要函数功能介绍

- **`InitBinaryTree`**：初始化二叉树，将根节点指针置为`NULL`。
- **`DestroyBinaryTree`**：递归销毁二叉树，释放所有节点的内存。
- **`ClearBinaryTree`**：递归清空二叉树，将所有节点的左右子节点指针置为`NULL`。
- **`GetSize`**：递归计算二叉树的节点数量。
- **`GetDepth`**：递归计算二叉树的深度。
- **`IsEmpty`**：判断二叉树是否为空。
- **`CreateBinTree`**：通过递归方式创建二叉树，输入`#`表示空节点。
- **`PreOrder`**：前序遍历二叉树，即根节点 -> 左子树 -> 右子树的顺序访问节点。
- **`InOrder`**：中序遍历二叉树，即左子树 -> 根节点 -> 右子树的顺序访问节点。
- **`LastOrder`**：后序遍历二叉树，即左子树 -> 右子树 -> 根节点的顺序访问节点。
- **`LevelOrder`**：层序遍历二叉树，使用队列实现，按层的顺序从左到右访问节点。