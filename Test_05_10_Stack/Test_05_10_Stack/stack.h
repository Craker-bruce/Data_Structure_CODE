#pragma once
#include"common.h"

////////////////////////////////////////////
//˳��ջ

#define SEQ_STACK_DEFAULT_SIZE 8
#define SEQ_STACK_INC_SIZE 3

typedef struct SeqStack
{
	ElemType* base;
	size_t capacity;
	int top;
}SeqStack;

///////////////////////////////////////////
//�����Ľӿڵ�ַ
void SeqStackInit(SeqStack* pst);

//////////////////////////////////////////
//������ʵ��
void SeqStackInit(SeqStack* pst)
{
	pst->base = (ElemType*)malloc(sizeof(ElemType) * SEQ_STACK_DEFAULT_SIZE);
	assert(pst->base != NULL);
	pst->capacity = SEQ_STACK_DEFAULT_SIZE;
	pst->top = 0;
}