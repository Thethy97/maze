
#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>


typedef struct Pos
{
	int _row;
	int _col;
}Pos;

typedef Pos DataType;

typedef struct Stack
{
	DataType* _a;
	int _top;		// Õ»¶¥
	int _capacity;  // ÈÝÁ¿ 
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);

void StackPush(Stack* ps, DataType x);
void StackPop(Stack* ps);
DataType StackTop(Stack* ps);
int StackEmpty(Stack* ps);
int StackSize(Stack* ps);

void TestStack();
