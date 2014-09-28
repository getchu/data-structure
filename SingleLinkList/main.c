#define ElementType int
#include "SingleLinkList.h"
#include <stdio.h>

int main()
{
	LinkListNode *listHead,*second;

	listHead = SingleLinkList_init(0);
	printf("%d",listHead->data);

	second = SingleLinkList_insert(listHead,65532);
	printf("%d",second->data);

	SingleLinkList_insert(listHead->next,404);
	SingleLinkList_insert(listHead->next->next,-151);

	SingleLinkList_updateByData(listHead,404,202);
	printf("%d",listHead->next->next->data);
	
	listHead = SingleLinkList_deleteByData(listHead,404);
	printf("%d",listHead->data);
	getchar();
	getchar();
	return 0;
}