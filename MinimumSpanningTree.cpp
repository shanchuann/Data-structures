#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "MinimumSpanningTree.h"

// 并查集数组
static int parent[MAX_VERTICES];

// 初始化并查集
void initSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

// 查找根节点
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  // 路径压缩
    }
    return parent[x];
}

// 合并两个集合
void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}

// 用于边排序的比较函数
static int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Kruskal算法实现
void kruskal(int n, int m, Edge edges[]) {
    int edgeCount = 0;  // 已选边的数量
    int totalWeight = 0;  // 最小生成树的总权重

    // 按权重对边进行排序
    qsort(edges, m, sizeof(Edge), compareEdges);

    // 初始化并查集
    initSet(n);

    printf("最小生成树的边为：\n");

    // 遍历所有边
    for (int i = 0; i < m && edgeCount < n - 1; i++) {
        int start = edges[i].start;
        int end = edges[i].end;

        // 如果这条边不会形成环
        if (find(start) != find(end)) {
            printf("%d - %d: %d\n", start, end, edges[i].weight);
            unionSet(start, end);
            totalWeight += edges[i].weight;
            edgeCount++;
        }
    }

    printf("最小生成树的总权重为：%d\n", totalWeight);
}

// 输入图的数据
void inputGraphData(int* n, int* m, Edge edges[]) {
    printf("请输入顶点数和边数：");
    scanf("%d %d", n, m);

    printf("请输入每条边的起点、终点和权重：\n");
    for (int i = 0; i < *m; i++) {
        scanf("%d %d %d", &edges[i].start, &edges[i].end, &edges[i].weight);
    }
}