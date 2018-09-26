#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include<string.h>
#include <windows.h>

#define MAX_SIZE 10

typedef int DataType;
//typedef char DataType;


typedef struct Stack
{
	DataType _array[MAX_SIZE];
	int _size;
}Stack;

void StackInit(Stack* s)
{
	assert(s);
	s->_size = 0;
}

void StackPush(Stack* s, DataType data)
{
	assert(s);
	if (s->_size == MAX_SIZE)
		return;
	s->_array[s->_size++] = data;
}

void StackPop(Stack* s)
{
	assert(s);
	if (StackEmpty(s))
	{
		return;
	}
	s->_size--;
}

DataType StackTop(Stack* s)
{
	assert(s);
	return s->_array[s->_size - 1];
}

int StackSize(Stack* s)
{
	assert(s);
	return s->_size;
}

int StackEmpty(Stack* s)
{
	assert(s);
	return 0 == s->_size;
}

int IsBracket(char ch)
{
	if ('(' == ch || ')' == ch ||
		'[' == ch || ']' == ch ||
		'{' == ch || '}' == ch)
	{
		return 1;
	}
	return 0;
}

//int MatchBrackets(const char* pStr)
//{
//	int i = 0;
//	int size = strlen(pStr);
//	Stack s;
//	StackInit(&s);
//	for (; i < size; ++i)
//	{
//		if (!IsBracket(pStr[i]))
//		{
//			continue;
//		}
//		else
//		{
//			if ('(' == pStr[i] || '[' == pStr[i] || '{' == pStr[i])
//			{
//				StackPush(&s, pStr[i]);
//			}
//			else
//			{
//				char ch;
//				if (StackEmpty(&s))
//				{
//					printf("右比左多\n");
//					return 0;
//				}
//
//				ch = StackTop(&s);
//				if (ch == '(' && pStr[i] == ')' ||
//					ch == '[' && pStr[i] == ']' ||
//					ch == '{' && pStr[i] == '}')
//				{
//					StackPop(&s);
//				}
//				else
//				{
//					printf("次序出错\n");
//					return 0;
//				}
//			}
//		}
//	}
//	if (!StackEmpty(&s))
//	{
//		printf("左括号比右多\n");
//		return 0;
//	}
//	printf("左右匹配正确\n");
//	return 1;
//}
//void TestStack()
//{
//	Stack s;
//	StackInit(&s);
//	StackPush(&s, 1);
//	StackPush(&s, 2);
//	StackPush(&s, 3);
//	StackPush(&s, 4);
//	StackPush(&s, 5);
//	printf("%d \n", StackSize(&s));
//	printf("%d \n", StackTop(&s));
//	StackPop(&s);
//	StackPop(&s);
//	printf("%d \n", StackSize(&s));
//	printf("%d \n", StackTop(&s));
//}
//
//void TestMatchBrackets()
//{
//	const char* p1 = "(())abc{[(])}";
//	const char* p2 = "(()))abc{[]}";
//	const char* p3 = "((())abc{[]}";
//	const char* p4 = "(())abc{[]()}";
//	MatchBrackets(p1);
//	MatchBrackets(p2);
//	MatchBrackets(p3);
//	MatchBrackets(p4);
//}

////////////////////////////////
//
////////////////////////////////

typedef enum { ADD, SUB, MUL, DIV, DATA }OPERATOR;

typedef struct Cell
{
	OPERATOR _op;
	int _data;
}Cell; 

int CalcRPN(Cell* RPN, int size)
{
	int i = 0;
	Stack s;
	StackInit(&s);
	for (; i < size; ++i)
	{
		if (RPN[i]._op == DATA)
		{
			StackPush(&s,RPN[i]._data);
		}
		else
		{
			int left = 0;
			int right = 0;
			right = StackTop(&s);
			StackPop(&s);
			left = StackTop(&s);
			StackPop(&s);
			switch (RPN[i]._op)
			{
			case ADD:
				StackPush(&s, left + right);
				break;
			case SUB:
				StackPush(&s, left - right);
				break;
			case MUL:
				StackPush(&s, left* right);
				break;
			case DIV:
				if (0 == right)
				{
					printf("除法的右操作数为0\n");
					return 0;
				}
				StackPush(&s, left / right);
				break;
			default:
				printf("无法进行的操作");
				return 0;
			}
		}
	}
	return StackTop(&s);
}

void TestRPN()
{
	Cell RPN[] = { { DATA, 12 }, { DATA, 3 }, { DATA, 4 }, { ADD, 0 }, { MUL, 0 },
	{ DATA, 6 }, { SUB, 0 }, { DATA, 8 }, { DATA, 2 }, { DIV, 0 }, { ADD, 0 } };

	printf("%d\n", CalcRPN(RPN, sizeof(RPN) / sizeof(RPN[0])));
}
int main()
{
	TestRPN();
	/*TestStack();
	TestMatchBrackets();*/
	system("pause");
 	return 0;
}
