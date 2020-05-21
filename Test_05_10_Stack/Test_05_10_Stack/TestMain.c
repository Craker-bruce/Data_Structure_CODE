#include "stack.h"

void main()
{
	SeqStack st;
	SeqStackInit(&st);
	SeqStackPush(&st, 1);
	SeqStackPush(&st, 2);

	SeqStackPrint(&st);
}