#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "school.h"

// ����ѧУ��֯��
SchoolTree* createSchoolTree() {
    SchoolTree* tree = (SchoolTree*)malloc(sizeof(SchoolTree));
    tree->root = createDepartment("�����ƾ���ѧ", 0, 1);
    return tree;
}

// �������Žڵ�
DepartmentNode* createDepartment(const char* name, int staff_number, int level) {
    DepartmentNode* node = (DepartmentNode*)malloc(sizeof(DepartmentNode));
	strcpy(node->name, name);
    node->staff_number = staff_number;
    node->level = level;
    node->childCount = 0;
    return node;
}

// ����Ӳ���
void addDepartment(DepartmentNode* parent, DepartmentNode* child) {
    if (parent->childCount < MAX_CHILDREN) {
        parent->children[parent->childCount++] = child;
    }
}

// ͳ���ض��㼶�Ĳ�������
void countDepartmentsByLevel(DepartmentNode* root, int level, int* count) {
    if (!root) return;

    if (root->level == level) {
        (*count)++;
    }

    for (int i = 0; i < root->childCount; i++) {
        countDepartmentsByLevel(root->children[i], level, count);
    }
}

// ��ӡ�ض��㼶�Ĳ���
void printDepartmentsByLevel(DepartmentNode* root, int level) {
    if (!root) return;

    if (root->level == level) {
        printf("%s (��������: %d)\n", root->name, root->staff_number);
    }

    for (int i = 0; i < root->childCount; i++) {
        printDepartmentsByLevel(root->children[i], level);
    }
}

// ��ѯ���ű�������
int getStaffNumber(DepartmentNode* root, const char* deptName) {
    if (!root) return -1;

    if (strcmp(root->name, deptName) == 0) {
        return root->staff_number;
    }

    for (int i = 0; i < root->childCount; i++) {
        int result = getStaffNumber(root->children[i], deptName);
        if (result != -1) return result;
    }

    return -1;
}

// ������
void destroyTree(DepartmentNode* root) {
    if (!root) return;

    for (int i = 0; i < root->childCount; i++) {
        destroyTree(root->children[i]);
    }

    free(root);
}