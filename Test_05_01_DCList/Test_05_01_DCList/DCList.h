#pragma once
#include"common.h"

/////////////////////////////////////////////////
//带头的双循环链表
typedef struct DCListNode
{
	ElemType data;
	struct  DCListNode* next;
	struct DCListNode* prev;
}DCListNode;

typedef struct DCList
{
	DCListNode* head;
}DCList;

static DCListNode* _Buydnode(ElemType x);
void DCListInit(DCList* plist);
void DCListPushBack(DCList* plist, ElemType x);//1
void DCListPushFront(DCList* plist, ElemType x);//2
void DCListShow(DCList* plist);//3

static DCListNode* _Buydnode(ElemType x)
{
	DCListNode* s = (DCListNode*)malloc(sizeof(DCListNode));
	assert(s != NULL);
	s->data = x;
	s->next = s->prev = s;
	return s;
}

void DCListInit(DCList* plist)
{
	plist->head = _Buydnode(0);
}

//1
void DCListPushBack(DCList* plist, ElemType x)
{
	assert(plist != NULL);
	DCListNode* s = _Buydnode(x);
	s->prev = plist->head->prev;
	s->prev->next = s;
	s->next = plist->head;
	plist->head->prev = s;
}

//2
void DCListPushFront(DCList* plist, ElemType x)
{
	assert(plist != NULL);
	DCListNode* s = _Buydnode(x);

}


//3
void DCListShow(DCList* plist)
{
	assert(plist != NULL);
	DCListNode* p = plist->head->next;
	while (p!=plist->head)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}