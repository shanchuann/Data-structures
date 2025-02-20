# Bank

`Bank.h` 文件

这是头文件，主要定义了系统中使用的数据结构和函数声明。

#### 常量定义

- `const int WinSize = 4;`：定义了银行窗口的数量，这里设置为 4 个窗口。

#### 数据结构定义

1. `Event` 结构体
   - `int OccurTime;`：记录事件发生的时间。
   - `int EventType;`：记录事件的类型，0 表示客户到达，1 - 4 表示对应的窗口事件。
2. `EventNode` 结构体
   - `Event evdata;`：存储事件数据。
   - `EventNode* next;`：指向下一个事件节点的指针，用于构建事件链表。
3. `OrderEventTable` 结构体
   - `EventNode* head;`：事件链表的头指针。
   - `int cursize;`：当前事件表的大小。
4. `TranType` 结构体
   - `int ArrivalTime;`：客户到达时间。
   - `int StartTime;`：客户开始办理业务的时间。
   - `int Duration;`：客户办理业务的持续时间。
5. `TranNode` 结构体
   - `TranType trandata;`：存储客户业务数据。
   - `TranNode* next;`：指向下一个客户节点的指针，用于构建客户链表。
6. `WinQueue` 结构体
   - `TranNode* front;`：客户链表的头指针。
   - `TranNode* tail;`：客户链表的尾指针。
   - `int cursize;`：当前队列的大小。
   - `int LastTime;`：该窗口的最后服务时间。
7. `BankStat` 结构体
   - `OrderEventTable evList;`：事件列表。
   - `WinQueue WinQue[WinSize + 1];`：窗口队列数组。
   - `int TotalTime;`：所有客户的总服务时间。
   - `int curtNum;`：当前客户数量。

#### 函数声明

- 与 `OrderEventTable` 相关的函数：`InitEventTable`、`DestroyEventTable`、`GetSize`、`EventEmpty`、`PopHeader`、`InsertEvent`。
- 与 `WinQueue` 相关的函数：`InitWinQueue`、`DestroyWinQueue`、`GetSize`、`GetLastTime`、`SetLastTime`、`QueueEmpty`、`GetFront`、`PopFront`、`GetTial`、`InsertTail`。
- 与 `BankStat` 相关的函数：`InitBankStat`、`DestroyBankStat`、`BankOpen`、`PrintAver`。

### `Bank.cpp` 文件

这是实现文件，包含了 `Bank.h` 中声明的函数的具体实现。

#### 静态函数

- **`BuyEventNode`**：动态分配一个 `EventNode` 节点的内存空间，并将其初始化为 0。
- **`FreeEventNode`**：释放 `EventNode` 节点的内存空间。
- **`BuyTran`**：动态分配一个 `TranNode` 节点的内存空间，并将其初始化为 0。
- **`FreeTran`**：释放 `TranNode` 节点的内存空间。

#### 事件表操作函数

- **`InitEventTable`**：初始化事件表，分配头节点并将当前大小设置为 0。
- **`DestroyEventTable`**：销毁事件表，释放所有节点的内存空间。
- **`GetSize`**：获取事件表的当前大小。
- **`EventEmpty`**：判断事件表是否为空。
- **`PopHeader`**：从事件表中移除并返回头节点的事件。
- **`InsertEvent`**：将事件按发生时间顺序插入事件表。

#### 窗口队列操作函数

- **`InitWinQueue`**：初始化窗口队列，将头尾指针置空，最后服务时间和当前大小设置为 0。
- **`DestroyWinQueue`**：销毁窗口队列，释放所有节点的内存空间。
- **`GetSize`**：获取窗口队列的当前大小。
- **`GetLastTime`**：获取窗口的最后服务时间。
- **`SetLastTime`**：设置窗口的最后服务时间。
- **`QueueEmpty`**：判断窗口队列是否为空。
- **`GetFront`**：获取窗口队列的头部客户数据。
- **`PopFront`**：从窗口队列中移除并返回头部客户数据。
- **`GetTial`**：获取窗口队列的尾部客户数据。
- **`InsertTail`**：将客户数据插入窗口队列的尾部。

#### 银行统计操作函数

- **`SelectMinLastTime`**：选择最后服务时间最小的窗口。
- **`InitBankStat`**：初始化银行统计数据，包括事件表和窗口队列。
- **`DestroyBankStat`**：销毁银行统计数据，包括事件表和窗口队列。
- **`BankOpen`**：模拟银行营业过程，处理客户到达和离开事件。
- **`PrintAver`**：打印所有客户的总服务时间和平均服务时间。

总的来说，这些代码通过链表和队列等数据结构模拟了银行的排队系统，实现了客户到达、客户服务、窗口选择等功能，并统计了客户的平均服务时间。