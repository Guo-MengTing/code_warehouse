#include "Stack.h"

void StackInit(Stack* ps, int n)
{
	assert(ps);
	ps->_a = (STDataType*)malloc(sizeof(STDataType)*n);
	ps->_top = 0;
	ps->_capacity = n;
}

void StackPush(Stack* ps, STDataType x)//在栈顶增加元素
{
	assert(ps);
	if (ps->_top ==ps->_capacity)
	{
		ps->_a = (STDataType*)realloc(ps->_a, ps->_capacity * 2 * sizeof(STDataType));
		ps->_capacity *= 2;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}

int StackPop(Stack* ps)//出栈
{
	assert(ps);
	if (ps->_top > 0)
	{
		ps->_top--;
	}
	
}

STDataType StackTop(Stack* ps)//返回栈顶元素
{
	assert(ps);
	return ps->_a[ps->_top - 1];
}
int StackSize(Stack* ps)//返回栈中元素个数
{
	assert(ps);
	return ps->_top;
}
int StackEmpty(Stack* ps)//栈为空则返回真
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;
}
void traverseStack(Stack* ps)
{
	struct ListNode* a = ps->_top;

}
void Stacktest()
{
	Stack st;
	StackInit(&st, 4);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	printf("top:%d\n", StackTop(&st));
	printf("Size:%d\n", StackSize(&st));
	printf("Stack:%d\n", StackPop(&st));
}

int main()
{
	Stacktest();
	return 0;
}