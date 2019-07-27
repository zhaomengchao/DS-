#pragma once
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


typedef int STDataType;
typedef struct Stack
{
	STDataType* array;
	size_t top;
	size_t capacity;
}Stack;


void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
bool StackEmpty(Stack* ps);
size_t StackSize(Stack* ps);



void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->array != NULL)
	{
		free(ps->array);
		ps->array = NULL;
		ps->capacity = ps->top = 0;
	}
}
void StackPush(Stack* ps, STDataType x)//β��
{
	assert(ps);
	if (ps->top == ps->capacity)//����
	{
		size_t newscapacity = ps->capacity == 0 ? 2 : ps->capacity * 2;
		ps->array = (STDataType*)realloc(ps->array, newscapacity* sizeof(STDataType));//����
		ps->capacity = newscapacity;
	}
	ps->array[ps->top] = x;
	ps->top++;
}
void StackPop(Stack* ps)//ɾ����һ���ڵ㣬βɾ
{
	assert(ps && ps->top > 0);

	ps->top--;
}
STDataType StackTop(Stack* ps)//����ջ����ֵ
{
	assert(ps && ps->top > 0);
	return ps->array[ps->top - 1];
}
bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}
size_t StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}


void teststack()
{
	Stack ps;
	StackInit(&ps);
	StackPush(&ps, 1);
	StackPush(&ps, 2);
	StackPush(&ps, 3);
	StackPush(&ps, 4);
	while (!StackEmpty(&ps))
	{
		printf("%d", StackTop(&ps));
		StackPop(&ps);
	}
	printf("\n");
	//StackDestory(&ps);
}