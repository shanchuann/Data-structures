#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "MinimumSpanningTree.h"

// ���鼯����
static int parent[MAX_VERTICES];

// ��ʼ�����鼯
void initSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

// ���Ҹ��ڵ�
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  // ·��ѹ��
    }
    return parent[x];
}

// �ϲ���������
void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}

// ���ڱ�����ıȽϺ���
static int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Kruskal�㷨ʵ��
void kruskal(int n, int m, Edge edges[]) {
    int edgeCount = 0;  // ��ѡ�ߵ�����
    int totalWeight = 0;  // ��С����������Ȩ��

    // ��Ȩ�ضԱ߽�������
    qsort(edges, m, sizeof(Edge), compareEdges);

    // ��ʼ�����鼯
    initSet(n);

    printf("��С�������ı�Ϊ��\n");

    // �������б�
    for (int i = 0; i < m && edgeCount < n - 1; i++) {
        int start = edges[i].start;
        int end = edges[i].end;

        // ��������߲����γɻ�
        if (find(start) != find(end)) {
            printf("%d - %d: %d\n", start, end, edges[i].weight);
            unionSet(start, end);
            totalWeight += edges[i].weight;
            edgeCount++;
        }
    }

    printf("��С����������Ȩ��Ϊ��%d\n", totalWeight);
}

// ����ͼ������
void inputGraphData(int* n, int* m, Edge edges[]) {
    printf("�����붥�����ͱ�����");
    scanf("%d %d", n, m);

    printf("������ÿ���ߵ���㡢�յ��Ȩ�أ�\n");
    for (int i = 0; i < *m; i++) {
        scanf("%d %d %d", &edges[i].start, &edges[i].end, &edges[i].weight);
    }
}