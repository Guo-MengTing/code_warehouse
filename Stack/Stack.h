#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdio.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;

void StackInit(Stack* ps, int n);
void StackPush(Stack* ps, STDataType x);
int StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
int StackSize(Stack* ps);
int StackEmpty(Stack* ps);

void StackTest();