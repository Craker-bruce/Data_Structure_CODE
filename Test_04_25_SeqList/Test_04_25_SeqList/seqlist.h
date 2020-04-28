//#pragma once
#ifndef _SEQLIST_H_
#define _SEQLIST_H_


#include"common.h"
#define SEQLIST_DEFAULT_SIZE 8

//����˳���ṹ
typedef struct SeqList
{
	ElemType* base;
	size_t capacity;
	size_t size;
}SeqList;

//////////////////////////////////
//���������ӿ�
void SeqListInit(SeqList* pst);
bool IsFull(SeqList* pst);
bool IsEmpty(SeqList* pst);
void SeqListPushBack(SeqList* pst, ElemType x);//1
void SeqListPushFront(SeqList* pst, ElemType x);//2
void SeqListShow(SeqList* pst);//3
void SeqListDestroy(SeqList* pst);
void SeqListPopBack(SeqList* pst);//4
void SeqListPopFront(SeqList* pst);//5
void SeqListInsertPos(SeqList* pst, size_t pos, ElemType x);//6
void SeqListInsertVal(SeqList* pst,  ElemType val);//7

//////////////////////////////////
//�����ӿ�ʵ��
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
//1
void SeqListPushBack(SeqList* pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("˳���ռ����������ܲ�������%d\n", x);
		return;
	}
	pst->base[pst->size++] = x;
}
//2
void SeqListPushFront(SeqList* pst, ElemType x)
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("˳���ռ����������ܲ�������%d\n", x);
		return;
	}
	for (size_t pos = pst->size; pos > 0; --pos)
	{
		pst->base[pos] = pst->base[pos - 1];
	}
	pst->base[0] = x;
	pst->size++;
}
//3
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
//4
void SeqListPopBack(SeqList* pst)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("˳���Ϊ�գ�����β��ɾ��!\n");
		return;
	}
	pst->size--;
}
//5
void SeqListPopFront(SeqList* pst)
{
	assert(pst != NULL);
	if (IsEmpty(pst))
	{
		printf("˳���Ϊ�գ�����β��ɾ��!\n");
		return;
	}
	for (size_t i = 0; i < pst->size; ++i)
	{
		pst->base[i] = pst->base[i + 1];
	}
	pst->size--;
}
//6
void SeqListInsertPos(SeqList* pst, size_t pos, ElemType x)
{
	assert(pst != NULL);
	if (pos<0 || pos>pst->size)
	{
		printf("Ҫ�������ݵ�λ�÷Ƿ�,�޷�����!\n");
		return;
	}
	if (IsFull(pst))
	{
		printf("˳������������ɲ�������Դ!\n");
	}
	for (size_t i = pst->size; i > pos; --i)
	{
		pst->base[i] = pst->base[i - 1];
	}
	pst->base[pos] = x;
	pst->size++;
}
//7
void SeqListInsertVal(SeqList* pst, ElemType val)
{
	assert(pst != NULL);
	if (IsFull(pst))
	{
		printf("˳������������ɲ�������!\n");
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