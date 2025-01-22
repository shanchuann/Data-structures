#ifndef MINIMUM_SPANNING_TREE_H
#define MINIMUM_SPANNING_TREE_H

#define MAX_VERTICES 100
#define MAX_EDGES 10000

// �ߵĽṹ��
typedef struct {
    int start;      // ��ʼ����
    int end;        // ��ֹ����
    int weight;     // �ߵ�Ȩ��
} Edge;

// ��������
void initSet(int n);
int find(int x);
void unionSet(int x, int y);
void kruskal(int n, int m, Edge edges[]);
void inputGraphData(int* n, int* m, Edge edges[]);

#endif