#pragma once
#include"common.h"

////////////////////////////////////////////
//顺序栈

#define SEQ_STACK_DEFAULT_SIZE 8
#define SEQ_STACK_INC_SIZE 3

typedef struct SeqStack
{
	ElemType* base;
	size_t capacity;
	int top;
}SeqStack;

///////////////////////////////////////////
//函数的接口地址
void SeqStackInit(SeqStack* pst);

//////////////////////////////////////////
//函数的实现
void SeqStackInit(SeqStack* pst)
{
	pst->base = (ElemType*)malloc(sizeof(ElemType) * SEQ_STACK_DEFAULT_SIZE);
	assert(pst->base != NULL);
	pst->capacity = SEQ_STACK_DEFAULT_SIZE;
	pst->top = 0;
}