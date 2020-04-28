//#pragma once
#ifndef _SEQLIST_H_
#define _SEQLIST_H_


#include"common.h"
#define SEQLIST_DEFAULT_SIZE 8

//定义顺序表结构
typedef struct SeqList
{
	ElemType* base;
	size_t capacity;
	size_t size;
}SeqList;

//////////////////////////////////
//声明函数接口
void SeqListInit(SeqList* pst);
bool IsFull(SeqList* pst);
bool IsEmpty(SeqList* pst);
void SeqListPushBack(SeqList* pst, ElemType x);
void SeqListPushFront(SeqList* pst, ElemType x);
void SeqListShow(SeqList* pst);
void SeqListDestroy(SeqList* pst);
void SeqListPopBack(SeqList* pst);
void SeqListPopFront(SeqList* pst);
void SeqListInsertPos(SeqList* pst, size_t pos, ElemType x);
void SeqListInsertVal(SeqList* pst,  ElemType val);

//////////////////////////////////
//函数接口实现
void SeqListInit(SeqList* pst)
{
	assert(pst != NULL);
	pst->base = (ElemType*)malloc(sizeof(ElemType) * SEQLIST_DEFAULT_SIZE);
	assert(pst->base != NULL);
	memset(pst->base, 0, sizeof(ElemType) * SEQLIST_DEFAULT_SIZE);
	pst->capacity = SEQLIST_DEFAULT_SIZE;
	pst->size = 0;
}

bool IsFull(SeqList* pst)
{
	assert(pst != NULL);
	return pst->size >= pst->capacity;
}
bool IsEmpty(SeqList* pst)
{
	assert(pst != NULL);
	return pst->size == 0;
}

void SeqListPushBack(SeqList* pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("顺序表空间已满，不能插入数据%d\n", x);
		return;
	}
	pst->base[pst->size++] = x;
}

void SeqListPushFront(SeqList* pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("顺序表空间已满，不能插入数据%d\n", x);
		return;
	}
	for (size_t pos = pst->size; pos > 0; --pos)
	{
		pst->base[pos] = pst->base[pos - 1];
	}
	pst->base[0] = x;
	pst->size++;
}

void SeqListShow(SeqList* pst)
{
	assert(pst != NULL);
	for (size_t i = 0; i < pst->size; ++i)
	{
		printf("%d ", pst->base[i]);
	}
	printf("\n");
}

void SeqListDestroy(SeqList* pst)
{
	assert(pst != NULL);
	if (pst->base)
		free(pst->base);
	pst->base = NULL;
	pst->capacity = pst->size = 0;
}

void SeqListPopBack(SeqList* pst)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表为空，不能尾部删除!\n");
		return;
	}
	pst->size--;
}

void SeqListPopFront(SeqList* pst)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("顺序表为空，不能尾部删除!\n");
		return;
	}
	for (size_t i = 0; i < pst->size; ++i)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}

void SeqListInsertPos(SeqList* pst, size_t pos, ElemType x)
{
	assert(pst != NULL);
	if (pos<0 || pos>pst->size)
	{
		printf("要插入数据的位置非法,无法插入!\n");
		return;
	}
	if (IsFull(pst))
	{
		printf("顺序表已满，不可插入数据源!\n");
	}
	for (size_t i = pst->size; i > pos; --i)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[pos] = x;
	pst->size++;
}

void SeqListInsertVal(SeqList* pst, ElemType val)
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("顺序表已满，不可插入数据!\n");
	}
	int end = pst->size;
	while (end > 0 && val < pst->base[end - 1])
	{
		pst->base[end] = pst->base[end - 1];
		end--;
	}
	pst->base[end] = val;
	pst->size++;
}


#endif // !_SEQLIST_H_