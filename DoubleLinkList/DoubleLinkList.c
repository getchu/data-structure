#include "DoubleLinkList.h"

// ��ʼ��
DLinkListNode* DoubleLinkList_init(ElementType data)
{
	DLinkListNode *newNodePointer;

	newNodePointer = (DLinkListNode *)malloc(sizeof(DLinkListNode));
	newNodePointer->data = data;
	newNodePointer->pre = NULL;
	newNodePointer->next = NULL;

	return newNodePointer;
}
// ��
DLinkListNode* DoubleLinkList_insertBehind(DLinkListNode* preNodePointer, ElementType data)
{
	DLinkListNode *newNodePointer = NULL;

	if( NULL == preNodePointer ) // �ձ�
		return DoubleLinkList_init(data);
	
	newNodePointer = DoubleLinkList_init(data);
	if( NULL == preNodePointer->next ) // �޺�̽��,��β���
	{
		preNodePointer->next = newNodePointer;
		newNodePointer->pre = preNodePointer;
	}
	else if( NULL == preNodePointer->pre ) // ��ǰ�̽��,��ͷ���
	{
		preNodePointer->next = newNodePointer;
		newNodePointer->pre = preNodePointer;
	}else // �м���
	{ 
		newNodePointer->next = preNodePointer->next;
		newNodePointer->pre = preNodePointer;

		preNodePointer->next = newNodePointer;
		newNodePointer->next->pre = newNodePointer;
	}

	return newNodePointer;
}

DLinkListNode* DoubleLinkList_insertBefore(DLinkListNode* backNodePointer, ElementType data)
{
	DLinkListNode *newNodePointer = NULL;

	if( NULL == backNodePointer ) // �ձ�
		return DoubleLinkList_init(data);
	
	newNodePointer = DoubleLinkList_init(data);
	if( NULL == backNodePointer->next ) // �޺�̽��,��β���
	{
		newNodePointer->next = backNodePointer;
		backNodePointer->pre = newNodePointer;
	}
	else if( NULL == backNodePointer->pre ) // ��ǰ�̽��,��ͷ���
	{
		newNodePointer->next = backNodePointer;
		backNodePointer->pre = newNodePointer;
	}else // �м���
	{ 
		newNodePointer->next = backNodePointer;
		newNodePointer->pre = backNodePointer->pre;

		backNodePointer->pre = newNodePointer;
		newNodePointer->pre->next = newNodePointer;
	}

	return newNodePointer;
}
// ɾ,��������ͷָ��
DLinkListNode* DoubleLinkList_deleteByData(DLinkListNode* list,ElementType data)
{
	DLinkListNode *listHeadPointer = NULL;

	if( NULL == list ) //�ձ�
		return NULL;

	if( data == list->data ) // ������ͷ���,���벢ɾ��
	{
		if( NULL != list->next) // ͷ����Ƿ��к��
		{
			listHeadPointer = list->next;
			listHeadPointer->pre = NULL;
		}
		free(list);
		return listHeadPointer;
	}

	listHeadPointer = list; // ������ʼ����
	do
	{ // ������
		list = list->next;
	}while( data != list->data && NULL != list->next );

	if( data == list->data ) // �ҵ����ݽ��,�ж�ָ������,���벢ɾ��
		if( NULL == list->next ) // �޺�̵Ľ��,��β���
		{
			list->pre->next = NULL; //����"����"����
			free(list);
		}else
		{ // �к�̵Ľ��,�ҷ�ͷ���,��Ϊ�м���
			list->pre->next = list->next;
			list->next->pre = list->pre;
			free(list);
		}

	return listHeadPointer;
}

DLinkListNode* DoubleLinkList_deleteByAddr(DLinkListNode* list,DLinkListNode* pointer)
{
	DLinkListNode *listHead = NULL;

	if( NULL == list || NULL == pointer )
		return list;

	if( list == pointer )//Ŀ����ͷ���
	{
		if( NULL != list->next) //�к��(�����ǵ���������)
		{
			listHead = list->next;
			listHead->pre = NULL;
		}
		free(list);// free(pointer);
		return listHead;
	}

	listHead = list;
	do{ //���±���
		list = list->next;
	}while( pointer != list && NULL != list->next );
	
	if( pointer == list)
	{
		if( NULL == list->next )//��β���
		{
			list->pre->next = NULL;
			// free(list);�Ż�
		}else
		{//���м���
			list->pre->next = list->next;
			list->next->pre = list->pre;
			//free(list);�Ż�
		}
		free(list);// �Ż�,����һ
	}
	return listHead;
}

// ��
DLinkListNode* DoubleLinkList_select(DLinkListNode* list,ElementType data)
{
	while(data != list->data && NULL != list->next)
	{
		list = list->next;
	}
	if( data == list->data )
		return list;
	return NULL;
}

// ��
int DoubleLinkList_updateByData(DLinkListNode* list,ElementType oldData,ElementType newData)
{
	 DLinkListNode *thisNode = NULL;
	 if( NULL == (thisNode = DoubleLinkList_select(list,oldData)) )
	 {
		return 0;//failure
	 }else
	 {
		 thisNode->data = newData;
		 return 1;//success
	 }
}

// һ�����߷���
// ������β���
DLinkListNode* DoubleLinkList_selectRearByAddr(DLinkListNode *list)
{
	while( NULL != list->next)
	{
		list = list->next;
	}

	return list;
}