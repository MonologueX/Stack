#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
#include <windows.h>

#define MAX_SIZE 10


typedef int DataType;

typedef struct Stack
{
	DataType _array[MAX_SIZE];
	int _size;
}Stack;

void StackInit(Stack* s);
int StackEmpty(Stack* s);
void StackPush(Stack* s, DataType data);
void StackPop(Stack* s);
DataType StackTop(Stack* s);
int StackSize(Stack* s);

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

void TestStack()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	printf("%d \n", StackSize(&s));
	printf("%d \n", StackTop(&s));
	StackPop(&s);
	StackPop(&s);
	printf("%d \n", StackSize(&s));
	printf("%d \n", StackTop(&s));
}

int main()
{
	TestStack();
	system("pause");
	return 0;
}