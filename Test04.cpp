#include<stdio.h>
#include"MBTree.h"
int main()
{
	BTree myt;
	InitBTree(&myt);
	char str[] = { "qwertyuiopasdfghjklzxcvbnm" };
	for (int i = 0; str[i] != '\0'; ++i)
	{
		ElemType val = { str[i],NULL };
		Insert(&myt, val);
	}
	PrintLevel(&myt);

	return 0;
}