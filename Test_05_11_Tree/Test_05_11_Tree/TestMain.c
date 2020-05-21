#include "Tree.h"


void main()
{
	//const char *str = "AB#DF###CE###";
	const char* str = "ABC##DE##F##G#H##";
	BinTree  bt;
	BinTreeInit(&bt);
	BinTreeCreate(&bt);
	//BinTreeCreateByStr(&bt, str);

	/*printf("VLR: ");
	PreOrder(&bt);
	printf("\n");

	printf("LVR: ");
	InOrder(&bt);
	printf("\n");

	printf("LRV: ");
	PostOrder(&bt);
	printf("\n");

	printf("Level: ");
	LevelOrder(&bt);
	printf("\n");

	printf("Size = %d\n", BinTreeCount(&bt));
	printf("Height = %d\n", BinTreeHeight(&bt));*/
}
