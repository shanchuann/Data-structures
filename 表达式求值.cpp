#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<assert.h>
#include<ctype.h>
#include"GenListStack.h"
bool IsOperator(const char ch);

#define BEGIN			1
#define NUMBER			2
#define NUMBER_OUT		3
#define OPERATOR		4
#define OPERATOR_OUT	5
#define FLOATNUMBER     6
#define FLOATFIRST    	7
#define LEFTBRACKET		8
#define RIGHTBRACKET	9
bool CheckMidStr(const char* str)
{
	GenListStack mys;
	InitGenListStack(&mys, sizeof(char));
	bool res = false;
	int tag = BEGIN;
	if (NULL == str || '\0' == *str) return res;
	for (const char* p = str; *p != '\0'; ++p)
	{
		switch (tag)
		{
			case BEGIN:	
				if (IsOperator(*p)) { goto END; }
				else if (*p == '.') { goto END; }
				else if (isspace(*p)) { /*'\t' '\n' */ }
				else if (isdigit(*p)) { tag = NUMBER; }
				else if (*p == '(') 
				{ 
					tag = LEFTBRACKET;
					Push(&mys, p);
				}
				break;
			case NUMBER: 
				if (isdigit(*p)) {}
				else if (*p == '.') { tag = FLOATFIRST; }
				else if (isspace(*p)) { tag = NUMBER_OUT; }
				else if (IsOperator(*p)) { tag = OPERATOR; }
				else if (*p == ')') { tag = RIGHTBRACKET; }
				break;
			case NUMBER_OUT: 
				if (isdigit(*p)) { goto END; }
				else if (isspace(*p)) {}
				else if (IsOperator(*p)) { tag = OPERATOR; }
				else if (*p == ')') { tag = RIGHTBRACKET; }
				break;
			case OPERATOR: 
				if (IsOperator(*p)) { goto END; }
				else if (isspace(*p)) { tag = OPERATOR_OUT; }
				else if (isdigit(*p)) { tag = NUMBER; }
				else if (*p == '(')
				{
					tag = LEFTBRACKET;
					Push(&mys, p);
				}
				break;
			case OPERATOR_OUT: 
				if (isspace(*p)) {}
				else if (IsOperator(*p)) { goto END; }
				else if (isdigit(*p)) { tag = NUMBER; }
				else if (*p == '(')
				{
					tag = LEFTBRACKET;
					Push(&mys, p);
				}
				break;
			case FLOATFIRST: 
				if (isdigit(*p)) { tag = FLOATNUMBER; }
				else if (isspace(*p)) { tag = NUMBER_OUT; }
				else if (IsOperator(*p)) { tag = OPERATOR; }
				else if (*p == '.') { goto END; }
				break;
			case FLOATNUMBER: 
				if (isdigit(*p)) {}
				else if (isspace(*p)) { tag = NUMBER_OUT; }
				else if (IsOperator(*p)) { tag = OPERATOR; }
				else if (*p == '.') { goto END; }
				else if (*p == ')') { tag = RIGHTBRACKET; }
				break;
			case LEFTBRACKET:
				if (isdigit(*p)) { tag = NUMBER; }
				else if (*p == '(')
				{
					Push(&mys, p);
				}
				else if (isspace(*p)) {}
				else if (IsOperator(*p)) { goto END; }
				break;
			case RIGHTBRACKET:
				if (isdigit(*p)) { tag = NUMBER; }
				else if (*p == '(')
				{
					Push(&mys, p);
				}
				else if (isspace(*p)) {}
				else if (IsOperator(*p)) { goto END; }
				break;
		}
	}
	if (!StackEmpty(&mys))
	{
		res = false;
	}
	else
	{
		res = true;
	}
	if (tag == NUMBER || tag == NUMBER_OUT)
	{
		res = true;
	}
END:
	return res;
}

bool IsOperator(const char ch)
{
	bool res = false;
	switch (ch)
	{
	case '+': case '-': case '*': case '/': case '%': case '(': case ')':
		res = true;
		break;
	default:
		break;
	}
	return res;
}

int InStackOp(const char cp)
{
	int py = 0;
	switch (cp)
	{
	case '+': case '-': py = 3; break;
	case '*': case '/': case '%': py = 5; break;
	case '(': py = 1; break;
	case ')': py = 6; break;
	}
	return py;
}
int OutStackOp(const char cp)
{
	int py = 0;
	switch (cp)
	{
	case '+': case '-': py = 2; break;
	case '*': case '/': case '%': py = 4; break;
	case '(': py = 6; break;
	case ')': py = 1; break;
	}
	return py;
}
//int Operator(const int leftval, const int rightval, const char op)
double Operator(const double leftval, const double rightval, const char op)
{
	double ret = 0;
	switch (op)
	{
	case '+': ret = leftval + rightval; break;
	case '-': ret = leftval - rightval; break;
	case '*': ret = leftval * rightval; break;
	case '/':
		if (0 == rightval)
		{
			printf(" div 0 \n");
			exit(1);
		}
		ret = leftval / rightval;
		break;
	case '%': ret = (int)leftval % (int)rightval; break;
	default:
		printf("无法计算....");
		exit(1);
		break;
	}
	return ret;
}

void PostFix(const char* midstr, char* laststr)
{		 
	// midstr =" 12345  +   23     * 80 ";
    // laststr = "1222 23 80 + * ";
	if (NULL == midstr || '\0' == *midstr) return;
	GenListStack mys;
	InitGenListStack(&mys, sizeof(char));
	char cval = '\0';
	Push(&mys, &cval);
	char* s = laststr;
	for (const char* p = midstr; *p != '\0'; ++p)
	{
		if (isspace(*p)) {}
		else if (!IsOperator(*p))
		{

			while (isdigit(*p) || *p == '.')
			{
				*s++ = *p++;
			}
			*s++ = ' ';
			--p; // 修复指针位置
		}
		else if (IsOperator(*p))
		{
			if (OutStackOp(*p) > InStackOp((GetTop(&mys, &cval), cval)))
			{
				Push(&mys, p);
			}
			else if (OutStackOp(*p) < InStackOp((GetTop(&mys, &cval), cval)))
			{
				Pop(&mys, &cval);
				//printf("%c ", cval);
				*s++ = cval;
				*s++ = ' ';
				--p;
			}
			else  if (*p == ')' && ((GetTop(&mys, &cval), cval) == '('))
			{
				Pop(&mys, &cval);
			}
		}
	}
	while (!StackEmpty(&mys) && (GetTop(&mys, &cval), cval) != '\0')
	{
		Pop(&mys, &cval);
		//printf("%c ", cval);
		*s++ = cval;
		*s++ = ' ';
	}
	*s = '\0';/// 
	DestroyGenListStack(&mys);
}

double LastExprValue(const char* laststr)
{
	// laststr ="12456354 23 80 * + "
	double sum = 0, leftval = 0, rightval = 0;
	if (NULL == laststr || '\0' == *laststr) return sum;
	GenListStack mys;
	//InitGenListStack(&mys, sizeof(int));
	InitGenListStack(&mys, sizeof(double));
	for (const char* p = laststr; *p != '\0'; ++p)
	{
		if (!IsOperator(*p) && *p != ' ')
		{
			//int val = atoi(p);
			double val = atof(p);
			Push(&mys, &val);
			p = strchr(p, ' ');
		}
		else if (IsOperator(*p))
		{
			Pop(&mys, &rightval);
			Pop(&mys, &leftval);
			sum = Operator(leftval, rightval, *p);
			Push(&mys, &sum);
		}
	}
	Pop(&mys, &sum);
	DestroyGenListStack(&mys);
	return sum;
}
//int main()
//{
//	const int n = 128;
//	char str[n] = { 0 };
//	do
//	{
//		fgets(str, n, stdin);
//		if (strcmp(str, "end") == 0) break;
//		printf("str: %s \n", str);
//		if (CheckMidStr(str))
//		{
//			//run(str);
//			printf("run \n");
//		}
//		else
//		{
//			printf("mid string error \n");
//		}
//	} while (1);
//	return 0;
//}