#pragma once
#include"common.h"

typedef struct SListNode
{
	ElemType data;
	struct SListNode* next;
}SListNode;

typedef struct SList
{
	SListNode* head;
}SList;

///////////////////////////////////////////
///////////////////////////////////////////
//单链表的函数接口声明
void SListInit(SList* plist);
static SListNode* _Buynode(ElemType x);
void SListPushBack(SList* plist, ElemType item);//1
void SListPushFront(SList* plist, ElemType item);//2
void SListShow(SList* plist);//3
void SListPopBack(SList* plist);//4
void SListPopFront(SList* plist);//5
void SListInsertVal(SList* plist, ElemType val);//7
void SListSort(SList* plist);//13

///////////////////////////////////////////
///////////////////////////////////////////
//单链表的函数接口实现
void SListInit(SList* plist)
{
	plist->head = NULL;
}
static SListNode* _Buynode(ElemType x)
{
	SListNode* s = (SListNode*)malloc(sizeof(SListNode));
	assert(s != NULL);
	s->data = x;
	s->next = NULL;
	return s;
}
//1
void SListPushBack(SList* plist, ElemType item)
{
	assert(plist != NULL);
	SListNode* s = _Buynode(item);
	//插入的节点为第一个节点
	if (plist->head == NULL)
	{
		plist->head = s;
		return;
	}
	//O(n)
	SListNode* p = plist->head;
	//查找链表的尾部节点
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = s;
}
//2
void SListPushFront(SList* plist, ElemType item)
{
	assert(plist != NULL);
	SListNode* s = _Buynode(item);
	s->next = plist->head;
	plist->head = s;
}
//3
void SListShow(SList* plist)
{
	assert(plist != NULL);
	SListNode* p = plist->head;
	while (p != NULL)
	{
		printf("%d-->", p->data);
		p = p->next;
	}
	printf("Over.\n");
}
//4
void SListPopBack(SList* plist)
{
	assert(plist != NULL);
	SListNode* p = plist->head;
	if (plist->head == NULL)
	{
		printf("单链表为空，输出失败!\n");
		return;
	}
	if (p->next == NULL)
	{
		plist->head = NULL;
		return;
	}
	SListNode* prev = NULL;
	while (p->next != NULL)
	{
		prev = p;
		p = p->next;
	}
	prev->next = NULL;
	free(p);
}
//5
void SListPopFront(SList* plist)
{
	assert(plist != NULL);
	SListNode* p = plist->head;
	if (plist->head == NULL)
	{
		printf("单链表为空，输出失败!\n");
		return;
	}
	plist->head = p->next;
	free(p);
}
//6
//7
//13
void SListSort(SList* plist)
{
	assert(plist != NULL);
}   
         