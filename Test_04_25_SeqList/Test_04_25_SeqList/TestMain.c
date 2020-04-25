#include"seqlist.h"

int main()
{
	SeqList mylist;
	SeqListInit(&mylist);
	ElemType item;
	int select = 1;
	while (select)
	{
		printf("***********SeqList*************\n");
		printf("*[1] push_back   [2] push_front*\n");
		printf("*[3] show_list   [4] pop_back  *\n");
		printf("*[5] pop_front   [6] insert_pos*\n");
		printf("*[7] insert_val  [8] delete_pos*\n");
		printf("*[9] delete_val  [10] find_val *\n");
		printf("*[11] length     [12] capacity *\n");
		printf("*[13] sort       [14] reverse  *\n");
		printf("*[15] clear      [0]quit_system*\n");
		printf("********************************\n");
		printf("请选择:>");
		scanf("%d", &select);
		if (select == 0)
			break;
		switch (select)
		{
		case 1:
			printf("请输入要插入的值[以-1结束]:>");
			while (scanf("%d", &item), item != -1)
			{
				SeqListPushBack(&mylist,item);
			}
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			break;
		case 14:
			break;
		case 15:
			break;
		default:
			break;
		}
	}

	return 0;
}