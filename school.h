#ifndef SCHOOL_TREE_H
#define SCHOOL_TREE_H

#define MAX_NAME 50
#define MAX_CHILDREN 20

// 部门节点结构
typedef struct DepartmentNode {
    char name[MAX_NAME];          // 部门名称
    int staff_number;             // 编制人数
    int level;                    // 部门层级(1:校级, 2:处级, 3:科级)
    struct DepartmentNode* children[MAX_CHILDREN];  // 子部门
    int childCount;              // 子部门数量
} DepartmentNode;

// 树结构
typedef struct {
    DepartmentNode* root;         // 根节点(学校)
} SchoolTree;

// 函数声明
SchoolTree* createSchoolTree();
DepartmentNode* createDepartment(const char* name, int staff_number, int level);
void addDepartment(DepartmentNode* parent, DepartmentNode* child);
void countDepartmentsByLevel(DepartmentNode* root, int level, int* count);
void printDepartmentsByLevel(DepartmentNode* root, int level);
int getStaffNumber(DepartmentNode* root, const char* deptName);
void destroyTree(DepartmentNode* root);

#endif 