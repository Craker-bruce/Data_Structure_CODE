#pragma once
#include "common.h"



#define LEVEL_ORDER
#ifdef LEVEL_OREDR

//链式队列
typedef struct LinkQueueNode
{
	BinTreeNode* data;
	struct LinkQueueNode* link;
}LinkQueueNode;

typedef struct LinkQueue
{
	LinkQueueNode* front;
	LinkQueueNode* rear;
}LinkQueue;

void LinkQueueInit(LinkQueue* pq);
void LinkQueueEnQue(LinkQueue* pq, BinTreeNode* x);
void LinkQueueDeQue(LinkQueue* pq);
void LinkQueuePrint(LinkQueue* pq);
bool LinkQueueEmpty(LinkQueue* pq);
BinTreeNode* LinkQueueFront(LinkQueue* pq);

void LinkQueueInit(LinkQueue* pq)
{
	assert(pq != NULL);
	pq->front = pq->rear = NULL;
}

void LinkQueueEnQue(LinkQueue* pq, BinTreeNode* x)
{
	assert(pq != NULL);
	LinkQueueNode* node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	assert(node != NULL);
	node->data = x;
	node->link = NULL;

	if (pq->front == NULL)
		pq->front = pq->rear = node;
	else
	{
		pq->rear->link = node;
		pq->rear = node;
	}
}
void LinkQueueDeQue(LinkQueue* pq)
{
	assert(pq != NULL);
	if (pq->front != NULL)
	{
		LinkQueueNode* p = pq->front;
		pq->front = p->link;
		free(p);
	}
}
void LinkQueuePrint(LinkQueue* pq)
{
	assert(pq != NULL);
	LinkQueueNode* p = pq->front;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	printf("\n");
}

bool LinkQueueEmpty(LinkQueue* pq)
{
	return pq->front == NULL;
}

BinTreeNode* LinkQueueFront(LinkQueue* pq)
{
	assert(pq->front != NULL);
	return pq->front->data;
}
#endif

typedef struct BinTreeNode
{
	ElemType data;
	struct BinTreeNode* leftChild;
	struct BinTreeNode* rightChild;
}BinTreeNode;

typedef struct BinTree
{
	BinTreeNode* root;
}BinTree;
//////////////////////////////////////////////////////////////////
//函数接口地址
//1 创建
void BinTreeInit(BinTree* pbt);
void BinTreeCreate(BinTree* bt);
void BinTreeCreate_1(BinTreeNode** t);
BinTreeNode* BinTreeCreate_2();
void BinTreeCreateByStr(BinTree* bt, const char* str);
BinTreeNode* BinTreeCreateByStr_1(const char* str, int* pindex);

///////////////////////////////////////////////////////////////////
//函数实现地址
//1 创建
void BinTreeInit(BinTree* pbt)
{
	pbt->root = NULL;
}

void BinTreeCreate(BinTree* bt)
{
	//1 BinTreeCreate_1(&bt->root);
	bt->root = BinTreeCreate_2();
}

void BinTreeCreate_1(BinTreeNode** t)
{
	ElemType item;
	scanf("%c", &item);
	if (item == '#')
		*t = NULL;
	else
	{
		*t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(*t != NULL);
		(*t)->data = item;
		BinTreeCreate_1(&(*t)->leftChild);
		BinTreeCreate_1(&(*t)->rightChild);
	}
}

BinTreeNode* BinTreeCreate_2()
{
	ElemType item;
	scanf("%c", &item);
	if (item == '#')
		return NULL;
	else
	{
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = item;
		t->leftChild = BinTreeCreate_2();
		t->rightChild = BinTreeCreate_2();
		return t;
	}
}

void BinTreeCreateByStr(BinTree* bt, const char* str)
{
	int index = 0;
	bt->root = BinTreeCreateByStr_1(str, &index);
}

BinTreeNode* BinTreeCreateByStr_1(const char* str, int* pindex)
{
	if (str[*pindex] == '#' || str[*pindex] == '\0')
		return NULL;
	else
	{
		BinTreeNode* t = (BinTreeNode*)malloc(sizeof(BinTreeNode));
		assert(t != NULL);
		t->data = str[*pindex];
		(*pindex)++;
		t->leftChild = BinTreeCreateByStr_1(str, pindex);
		(*pindex)++;
		t->rightChild = BinTreeCreateByStr_1(str, pindex);
		return t;
	}
}