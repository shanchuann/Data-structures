#ifndef MINIMUM_SPANNING_TREE_H
#define MINIMUM_SPANNING_TREE_H

#define MAX_VERTICES 100
#define MAX_EDGES 10000

// 边的结构体
typedef struct {
    int start;      // 起始顶点
    int end;        // 终止顶点
    int weight;     // 边的权重
} Edge;

// 函数声明
void initSet(int n);
int find(int x);
void unionSet(int x, int y);
void kruskal(int n, int m, Edge edges[]);
void inputGraphData(int* n, int* m, Edge edges[]);

#endif