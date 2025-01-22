#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "school.h"

// 创建学校组织树
SchoolTree* createSchoolTree() {
    SchoolTree* tree = (SchoolTree*)malloc(sizeof(SchoolTree));
    tree->root = createDepartment("西安财经大学", 0, 1);
    return tree;
}

// 创建部门节点
DepartmentNode* createDepartment(const char* name, int staff_number, int level) {
    DepartmentNode* node = (DepartmentNode*)malloc(sizeof(DepartmentNode));
	strcpy(node->name, name);
    node->staff_number = staff_number;
    node->level = level;
    node->childCount = 0;
    return node;
}

// 添加子部门
void addDepartment(DepartmentNode* parent, DepartmentNode* child) {
    if (parent->childCount < MAX_CHILDREN) {
        parent->children[parent->childCount++] = child;
    }
}

// 统计特定层级的部门数量
void countDepartmentsByLevel(DepartmentNode* root, int level, int* count) {
    if (!root) return;

    if (root->level == level) {
        (*count)++;
    }

    for (int i = 0; i < root->childCount; i++) {
        countDepartmentsByLevel(root->children[i], level, count);
    }
}

// 打印特定层级的部门
void printDepartmentsByLevel(DepartmentNode* root, int level) {
    if (!root) return;

    if (root->level == level) {
        printf("%s (编制人数: %d)\n", root->name, root->staff_number);
    }

    for (int i = 0; i < root->childCount; i++) {
        printDepartmentsByLevel(root->children[i], level);
    }
}

// 查询部门编制人数
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

// 销毁树
void destroyTree(DepartmentNode* root) {
    if (!root) return;

    for (int i = 0; i < root->childCount; i++) {
        destroyTree(root->children[i]);
    }

    free(root);
}