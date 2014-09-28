#define ElementType int
#include "DoubleLinkList.h"
#include <stdio.h>

int main()
{
	DLinkListNode *listHead,*second;

	listHead = DoubleLinkList_init(0);
	printf("%d",listHead->data);

	second = DoubleLinkList_insertBehind(listHead,8888);
	printf("%d",second->data);

	DoubleLinkList_insertBehind(listHead->next,404);
	DoubleLinkList_insertBehind(listHead->next->next,-151);

	DoubleLinkList_updateByData(listHead,404,202);
	printf("++%d++",listHead->next->next->data);
	
	listHead = DoubleLinkList_deleteByData(listHead,202);
	printf("**%d**",listHead->next->next->data);
	printf("(%d)",listHead->next->next->data);

	printf("%d",listHead->data);
	getchar();
	getchar();
	return 0;
}