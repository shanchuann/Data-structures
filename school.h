#ifndef SCHOOL_TREE_H
#define SCHOOL_TREE_H

#define MAX_NAME 50
#define MAX_CHILDREN 20

// ���Žڵ�ṹ
typedef struct DepartmentNode {
    char name[MAX_NAME];          // ��������
    int staff_number;             // ��������
    int level;                    // ���Ų㼶(1:У��, 2:����, 3:�Ƽ�)
    struct DepartmentNode* children[MAX_CHILDREN];  // �Ӳ���
    int childCount;              // �Ӳ�������
} DepartmentNode;

// ���ṹ
typedef struct {
    DepartmentNode* root;         // ���ڵ�(ѧУ)
} SchoolTree;

// ��������
SchoolTree* createSchoolTree();
DepartmentNode* createDepartment(const char* name, int staff_number, int level);
void addDepartment(DepartmentNode* parent, DepartmentNode* child);
void countDepartmentsByLevel(DepartmentNode* root, int level, int* count);
void printDepartmentsByLevel(DepartmentNode* root, int level);
int getStaffNumber(DepartmentNode* root, const char* deptName);
void destroyTree(DepartmentNode* root);

#endif 