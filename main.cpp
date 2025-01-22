#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "AVLTree.h"

int main() {
	AVLTree mytree;
	InitAVLTree(&mytree);
	int n = 10;
	for (int i = 0; i < n; ++i)
	{
		Insert(&mytree, i);
	}
	NiceInOrder(&mytree);
	printf("\n");
	return 0;
}
//#include <stdio.h>
//#include "BinaryTree.h"
//
//void testBasicOperations(BinaryTree tree) {
//    printf("树的节点数: %d\n", GetSize(tree));
//    printf("树的深度: %d\n", GetDepth(tree));
//    printf("是否为空: %s\n", IsEmpty(tree) ? "是" : "否");
//}
//
//void testTraversals(BinaryTree tree) {
//
//    printf("前序遍历: ");
//    PreOrder(tree);
//    printf("\n");
//
//    printf("中序遍历: ");
//    InOrder(tree);
//    printf("\n");
//
//    printf("后序遍历: ");
//    LastOrder(tree);
//    printf("\n");
//
//    printf("层序遍历: ");
//    LevelOrder(tree);
//    printf("\n");
//}
//
//int main() {
//    BinaryTree tree;
//    InitBinaryTree(&tree);
//    printf("\n请输入：");
//    tree = CreateBinTree();
//    // 测试基本操作
//    testBasicOperations(tree);
//    // 测试各种遍历方式
//    testTraversals(tree);
//    DestroyBinaryTree(tree);
//    return 0;
//}

//#include <stdio.h>
//#include "MinimumSpanningTree.h"
//
//int main() {
//    int n, m;  // n为顶点数，m为边数
//    Edge edges[MAX_EDGES];
//
//    // 输入图的数据
//    inputGraphData(&n, &m, edges);
//
//    // 执行Kruskal算法
//    kruskal(n, m, edges);
//
//    return 0;
//}
//#include <stdio.h>
//#include "avl.h"
//
//int main() {
//	//建立平衡二叉树，进行创建、增加、删除操作
//	AVLNode* root = NULL;
//	root = insert(root, 10);
//	root = insert(root, 20);
//	root = insert(root, 30);
//	root = insert(root, 40);
//	root = insert(root, 50);
//	root = insert(root, 25);
//	root = insert(root, 35);
//	root = insert(root, 45);
//	root = insert(root, 55);
//	root = insert(root, 60);
//
//	printf("=== AVL树 ===\n");
//	printTree(root, 0);
//
//	printf("\n=== 中序遍历 ===\n");
//	inorderTraversal(root);
//
//	root = Delete(root, 30);
//	printf("\n\n=== 删除节点 30 ===\n");
//	printTree(root, 0);
//	return 0;
//}
//#include "school.h"
//#include <corecrt_malloc.h>
//
//int main() {
//    // 1. 创建学校组织树
//    SchoolTree* school = createSchoolTree();
//
//    // 2. 添加处级部门
//    DepartmentNode* academic = createDepartment("教务处", 25, 2);
//    DepartmentNode* student = createDepartment("学生处", 20, 2);
//    DepartmentNode* hr = createDepartment("人事处", 15, 2);
//    DepartmentNode* finance = createDepartment("财务处", 18, 2);
//    DepartmentNode* csCollege = createDepartment("信息学院", 120, 2);
//    DepartmentNode* mathCollege = createDepartment("数学学院", 80, 2);
//	DepartmentNode* tongjiCollege = createDepartment("统计学院", 80, 2);
//	DepartmentNode* jingjiCollege = createDepartment("经济学院", 80, 2);
//    addDepartment(school->root, academic);
//    addDepartment(school->root, student);
//    addDepartment(school->root, hr);
//    addDepartment(school->root, finance);
//    addDepartment(school->root, csCollege);
//    addDepartment(school->root, mathCollege);
//	addDepartment(school->root, tongjiCollege);
//	addDepartment(school->root, jingjiCollege);
//
//    // 3. 添加科级部门
//    // 教务处下属科室
//    addDepartment(academic, createDepartment("教学科", 8, 3));
//    addDepartment(academic, createDepartment("考务科", 6, 3));
//    addDepartment(academic, createDepartment("实践科", 5, 3));
//
//    // 学生处下属科室
//    addDepartment(student, createDepartment("学生管理科", 7, 3));
//    addDepartment(student, createDepartment("心理咨询科", 5, 3));
//
//    // 人事处下属科室
//    addDepartment(hr, createDepartment("人事科", 8, 3));
//    addDepartment(hr, createDepartment("工资科", 4, 3));
//
//    // 信息学院下属科室
//    addDepartment(csCollege, createDepartment("教务科", 6, 3));
//    addDepartment(csCollege, createDepartment("学工科", 5, 3));
//    addDepartment(csCollege, createDepartment("实验中心", 8, 3));
//
//    // 4. 统计和显示处级部门信息
//    printf("=== 处级部门统计 ===\n");
//    int count = 0;
//    countDepartmentsByLevel(school->root, 2, &count);
//    printf("处级部门总数：%d\n\n", count);
//
//    printf("处级部门列表：\n");
//    printDepartmentsByLevel(school->root, 2);
//    printf("\n");
//
//    // 5. 查询具体部门编制
//    const char* departments[] = { "教务处", "信息学院", "人事科", "实验中心" };
//    int num_departments = sizeof(departments) / sizeof(departments[0]);
//
//    printf("=== 部门编制查询 ===\n");
//    for (int i = 0; i < num_departments; i++) {
//        int staff = getStaffNumber(school->root, departments[i]);
//        if (staff != -1) {
//            printf("%s的编制人数：%d\n", departments[i], staff);
//        }
//        else {
//            printf("未找到部门：%s\n", departments[i]);
//        }
//    }
//
//    // 6. 测试科级部门统计
//    printf("\n=== 科级部门统计 ===\n");
//    count = 0;
//    countDepartmentsByLevel(school->root, 3, &count);
//    printf("科级部门总数：%d\n\n", count);
//
//    printf("科级部门列表：\n");
//    printDepartmentsByLevel(school->root, 3);
//
//    return 0;
//}

//#include<stdlib.h>
//#include<assert.h>
//#include<string.h>
//#include<time.h>
//#include<ctype.h>
//#include"SeqStack.h"
//#include<stdio.h>
//int main()
//{
//	SeqStack myStack;
//	InitStack(&myStack);
//	int n = 10;
//	for (int i = 0; i < n; ++i)
//	{
//		Push(&myStack, i);
//	}
//	PrintStack(&myStack);
//	int val;
//	while (!StackEmpty(&myStack))
//	{
//		Pop(&myStack, &val);
//		printf("val: %d\n", val);
//	}
//	//验证两栈共享一连续存储空间
//	InitStack2(&myStack);
//	for (int i = 0; i < n; ++i)
//	{
//		Push2(&myStack, i, 1);
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		Push2(&myStack, i, 2);
//	}
//	PrintStack(&myStack);
//	for (int i = 0; i < n; ++i)
//	{
//		Pop(&myStack, &val);
//		printf("val: %d\n", val);
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		Pop(&myStack, &val);
//		printf("val: %d\n", val);
//	}
//	DestroyStack2(&myStack);
//
//	DestroyStack(&myStack);
//	return 0;
//
//}
//#include"BinarySortTree.h"
//
//int main()
//{
//	BSTree mytree;
//	InitBSTree(&mytree);
//	int n = 10;
//	for (int i = 0; i < n; ++i)
//	{
//		Insert(&mytree, rand() % 100);
//	}
//	NiceInOrder(&mytree);
//	printf("\n");
//	return 0;
//}
//#include <stdio.h>
//#include "BinaryTree.h"
////ABD##E##CF##G##
//int main(void)
//{
//	BinaryTree tree;
//	InitBinaryTree(&tree);
//	tree = CreateBinTree();
//	int num = GetSize(tree);
//	printf("num: %d\n", num);
//	int depth = GetDepth(tree);
//	printf("depth: %d\n", depth);
//	PreOrder(tree);
//	printf("\n");
//	InOrder(tree);
//	printf("\n");
//	LastOrder(tree);
//	printf("\n");
//	LevelOrder(tree);
//	printf("\n");
//	ClearBinaryTree(tree);
//	printf("%d",IsEmpty(tree));
//
//	NiceInOrder(tree);
//	printf("\n");
//	NicePreOrder(tree);
//	printf("\n");
//	NiceLastOrder(tree);
//	printf("\n");
//
//
//	return 0;
//}
//int main(void)
//{
//	BinaryTree mytree;
//	InitBinaryTree(&mytree);
//	mytree = CreateBinTree();
//	PreOrder(mytree);
//	printf("\n");
//	InOrder(mytree);
//	printf("\n");
//	LastOrder(mytree);
//	printf("\n");
//	return 0;
//}
//#include"SkipList.h"

//int main(void)
//{
//    SkipList mylist;
//    InitSkipList(&mylist);
//    int n = 10;
//    for (int i = 0; i < n; ++i)
//    {
//        InsertNode(&mylist,i);
//    }
//    SkipListNode* p = mylist.head->backward[0];
//    while (p != nullptr)
//    {
//        printf("%d ", p->key);
//        p = p->backward[0];
//    }
//    printf("\n");
//	PrintSkip(&mylist);
//    DestroySkipList(&mylist);
//    return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 
//#include<stdio.h>
//#include"SeqQueue.h"
//
//void PrintInt(const void* pval)
//{
//    printf("%d ", *(const int*)pval);
//}
//
//int main()
//{
//    GenSeqQueue myq;
//    InitQueue(&myq, sizeof(int));
//    //测试队列
//    for (int i = 0; i < 5; ++i)
//    {
//        EnQueue(&myq, &i);
//    }
//    PrintQueue(&myq, PrintInt);
//    int val;
//	printf("\n");
//    while (!QueueEmpty(&myq))
//    {
//        DeQueue(&myq, &val);
//        printf("val: %d\n", val);
//    }
//    DestroyQueue(&myq);
//    return 0;
//}
//
////#define STRLEN 128
////bool Paren(const char* str)
////{
////	assert(str != NULL);
////	if (str[0] == '\0') return false;
////	GenListStack cst;
////	InitGenListStack(&cst, sizeof(char));
////	int i = 0;
////	while (str[i++] != '\0')
////	{
////		char val = str[i];
////		switch (val)
////		{
////		case '(':
////		case '[':
////		case '{':
////			Push(&cst, &val);
////			break;
////		case ')':
////			char topval;
////			GetTop(&cst, &topval);
////			if (!StackEmpty(&cst) && topval == '(')
////			{
////				Pop(&cst, &val);
////				break;
////			}
////			else return false;
////		case ']':
////			char topval;
////			GetTop(&cst, &topval);
////			if (!StackEmpty(&cst) && val == '[')
////			{
////				Pop(&cst, &val);
////				break;
////			}
////			else return false;
////		case '}':
////			char val;
////			GetTop(&cst, &val);
////			if (!StackEmpty(&cst) && val == '{')
////			{
////				Pop(&cst, &val);
////				break;
////			}
////			else return false;
////		default:
////			break;
////		}
////	}
////	if (StackEmpty(&cst)) return true;
////	else return false;
////}
//#define STRLEN 128
//bool Paren(const char* str)
//{
//	bool res = false;
//	if (NULL == str || '\0' == *str) return res;
//	char val = '\0';
//	GenListStack cst;
//	InitGenListStack(&cst, sizeof(char));
//	for (const char* p = str; *p != '\0'; ++p)
//	{
//		switch (*p)
//		{
//		case '(': case '[': case '{':
//			Push(&cst, p);
//			break;
//		case ')': case ']': case '}':
//			if (StackEmpty(&cst) || (Pop(&cst, &val), val != *p))
//			{
//				goto END;
//			}
//			break;
//		default:
//			break;
//		}
//	}
//	if (StackEmpty(&cst))
//	{
//		res = true;
//	}
//END:
//	DestroyGenListStack(&cst);
//	return res;
//}
//int main()
//{
//	char buff[STRLEN] = { 0 };
//	while(fgets(buff,STRLEN,stdin),strcmp(buff,"end") == 0)
//	//while (scanf("%s", buff), strcmp(buff, "end") == 0)
//	{
//		bool tag = Paren(buff);
//		if (tag)
//		{
//			printf("括号匹配\n");
//		}
//		else
//		{
//			printf("not ... \n");
//		}
//	}
//	return 0;
//}
//#if 0
//
//int main(void)
//{
//	char buff[STRLEN] = { 0 };
//	while (scanf("%s", buff), strcmp(buff, "end") != 0)
//	{
//		bool tag = Paren(buff);
//		if (tag)
//		{
//			printf("Yes");
//		}
//		else
//		{
//			printf("No");
//		}
//	}
//}
//
//#define BEGIN 1
//#define WORD_IN 2
//#define WORD_OUT 3
//
//int GetWordNums(const char* str)
//{
//	if (NULL == str) return -1;
//	if (*str == '\0') return 0;
//	const char* p = str;
//	int nums = 0;
//	int tag = BEGIN;
//	for (; *p != '\0'; ++p)
//	{
//		switch (tag)
//		{
//		case BEGIN:
//			if (isalpha(*p))
//			{
//				tag = WORD_IN;
//			}
//			else
//			{
//				tag = WORD_OUT;
//			}
//			break;
//
//		case WORD_IN:
//			if (!isalpha(*p))
//			{
//				tag = WORD_OUT;
//				++nums;
//			}
//			break;
//
//		case WORD_OUT:
//			if (isalpha(*p))
//			{
//				tag = WORD_IN;
//			}
//			break;
//		}
//	}
//}
//int main(void)
//{
//	char str[] = "  hello  world  c++  ";
//	int nums = GetWordNums(str);
//	printf("nums: %d \n", nums);
//	return 0;
//
//}
//
//bool GetConversion(unsigned int nums, int radix, char* buff)
//{
//	if (radix < 2 || radix > 36) return false;
//	if (NULL == buff) return false;
//	static char dig[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//	GenListStack mylist;
//	InitGenListStack(&mylist, sizeof(char));
//	while (nums != 0)
//	{
//		int index = nums % radix;
//		nums = nums / radix;
//		Push(&mylist, &dig[index]);
//	}
//	int i = 0;
//	char val;
//	while (!StackEmpty(&mylist))
//	{
//		Pop(&mylist, &val);
//		buff[i++] = val;
//	}
//	buff[i] = '\0';
//	DestroyGenListStack(&mylist);
//	return true;
//}
//
//int main()
//{
//	int n = 7;
//	int dx = 12.25;
//	GenListStack imys, dmys;
//	InitGenListStack(&imys, sizeof(int));
//	InitGenListStack(&dmys, sizeof(double));
//	for (int i = 0; i < n; ++i)
//	{
//		Push(&imys, &i);
//		Push(&dmys, &dx);
//		dx += 1;
//	}
//	int val;
//	while (!StackEmpty(&imys))
//	{
//		Pop(&imys, &val);
//		printf("val : %d \n", val);
//	}
//	double dy = 0;
//	while (!StackEmpty(&dmys))
//	{
//		Pop(&dmys, &dy);
//		printf("dy : %lf \n", dy);
//	}
//
//	DestroyGenListStack(&imys);
//	DestroyGenListStack(&dmys);
//	return 0;
//}
//
//#include"GenDuLinkList.hpp"
//int main()
//{
//	double dx = 12.25;
//	GenLinkList dmylist;
//	InitGenLinkList(&dmylist, sizeof(double));
//	for (int i = 0; i < 5; ++i)
//	{
//		dx += i;
//		Push_Back(&dmylist, &dx);
//	}
//
//	double dy = 0;
//	while (!IsEmpty(&dmylist))
//	{
//		if (GetFront(&dmylist, &dy))
//		{
//			printf("dy : %lf \n", dy);
//			Pop_Front(&dmylist);
//		}
//	}
//	DestroyGenLinkList(&dmylist);
//	return 0;
//}
//
//
//struct Student
//{
//	char s_id[20];
//	char s_name[20];
//	char s_sex[10];
//	int s_age;
//};// sizeof(Student); 
//void PrintStudent(const void* p)
//{
//	const Student* sp = (const Student*)p;
//	printf("id: %s name: %s sex: %s age: %d \n",
//		sp->s_id, sp->s_name, sp->s_sex, sp->s_age);
//
//}
//bool CompId(const void* sp, const void* id)
//{
//	const Student* pstud = (const Student*)sp;
//	const char* sid = (const char*)id;
//	return strcmp(pstud->s_id, sid) == 0;
//}
//int main()
//{
//	struct Student studar[] = {
//#include"student.txt"  
//	};
//	printf("studar size: %d\n", sizeof(studar));
//	printf("studar elem size: %d \n", sizeof(studar[0]));
//	int n = sizeof(studar) / sizeof(studar[0]); // FILE *fp 
//	GenLinkList smylist;
//	InitGenLinkList(&smylist, sizeof(Student));
//	for (int i = 0; i < n; ++i)
//	{
//		Push_Back(&smylist, &studar[i]);
//	}
//	PrintInfo(&smylist, PrintStudent);
//	char id[20];
//	while (scanf("%s", id), strcmp(id, "end") != 0)
//	{
//		GenListNode* p = FindElem(&smylist, id, CompId);
//		if (p != NULL)
//		{
//			PrintStudent(p->data);
//		}
//	}
//	DestroyGenLinkList(&smylist);
//	return 0;
//}
//
//
//void PrintInt(const void* p)
//{
//	const int* ip = (const int*)p;
//	printf("%d ", *ip);
//}
//void PrintDouble(const void* p)
//{
//	const double* dp = (const double*)p;
//	printf("%lf ", *dp);
//}
//int funa()
//{
//	GenLinkList dmylist;
//	InitGenLinkList(&dmylist, sizeof(double));
//	int n = 10;
//	double val = 12.25;
//	for (int i = 0; i < n; ++i)
//	{
//		Push_Back(&dmylist, &val);
//		val += 1;
//	}
//	PrintInfo(&dmylist, PrintDouble);
//	while (scanf("%lf", &val), val != -1)
//	{
//		GenListNode* p = FindValue(&dmylist, &val);
//		if (NULL != p) { printf("%x %lf\n", p, *((double*)p->data)); }
//	}
//
//	DestroyGenLinkList(&dmylist);
//	return 0;
//}
//
//int funb()
//{
//	GenLinkList imylist;
//	InitGenLinkList(&imylist, sizeof(int));
//	int n = 10;
//	int val = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		val = rand() % 100;
//		Push_Back(&imylist, &val);
//	}
//	PrintInfo(&imylist, PrintInt);
//	while (scanf("%d", &val), val != -1)
//	{
//		GenListNode* p = FindValue(&imylist, &val);
//		if (NULL != p) { printf("%x %d\n", p, *((int*)p->data)); }
//	}
//
//	DestroyGenLinkList(&imylist);
//	return 0;
//}
//int main()
//{
//	funa();
//	funb();
//	return 0;
//}
//
//int main()
//{
//	GenLinkList	  imylist;
//	GenLinkList   dmylist;
//	InitGenLinkList(&imylist, sizeof(int));
//	InitGenLinkList(&dmylist, sizeof(double));
//
//	for (int i = 0; i < 5; ++i)
//	{
//		Push_Back(&imylist, &i);
//	}
//	double dx = 12.25;
//	for (int i = 0; i < 5; ++i)
//	{
//		Push_Back(&dmylist, &dx);
//		++dx;
//	}
//	return 0;
//}
//
//#include"my_list_stack.hpp"
//int main()
//{
//	LinkStack mys;
//	InitLinkStack(&mys);
//	const int n = 10;
//	for (int i = 0; i < n; ++i)
//	{
//		Push(&mys, i);
//	}
//	int val;
//	while (!IsEmpty(&mys))
//	{
//		Pop(&mys, &val);
//		printf("val: %d\n", val);
//	}
//	DestroyLinkStack(&mys);
//	return 0;
//}
//
//struct Student
//{
//	int id;
//	char name[20];
//};
//int main()
//{
//	int a = 10;
//	struct Student s1 = { 900,"yhping" };
//	struct Student s2;
//	s1 = s2;
//	s1 = a;
//	a = s1;
//
//
//}
//
//#include"my_stack.hpp"
//int main()
//{
//	SeqStack mys;
//	InitStack(&mys);
//	for (int i = 0; i < 15; ++i)
//	{
//		Push(&mys, i);
//	}
//	while (!StackEmpty(&mys))
//	{
//		int val = 0;
//		Pop(&mys, &val);
//		printf("%d \n", val);
//	}
//	DestroyStack(&mys);
//	return 0;
//}
//
//
//#include"GenDuLinkList.hpp"
//int main()
//{
//	GenLinkList imylist;
//	GenLinkList dmylist;
//	InitGenLinkList(&imylist, sizeof(int));
//	InitGenLinkList(&imylist, sizeof(double));
//
//	int val = 10;
//	double dx = 12.25;
//
//	Push_Back(&imylist, &val);
//	Push_Back(&dmylist, &dx);
//
//}
//
//#include"DuLinkList.hpp"
//int main()
//{
//	DuLinkList mylist;
//	InitLinkList(&mylist);
//	for (int i = 10; i < 15; ++i)
//	{
//		Push_Back(&mylist, i);
//	}
//	Print(&mylist);
//	return 0;
//}
//
//
//#include<string.h>
//#include<stdio.h>
//#include<iostream>	
//#include<set>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//int main()
//{
//	std::unordered_map<std::string, int> siunmap;
//	siunmap["yhping"] = 23;
//	siunmap["hm"] = 12;
//	siunmap["tulun"] = 18;
//	siunmap["yutun"] = 26;
//
//	return 0;
//}
//
//
//int main()
//{
//	const int n = 20;
//	std::vector<int> ivec;
//	std::set<int> iset;
//	ivec.reserve(n);
//	for (int i = 0; i < n; ++i)
//	{
//		ivec.push_back(rand() % 20);
//	}
//	cout << "--------------ivec data -------------" << endl;
//	for (auto& x : ivec)
//	{
//		cout << "\t" << x;
//	}
//	cout << endl;
//	iset.insert(ivec.begin(), ivec.end());
//	cout << "---------------iset data ----------------" << endl;
//	for (auto& x : iset)
//	{
//		cout << "\t" << x;
//	}
//	cout << endl;
//	return 0;
//}
//
//struct A
//{
//	A()
//	{
//
//	}
//	int a;
//	virtual void func() {}
//	virtual void print() {}
//};
//struct B : virtual A	// sizeof(B) 8
//{
//	B()
//	{
//
//	}
//	virtual void func() {}
//	virtual void print() {}
//	int b;
//};
//struct  C : virtual A	// sizeof(C) 8
//{
//
//	C()
//	{
//	}
//	virtual void func() {}
//	virtual void print() {}
//	int c;
//};
//struct D : public B, public C   // sizeof(D) 24
//{
//	D()
//	{
//
//	}
//	virtual void func() {}
//	virtual void print() {}
//	int d;
//};
//int main()
//{
//	D dx;
//	cout << sizeof(dx) << endl;
//	dx.a = 1;
//	dx.b = 2;
//	dx.c = 3;
//	dx.d = 4;
//	dx.a = 5;
//
//}
//
//
//#include"NotHead.hpp"
//
//int main()
//{
//	LinkList head = NULL;
//	for (int i = 0; i < 10; ++i)
//	{
//		Push_Front(&head, i);
//	}
//	PrintList(head);
//	ResList(&head);
//	PrintList(head);
//	ResList(&head);
//	PrintList(head);
//	ResList(&head);
//	PrintList(head);
//	return 0;
//}
//
//
//class MyString
//{
//private:
//	char* str;
//public:
//	//带参构造
//	MyString(const char* s = nullptr) :str(nullptr)
//	{
//		if (s != nullptr)
//		{
//			int len = strlen(s);
//			str = new char[len + 1];	 // []
//			strcpy(str, s);
//		}
//	}
//
//	//缺省拷贝构造   浅拷贝
//	//MyString(const MyString &other) :str(other.str)	{  } 
//	//MyString &operator=(const MyString &other) 
//	//{
//	//	this->str = other.str;
//	//	return *this;
//	//}// MyString stra("yhping");
//	 // MyString strb("tulun");
//	 // stra = strb;
//	// 深拷贝
//	MyString(const MyString& other) :str(nullptr)
//	{
//		if (nullptr != other.str)
//		{
//			int len = strlen(other.str);
//			str = new char[len + 1];
//			strcpy(str, other.str);
//		}
//	}
//
//	MyString& operator=(const MyString& other)
//	{
//		if (this != &other)
//		{
//			delete[]str;
//			str = nullptr;
//			if (nullptr != other.str)
//			{
//				int len = strlen(other.str);
//				str = new char[len + 1];
//				strcpy(str, other.str);
//			}
//		}
//		return *this;
//	}//赋值重载	 stra = strb;
//	// MyString stra("yhping");
//	   // MyString strb(stra);
//	   // const MyString strc("yhping");
//	   // MyString strd(strc); 
//	~MyString()
//	{
//		delete[] str;	// free(str) delete delete [] nullptr;
//		str = nullptr;
//	}//析构函数
//
//	MyString(MyString&& other)
//	{
//		str = other.str;
//		other.str = nullptr;
//	}//移动构造
//
//	MyString& operator=(MyString&& other)
//	{
//		if (this != &other)
//		{
//			delete[] str;
//			str = other.str;
//			other.str = nullptr;
//		}
//		return *this;
//
//	}//移动复制重载
//
//	void Print() const
//	{
//		if (nullptr != str)
//		{
//			printf("str: %s \n", str);
//		}
//		else
//		{
//			printf("empty string \n");
//		}
//	}
//};
//MyString func(const char* s)
//{
//	MyString tmp(s);
//	return tmp;
//}
//int main()
//{
//	MyString stra("hello");
//	stra = func("yhpinghello");
//	return 0;
//}
//
//
//void func(MyString str)
//{
//}
//MyString GetString()
//{
//	MyString stra("yhping");
//	return stra;
//}		 // c++98
//int main()
//{
//	MyString stra("yhping");
//	MyString strb(stra);
//	func(stra);
//}
//
//
//int main()
//{
//	MyString stra;
//	MyString strb("yhpinghello");
//	stra.Print();
//	strb.Print();
//
//}
//
//#include <iostream>  
//#include <string>  
//#include <map>  
//#include <vector>
//using namespace std;
//
//
//// DNS 记录结构  
//struct DNSRecord
//{
//	std::string ipAddress;
//	std::string type;  //IPv4,IPv6
//};
//
//// 使用 multimap 存储 DNS 记录  
//std::multimap<std::string, DNSRecord> dnsRecords;
//
//// 添加 DNS 记录到 multimap  
//void addDNSRecord(const std::string& domain, const DNSRecord& record)
//{
//	dnsRecords.insert({ domain, record });
//}
//
//// 根据域名查询 DNS 记录  
//std::vector<DNSRecord> findDNS(const std::string& domain)
//{
//	std::vector<DNSRecord> results;
//	auto range = dnsRecords.equal_range(domain);
//	for (auto it = range.first; it != range.second; ++it) {
//		results.push_back(it->second);
//	}
//	return results;
//}
//
//int main()
//{
//	addDNSRecord("baidu.com", { "192.168.23.1", "IPv4" });
//	addDNSRecord("baidu.com", { "2002::c0a8:1701", "IPv6" });
//	addDNSRecord("tulun.net", { "192.168.0.23", "IPv4" });
//	addDNSRecord("tulun.net", { "2002::c0a8:17", "IPv4" });
//
//	// 查询并打印 DNS 记录  
//	std::string domainToQuery = "baidu.com";
//	std::cout << "DNS records for " << domainToQuery << ":" << std::endl;
//	auto records = findDNS(domainToQuery);
//	for (const auto& record : records)
//	{
//		std::cout << "IP: " << record.ipAddress << ", Type: " << record.type << std::endl;
//	}
//
//	return 0;
//}
//
//
//#include <algorithm>
//#include <cstdlib>
//#include <cstddef>
//#include <ctime>
//#include <iostream>
//#include <iterator>
//#include <map>
//#include <sstream>
//#include <string>
//#include <vector>
//using namespace std;
////	数据点类型
//class DataPoint
//{
//	int x, y;     // 位置坐标
//	time_t time;  // 目睹时间
//public:
//	DataPoint() : x(0), y(0), time(0) {}
//	DataPoint(int xx, int yy, time_t tm)
//		:x(xx), y(yy), time(tm) {}
//	int getX() const { return x; }
//	int getY() const { return y; }
//	const time_t* getTime() const { return &time; }
//};
//
////动物名字符串数组
//std::string animal[] =
//{
//  "chipmunk", "beaver", "marmot", "weasel",
//  "squirrel", "ptarmigan", "bear", "eagle",
//  "hawk", "vole", "deer", "otter", "hummingbird",
//};
////"花栗鼠","海狸","土拨鼠","黄鼠狼",
////"松鼠","松鸡","熊","鹰",
////"鹰","田鼠","鹿","水獭","蜂鸟",
//// ASZ 动物数组元素个数
//const int ASZ = sizeof animal / sizeof * animal;
//// 初始化vecctor;
//std::vector<string> animals(animal, animal + ASZ);
//
//// 信息组合到pair 对中，为输出准备
//typedef pair<string, DataPoint> Sighting;
//
//ostream& operator<<(ostream& out, const Sighting& s)
//{
//	return out << s.first << " sighted at x= "
//		<< s.second.getX() << ", y= " << s.second.getY()
//		<< ", time = " << ctime(s.second.getTime());
//}
//
//// 观光发现者
//class SightingGen
//{
//private:
//	std::vector<string>& animals;
//	enum { D = 100 };
//public:
//	SightingGen(vector<string>& an) : animals(an) {}
//	Sighting operator()()
//	{
//		Sighting result;
//		int select = rand() % animals.size();
//		result.first = animals[select];
//		result.second = DataPoint(rand() % D, rand() % D, time(0));
//		return result;
//	}
//};
//
////显示动物菜单，允许用户选择一个，返回索引值
//int menu()
//{
//	cout << "select an animal or 'q' to quit: ";
//	for (size_t i = 0; i < animals.size(); i++)
//	{
//		cout << '[' << i << ']' << animals[i] << ' ';
//	}
//	cout << endl;
//	string reply; // 回复
//	cin >> reply;
//	if (reply.at(0) == 'q') return -1;
//	istringstream r(reply);
//	int i;
//	r >> i; // Converts to int
//	i %= animals.size();
//	return i;
//}
//
//int main()
//{
//	typedef multimap<string, DataPoint> DataMap;
//	typedef DataMap::iterator DMIter;
//	DataMap sightings;
//	srand(time(0));  // 设置随机种子
//	generate_n(inserter(sightings, sightings.begin()), 50, SightingGen(animals));
//	// 打印所有内容
//	copy(sightings.begin(), sightings.end(), ostream_iterator<Sighting>(cout, ""));
//	//
//	cout << "-------打印选定动物的目击记录------" << endl;
//	for (int count = 1; count < 10; count++)
//	{
//		//使用菜单进行选择
//		int i = menu();
//		// 随机生成（用于自动化测试）
//		//int i = rand() % animals.size();
//		//"range"中的迭代器表示匹配范围的开始和结束：
//		if (-1 == i) break;
//		pair<DMIter, DMIter> range = sightings.equal_range(animals[i]);
//		copy(range.first, range.second, ostream_iterator<Sighting>(cout, ""));
//	}
//	return 0;
//} ///:~
//
//class MyString
//{
//public:
//	struct StrNode
//	{
//		int len;  // 字符串的长度
//		int capa; // 空间大小
//		int ref;  // 应用计数
//		char data[];
//	};
//private:
//	StrNode* pstr;
//public:
//	empty();
//	length();
//	swap();
//public:
//	MyString(const char* str = nullptr);
//	~MyString();
//
//	operator+(const MyString& st);
//	operator+(const char* str);
//};
//
//
//
//typedef std::multimap<std::string, std::string> PhoneMap;
//int main()
//{
//	PhoneMap phonebooks =
//	{
//#include"phonebook.txt"
//	};
//	cout << "---------print name:phone------------" << endl;
//	for (const auto& px : phonebooks)
//	{
//		cout << "name: " << px.first << " phone: " << px.second << endl;
//	}
//	cout << "_______________________________________" << endl;
//	cout << " -------------find name-----------------" << endl;
//	std::string name;
//	while (cin >> name, name != "end")
//	{
//		auto itpair = phonebooks.equal_range(name);
//		if (itpair.first != phonebooks.end() && itpair.first->first == name)
//		{
//			cout << "name: " << name;
//			for (auto it = itpair.first; it != itpair.second; ++it)
//			{
//				cout << "\t" << it->second;
//			}
//			cout << endl;
//		}
//		else
//		{
//			cout << "name: " << name << " not key" << endl;
//		}
//	}
//	return 0;
//}
//
//typedef std::map<int, std::string> ISMap;
//typedef std::multimap<int, std::string> ISMulMap;
//
//int main()
//{
//	ISMap ismap;
//	ISMulMap ismulmap;
//	cout << "-------------map::insert-----------------" << endl;
//	auto it = ismap.insert(std::make_pair(23, "yhping"));
//	cout << "是否成功插入键值对： " << it.second << endl;
//	cout << it.first->first << " " << it.first->second << endl;
//	it = ismap.insert(std::make_pair(23, "tulun"));
//	cout << "是否成功插入键值对： " << it.second << endl;
//	cout << it.first->first << " " << it.first->second << endl;
//	cout << "--------------------------------------------" << endl;
//	ismap.operator[](34) = "yhping";
//
//	cout << "-------------multimap::insert-----------------" << endl;
//	auto mit = ismulmap.insert(std::make_pair(23, "yhping"));
//	cout << mit->first << " " << mit->second << endl;
//	mit = ismulmap.insert(std::make_pair(23, "tulun"));
//	cout << mit->first << " " << mit->second << endl;
//	cout << "--------------------------------------------" << endl;
//
//}
//
//
//#define Sort_(Type) Sort_##Type
//
//#define SORT(Type) \
//void Sort_(Type)(Type *ar,int n)  \
//{	    \
//    printf("sort");  \
//}
//
//SORT(int)	// Sort_int
//SORT(double) // Sort_double
//int main()
//{
//	int ar[10] = {};
//	int n = 10;
//	Sort_(int)(ar, n);
//}
//
//int main()
//{
//	const int n = 10;
//	std::map<int, char> icmap;
//	for (int i = 0; i < n; ++i)
//	{
//		icmap[rand() % 1000] = 'a' + i;
//	}
//	for (const auto& x : icmap)
//	{
//		cout << x.first << " " << x.second << endl;
//	}
//
//	for (int i = 41; i <= 170; ++i)
//	{
//		auto it = icmap.lower_bound(i);
//		cout << i << "==> " << it->first << endl;
//	}
//	return 0;
//
//}
//
//int main()
//{
//	// name, age;
//	std::map<std::string, int> simap;
//	simap["yhping"] = 23;
//	simap["hm"] = 12;
//	simap["cyc"] = 34;
//
//	for (auto& x : simap)
//	{
//		cout << "name: " << x.first << " age " << x.second << endl;
//	}
//
//	auto it = simap.find("hmmm");
//	if (it != simap.end())
//	{
//		cout << it->second << endl;
//	}
//	else
//	{
//		cout << "find not ... key: " << endl;
//	}
//
//	return 0;
//
//}
//
//int main()
//{
//	const int n = 1000;
//	int ar[n] = {};
//	for (int i = 0; i < n; ++i) { ar[i] = rand() % 100 + 1; }
//	std::map<int, int> iimap;
//	for (int i = 0; i < n; ++i)
//	{
//		iimap[ar[i]] += 1;
//	}
//	for (auto& x : iimap)
//	{
//		cout << "key ip : " << x.first << " ref: " << x.second << endl;
//	}
//
//	std::multimap<int, int, std::greater<int> > ipmap;
//	for (auto& x : iimap)
//	{
//		ipmap.insert(std::multimap<int, int, std::greater<int> >::value_type(x.second, x.first));
//	}
//
//	int num = 0;
//	cout << "____________________________________" << endl;
//	for (auto& x : ipmap)
//	{
//		cout << "ref: " << x.first << " ip : " << x.second << endl;
//		if (++num >= 15) break;
//	}
//	cout << "______________________________________" << endl;
//
//
//	return 0;
//}
//
//
//int main()
//{	 // age; name 
//	std::map<int, std::string> ismap;
//	ismap[23] = "yhping";
//	ismap[12] = "whq";
//	ismap[34] = "cyc";
//	ismap[8] = "duanzhe";
//	ismap[18] = "hx";
//	ismap[38] = "hm";
//	return 0;
//}
//
//
//int main()
//{	 // age; name 
//	std::map<int, std::string> ismap;
//	ismap.insert(std::map<int, string>::value_type(23, "yhping"));
//	ismap.insert(std::map<int, string>::value_type(12, "whq"));
//	ismap.insert(std::map<int, string>::value_type(34, "cyc"));
//	ismap.insert(std::map<int, string>::value_type(8, "duanzhe"));
//	ismap.insert(std::map<int, string>::value_type(18, "hx"));
//	ismap.insert(std::map<int, string>::value_type(38, "hm"));
//	int age;	// map . at(key);
//	// operator[](key)
//	while (cin >> age, age != -1)
//	{
//		std::string name = ismap[age];
//		cout << name << endl;
//	}
//	return 0;
//}
//
//template<class T1, class T2 >
//struct my_pair
//{
//	using first_type = T1;
//	using second_type = T2;
//public:
//	first_type first;
//	second_type second;
//public:
//	my_pair() {}
//	my_pair(const T1& a, const T2& b) :first(a), second(b) {}
//};
//int main()
//{	 // age; name 
//	std::map<int, std::string> ismap;
//	ismap.insert(std::map<int, string>::value_type(23, "yhping"));
//	ismap.insert(std::map<int, string>::value_type(12, "whq"));
//	ismap.insert(std::map<int, string>::value_type(34, "cyc"));
//	ismap.insert(std::map<int, string>::value_type(8, "duanzhe"));
//	ismap.insert(std::map<int, string>::value_type(18, "hx"));
//	ismap.insert(std::map<int, string>::value_type(38, "hm"));
//	int age;
//	while (cin >> age, age != -1)
//	{
//		try
//		{
//			std::string name = ismap.at(age);
//			cout << "name: " << name << endl;
//		}
//		catch (std::out_of_range& e)
//		{
//			cout << e.what() << endl;
//		}
//	}
//	return 0;
//}
//
//
//
//int main()
//{	 // age; name 
//	std::map<int, std::string> ismap;
//	ismap.insert(std::map<int, string>::value_type(23, "yhping"));
//	ismap.insert(std::map<int, string>::value_type(12, "whq"));
//	ismap.insert(std::map<int, string>::value_type(34, "cyc"));
//	ismap.insert(std::map<int, string>::value_type(8, "duanzhe"));
//	auto x = ismap.insert(std::map<int, string>::value_type(18, "hx"));
//	cout << x.second << endl; // 1
//	cout << x.first->first << " " << x.first->second << endl;
//
//	x = ismap.insert(std::map<int, string>::value_type(18, "hxx"));
//
//	auto it = ismap.begin();
//
//	cout << it->first << " " << it->second << endl;
//
//	ismap.insert(it, std::map<int, string>::value_type(38, "hm"));
//
//	it = ismap.begin();
//	for (; it != ismap.end(); ++it)
//	{
//		cout << it->first << " " << it->second << endl;
//	}
//
//	for (auto& x : ismap)	// value_type  pair // first second
//	{
//		cout << typeid(x).name() << endl;
//		cout << x.first << " " << x.second << endl;
//	}
//
//
//	return 0;
//
//
//
//
//}
//
//
//
//#define  _CRT_SECURE_NO_WARNINGS
//#include"NotHead.hpp"
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include<string.h>
//int main()
//{
//	LinkList head = NULL;
//	for (int i = 0; i < 10; ++i)
//	{
//		Push_Back(&head, i);
//	}
//
//	PrintList(head);
//	return 0;
//}
//
//
//
//
//
//#define  _CRT_SECURE_NO_WARNINGS
//#include"LinkList.hpp"
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//#include<string.h>
//
//int main()
//{
//	LinkList mylist;
//	InitList(&mylist);
//	int n = 13;
//	for (int i = 0; i < n; ++i)
//	{
//		Push_Back(&mylist, i);
//	}
//	PrintInfo(&mylist);
//	return 0;
//}
//
//struct Student
//{
//	char s_id[20];
//	char s_name[20];
//	char s_sex[10];
//	int s_age;
//};
//void PrintStudent(const void* p)
//{
//	const struct Student* sp = (const struct Student*)p;
//	printf("id: %s name: %s sex: %s age: %d\n",
//		sp->s_id, sp->s_name, sp->s_sex, sp->s_age);
//
//}
//// pid s_id;    ps => student;
//bool CompId(const void* pid, const void* ps)
//{
//	const char* sid = (const char*)pid;
//	const Student* sps = (const Student*)ps;
//	return strcmp(sid, sps->s_id) == 0;
//}
//
//bool CompName(const void* pname, const void* ps)
//{
//	const char* sn = (const char*)pname;
//	const Student* sps = (const Student*)ps;
//	return strcmp(sn, sps->s_name) == 0;
//}
//bool CompAge(const void* pname, const void* ps)
//{
//	const int* sn = (const int*)pname;
//	const Student* sps = (const Student*)ps;
//	return (*sn == sps->s_age);
//}
//int main()
//{
//	GenSeqList smylist;
//	InitGenSeqList(&smylist, sizeof(struct Student));
//	struct Student studx[] = {
//#include"yhp.txt"
//	};
//	int n = sizeof(studx) / sizeof(studx[0]);
//	for (int i = 0; i < n; ++i)
//	{
//		Push_Back(&smylist, &studx[i]);
//	}
//
//	PrintInfo(&smylist, PrintStudent);
//	struct Student stud;
//	char id[20] = {}, name[10] = {};
//	int age;
//	int select = 0;
//	int pos = -1;
//	do
//	{
//		printf("***************\n");
//		printf("* 1.find id   *\n");
//		printf("* 2.find name *\n");
//		printf("* 3.find age  *\n");
//		printf("* 0.quit      *\n");
//		printf("***************\n");
//		printf("input select : ");
//		scanf("%d", &select);
//		switch (select)
//		{
//		case 0: break;
//		case 1:
//			printf("input s_id ");
//			scanf("%s", id);
//			pos = ElemFindValue(&smylist, id, CompId);
//			printf("pos : %d \n", pos);
//			break;
//		case 2:
//			printf("input name ");
//			scanf("%s", name);
//			pos = ElemFindValue(&smylist, name, CompName);
//			printf("pos : %d \n", pos);
//			break;
//		case 3:
//			printf("input age ");
//			scanf("%d", &age);
//			pos = ElemFindValue(&smylist, &age, CompAge);
//			printf("pos : %d \n", pos);
//		default:
//			break;
//		}
//	} while (select != 0);
//	DestroyGenSeqList(&smylist);
//	return 0;
//}
//
//int main()
//{
//	int a = 10, b = 20;
//	int* (ar[3])[10] = { &a,&b };
//	int* br[3][10] = { &a,&b };
//
//}
//
//
//struct Node
//{
//	char s_id[10];
//	int s_age;
//};
//struct Node a = { "2024001",12 };
//int main()
//{
//
//	struct Node b = { "2024001",12 };
//	//scanf("%s %d", b.s_id, &b.s_age);
//	int x = memcmp(&a, &b, sizeof(struct Node));
//	printf("x: %d \n", x);
//	return 0;
//}
//
//struct Student
//{
//	char s_id[20];
//	char s_name[20];
//	char s_sex[10];
//	int s_age;
//};
//
//void PrintStudent(const void* p)
//{
//	const struct Student* sp = (const struct Student*)p;
//	printf("id: %s name: %s sex: %s age: %d\n",
//		sp->s_id, sp->s_name, sp->s_sex, sp->s_age);
//
//}
//void PrintInt(const void* p)
//{
//	const int* ip = (const int*)p;
//	printf("%d ", *ip);
//}
//void PrintDouble(const void* p)
//{
//	const double* dp = (const double*)p;
//	printf("%lf ", *dp);
//}
//int main()
//{
//	GenSeqList  smylist;
//	InitGenSeqList(&smylist, sizeof(struct Student));
//	struct Student stud;
//	while (scanf("%s %s %s %d",
//		stud.s_id,
//		stud.s_name,
//		stud.s_sex,
//		&stud.s_age), stud.s_age != 0)
//	{
//		Push_Back(&smylist, &stud);
//	}
//	PrintInfo(&smylist, PrintStudent);
//	while (scanf("%s %s %s %d",
//		stud.s_id,
//		stud.s_name,
//		stud.s_sex,
//		&stud.s_age), stud.s_age != 0)
//	{
//		int pos = FindValue(&smylist, &stud);
//		if (pos != -1)
//		{
//			printf("find ... \n");
//		}
//		else
//		{
//			printf("find not ... \n");
//		}
//
//	}
//	DestroyGenSeqList(&smylist);
//	return 0;
//}
//
//int main()
//{
//	int n = 8;
//	GenSeqList dmylist;
//	InitGenSeqList(&dmylist, sizeof(double));
//	double val = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		val = rand() % 100;
//		val /= 10;
//		Push_Front(&dmylist, &val);
//	}
//	PrintInfo(&dmylist, PrintDouble);
//	while (scanf("%lf", &val), val != -1)
//	{
//		int pos = FindValue(&dmylist, &val);
//		if (pos != -1)
//		{
//			printf("find .. \n");
//		}
//		else
//		{
//			printf("not find ...\n");
//		}
//	}
//	DestroyGenSeqList(&dmylist);
//	return 0;
//}
//
//int main()
//{
//	int n = 8;
//	GenSeqList imylist;
//	InitGenSeqList(&imylist, sizeof(int));
//	int val = 0;
//	for (int i = 0; i < n; ++i)
//	{
//		val = rand() % 100;
//		Push_Front(&imylist, &val);
//	}
//	PrintInfo(&imylist, PrintInt);
//	while (scanf("%d", &val), val != -1)
//	{
//		int pos = FindValue(&imylist, &val);
//		if (pos != -1)
//		{
//			printf("find .. \n");
//		}
//		else
//		{
//			printf("not find ...\n");
//		}
//	}
//	DestroyGenSeqList(&imylist);
//	return 0;
//}
//
//int main()
//{
//	GenSeqList  smylist;
//	InitGenSeqList(&smylist, sizeof(struct Student));
//	struct Student stud;
//	while (scanf("%s %s %s %d",
//		stud.s_id,
//		stud.s_name,
//		stud.s_sex,
//		&stud.s_age), stud.s_age != 0)
//	{
//		Push_Back(&smylist, &stud);
//	}
//	PrintInfo(&smylist, PrintStudent);
//	DestroyGenSeqList(&smylist);
//	return 0;
//}
//
//void PrintInt(const void* p)
//{
//	const int* ip = (const int*)p;
//	printf("%d ", *ip);
//}
//void PrintDouble(const void* p)
//{
//	const double* dp = (const double*)p;
//	printf("%lf ", *dp);
//}
//int main()
//{
//	GenSeqList imylist;     // int 
//	GenSeqList dmylist; 	// double;
//	InitGenSeqList(&imylist, sizeof(int));
//	InitGenSeqList(&dmylist, sizeof(double));
//	int n = 8;
//	int ival = 10;
//	for (int i = 0; i < n; ++i)
//	{
//		Push_Back(&imylist, &ival);
//		ival++;
//	}
//	double dval = 12.25;
//	for (int i = 0; i < n; ++i)
//	{
//		Push_Back(&dmylist, &dval);
//		dval++; // 13.25; dval+= 0.01;
//	}
//	PrintInfo(&imylist, PrintInt);
//	PrintInfo(&dmylist, PrintDouble);
//
//
//
//}
//
//// 返回类型 + 参数表
//void* PrintInt(const void* p)
//{
//	const int* ip = (const int*)p;
//	printf("%d ", *ip);
//	return (void*)(ip + 1);
//}
//void* PrintDouble(const void* p)
//{
//	const double* dp = (const double*)p;
//	printf("%lf ", *dp);
//	return (void*)(dp + 1);
//}
//void Print(void* vp, int n, void* (*pfun)(const void*))
//{
//	for (int i = 0; i < n; ++i)
//	{
//		vp = pfun(vp);
//	}
//	printf("\n");
//}
//int main()
//{
//	int ar[] = { 12,23,34,45 };
//	double dr[] = { 1.2,2.3,3.4,4.5,5.6,6.7 };
//	//void a; // sizeof(void);抽象类型
//	void* vp = NULL;
//	int a = 10;
//	char ch = 'a';
//	vp = &a;
//	int* ip = (int*)vp;
//
//	//*vp;
//	//vp = vp + 1; //vs2019; g++ gcc; 
//
//	vp = &ch;
//
//	vp = &vp;
//
//
//	int in = sizeof(ar) / sizeof(ar[0]);
//	int dn = sizeof(dr) / sizeof(dr[0]);
//	Print(ar, in, PrintInt);
//	Print(dr, dn, PrintDouble);
//	return 0;
//}
//
//int Add(int, int);
//int Add(int a, int b)
//{
//	return a + b;
//}
//int Max(int a, int b) { return a > b ? a : b; }
//
//void Print(int a, int b, int (*pfun)(int, int))
//{
//	if (NULL != pfun)
//	{
//		int x = pfun(a, b);
//		printf("x: %d \n", x);
//	}
//}
//int main()
//{
//	Print(12, 23, Add);
//	Print(12, 23, Max);
//	return 0;
//}
//
//
//int main()
//{
//	int (*pfun)(int, int) = NULL;
//	pfun = Add;
//	int a = pfun(12, 23);
//	a = (*pfun)(12, 23);
//
//	pfun = Max;
//	a = Max(12, 23);
//
//}
//
//int main()
//{
//	int a = Add(12, 23);
//	Add;   &Add;
//	return 0;
//}
//
//
//
//int Inc(int a) { return a += 1; }
//
//
//struct Student
//{
//	char s_id[20];
//	char s_name[20];
//	char s_sex[10];
//	int s_age;
//};
//int main()
//{
//	GenSeqList imylist;     // int 
//	GenSeqList dmylist; 	// double;
//	GenSeqList smylist;
//
//	InitGenSeqList(&imylist, sizeof(int));
//	InitGenSeqList(&dmylist, sizeof(double));
//	InitGenSeqList(&smylist, sizeof(struct Student));
//
//
//}
//
//int main()
//{
//	(int*)malloc(sizeof(int));
//	//void a; // error;
//	void* vp = NULL;
//	int a = 10;
//	double d = 12.23;
//	char ch = 'a';
//	vp = &a;   // sizeof(void); 
//	//vp += 1;	 // gcc; 
//	int* ip;
//	ip = (int*)vp;
//
//	vp = &d;
//	double* dp = NULL;
//	dp = (double*)vp;
//
//	vp = &ch;
//	char* cp = (char*)vp;
//
//	vp = &vp;
//
//
//
//}
//
//
//int main()
//{
//	SeqList mylist;
//	InitSeqList(&mylist);
//	int n = rand() % 100;
//	for (int i = 0; i < n; ++i)
//	{
//		Push_Back(&mylist, rand() % 100);
//	}
//	PrintInfo(&mylist);
//	int pos = 0;
//	do
//	{
//		pos = rand() % 100;
//		ElemType val;
//		if (GetElem(&mylist, pos, &val))
//		{
//			printf("pos: %d val: %d \n", pos, val);
//		}
//		else
//		{
//			printf("error pos : %d \n", pos);
//		}
//		pos -= 1;
//	} while (pos != -1);
//	DestroySeqList(&mylist);
//	return 0;
//}
//
//int main()
//{
//	SeqList mylist;
//	InitSeqList(&mylist);
//	int n = 13;
//	for (int i = 0; i < n; ++i)
//	{
//		Push_Back(&mylist, rand() % 100);
//	}
//	PrintInfo(&mylist);
//	SelectSort(&mylist);
//	PrintInfo(&mylist);
//	DestroySeqList(&mylist);
//	return 0;
//}
//
//
//int main()
//{
//	int ar[10] = { 12,23,34,45,56,67,78,89,90,100 };
//	FILE* pf = fopen("yhp.txt", "w");
//	if (NULL == pf) return 1;
//	for (int i = 0; i < 10; ++i)
//	{
//		fprintf(pf, "%5d", ar[i]);
//	}
//	//exit(0);
//	fclose(pf); // 
//	pf = NULL;
//	return 0;
//}
//
//int main()
//{
//	SeqList mylist;
//	InitSeqList(&mylist);
//	int n = 15;
//	srand(time(NULL)); // time 1970 1:1 .... 
//	for (int i = 0; i < n; ++i)
//	{
//		Push_Back(&mylist, rand() % 100);
//	}
//	PrintInfo(&mylist);
//	InsertSort(&mylist);
//	PrintInfo(&mylist);
//	DestroySeqList(&mylist);
//	return 0;
//}
//
//#include<stdio.h>
//#define ADD(x) (x)*(x)
//int main()
//{
//	int a = 4, b = 6, c = 7, d = ADD(a + b) * c;
//	int e = (4 + 6) * (4 + 6) * 7;
//	printf("%d \n", d);
//	printf("%d \n", e);
//	return 0;
//}
//
//#include"SeqList.hpp"
//
//int main()
//{
//	SeqList mylist; // mylist.data mylist.capacity; mylist.cursize
//	InitSeqList(&mylist);
//	int n = 23;
//	for (int i = 0; i < n; ++i)
//	{
//		Push_Front(&mylist, i);
//		PrintInfo(&mylist);
//	}
//
//	//
//	DestroySeqList(&mylist);
//	return 0;
//}
//
//
//int main()
//{
//	SeqList mylist; // mylist.data mylist.capacity; mylist.cursize
//	InitSeqList(&mylist);
//
//
//	int* p;
//	int* s = NULL;
//	int* ip = (int*)malloc(sizeof(int));
//	if (NULL == ip) exit(1);
//	//
//	free(ip);
//	ip = NULL;
//	//
//	DestroySeqList(&mylist);
//}
//
//
//SeqList my;
//
//int main()
//{
//	SeqList mylist;
//
//	return 0;
//}
//
//
//#include<typeinfo>
//using namespace std;
//
//#define SINT  int *
//typedef int* PINT;
//int main()
//{
//	SINT a, b;
//	PINT x, y;
//	// a type ; b  byte;
//	// x type ; y  byte;
//	//typeid(a).name() x; "int *" x;
//	printf("a type %s b type %s \n", typeid(a).name(), typeid(b).name());
//	printf("x type %s y type %s \n", typeid(x).name(), typeid(y).name());
//
//}
//
//
//typedef int INT;
//typedef unsigned char u_char;
//typedef char Array[10];
//typedef void (*pfun)();
//int main()
//{
//	Array ar, br;
//	return 0;
//}
//
//int main()
//{
//	int ar[100];
//	int capacity = 100;
//	int cursize = 0;
//	ar[0] = 12;
//	cursize += 1;
//	ar[1] = 23;
//	cursize += 2;
//
//
//}
//
//int main()
//{
//	int ar[100];
//	// 
//	double dr[1000];
//
//	char stra[200];
//}
//#endif 