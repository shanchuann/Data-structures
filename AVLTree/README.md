# AVLTree

### 1. 定义和特点

AVL 树是一种自平衡的二叉搜索树（Binary Search Tree, BST）。在二叉搜索树的基础上，AVL 树通过在插入和删除节点时自动调整树的结构，保证树的高度始终保持在对数级别，即对于包含 个节点的 AVL 树，其高度 满足 。这样可以使得 AVL 树的查找、插入和删除操作的时间复杂度都保持在 ，避免了普通二叉搜索树在极端情况下退化为链表，导致操作时间复杂度变为 的问题。

### 2. 节点和树的结构

- 节点结构（`AVLNode`）
  - `leftchild`：指向当前节点的左子节点。
  - `parent`：指向当前节点的父节点。
  - `rightchild`：指向当前节点的右子节点。
  - `balance`：节点的平衡因子，取值为 -1、0 或 1，用于表示节点左右子树的高度差。平衡因子的计算方式为：左子树高度 - 右子树高度。
  - `key`：节点存储的键值。

```cpp
typedef struct AVLNode
{
    struct AVLNode* leftchild;
    struct AVLNode* parent;
    struct AVLNode* rightchild;
    int balance;  // -1, 0, 1;
    KeyType key;
}AVLNode;
```

- 树结构（`AVLTree`）
  - `root`：指向 AVL 树的根节点。
  - `cursize`：记录当前 AVL 树中节点的数量。

```cpp
typedef struct
{
    AVLNode* root;
    int cursize;
}AVLTree;
```

### 3. 主要操作

#### 3.1 初始化（`InitAVLTree`）

将 AVL 树的根节点指针置为 `NULL`，并将当前节点数量初始化为 0。

```cpp
void InitAVLTree(AVLTree* ptree)
{
    assert(ptree != NULL);
    ptree->root = NULL;
    ptree->cursize = 0;
}
```

#### 3.2 插入操作（`Insert`）

- 首先按照二叉搜索树的插入规则找到合适的插入位置。
- 插入新节点后，从插入节点开始向上调整树的结构，更新节点的平衡因子。
- 如果某个节点的平衡因子超出了范围（-1, 0, 1），则通过旋转操作（左旋 `RotateLeft` 或右旋 `RotateRight`）来重新平衡树。

#### 3.3 删除操作（`Remove`）

- 先按照二叉搜索树的删除规则找到要删除的节点。
- 删除节点后，从删除节点的父节点开始向上调整树的结构，更新节点的平衡因子。
- 如果某个节点的平衡因子超出了范围，则通过旋转操作来重新平衡树。

#### 3.4 查找操作（`FindValue`）

从根节点开始，根据键值的大小关系，不断地在左子树或右子树中查找，直到找到目标节点或遍历到空节点为止。

```cpp
AVLNode* FindValue(const AVLTree* ptree, KeyType kx)
{
    assert(ptree != NULL);
    AVLNode* p = ptree->root;
    while (p != NULL && p->key != kx)
    {
        if (kx < p->key)
        {
            p = p->leftchild;
        }
        else
        {
            p = p->rightchild;
        }
    }
    return p;
}
```

#### 3.5 遍历操作（`NiceInOrder`）

中序遍历 AVL 树，按节点键值从小到大的顺序输出节点的键值。

### 4. 平衡调整

- **左旋（`RotateLeft`）**：当某个节点的右子树高度过高时，通过左旋操作降低右子树的高度，同时更新相关节点的指针和平衡因子。
- **右旋（`RotateRight`）**：当某个节点的左子树高度过高时，通过右旋操作降低左子树的高度，同时更新相关节点的指针和平衡因子。
- **左右双旋和右左双旋**：在某些情况下，单次的左旋或右旋无法恢复树的平衡，需要进行左右双旋或右左双旋操作。例如，当某个节点的左子节点的右子树高度过高时，需要先对左子节点进行左旋，再对该节点进行右旋。

### 5. 优缺点

#### 优点

- 查找、插入和删除操作的时间复杂度都为 ，性能稳定。
- 可以保证树的高度平衡，避免了二叉搜索树退化为链表的情况。

#### 缺点

- 插入和删除操作需要进行额外的平衡调整，可能会导致一些性能开销。
- 实现相对复杂，需要维护节点的平衡因子和进行旋转操作。