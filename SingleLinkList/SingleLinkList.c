#include "SingleLinkList.h"

// ��ʼ��
LinkListNode* SingleLinkList_init(ElementType data)
{
	LinkListNode* pointer = NULL;

	pointer = (LinkListNode *)malloc(sizeof(LinkListNode));
	pointer->data = data;
	pointer->next = NULL;

	return pointer;
}

// ��
LinkListNode* SingleLinkList_insert(LinkListNode* frontNodePointer, ElementType data)
{
	LinkListNode* newNodePointer = NULL;

	if( NULL == frontNodePointer ) // �ձ�
		return SingleLinkList_init(data);

	newNodePointer = SingleLinkList_init(data);
	if( NULL != frontNodePointer->next) // �к��
		newNodePointer->next = frontNodePointer->next;
	frontNodePointer->next = newNodePointer;

	return newNodePointer;
}

// ɾ,��������ͷָ��
LinkListNode* SingleLinkList_deleteByData(LinkListNode* list,ElementType data)
{// �ٶ���ʼ����list ָ�� ����ͷ���

	LinkListNode* listHeadPointer = NULL;
	LinkListNode* PreNodePointer = NULL;
	
	if( NULL == list) //�ձ�
		return NULL;

	if( data == list->data ) // ������ͷ���,����ͷ����Ƿ��к��
	{
		listHeadPointer = list->next;
		free(list);
		return listHeadPointer;
	}

	/*
	 * if( NULL == pointer->next) // ͷ���Ҳ��β������Ҳ�������,��ɾ��ʧ��
	 * {
	 * }
	 */

	listHeadPointer = list; // ����ͷ���
	do // ����һ��������,ֱ�� �ҵ�����,�����������Ҳ������
	{
		PreNodePointer = list;//��ʱ���渡���ǰ���ڵ�
		list = list->next;
	}while( data != list->data && NULL != list->next );

	if( data == list->data ) // ����ҵ�����
	{
		if( NULL == list->next )// ������β�ڵ�
		{
			PreNodePointer->next = NULL;
			//free(list);�Ż�
		}else{ // �к��,�ҷ�ͷ���,���������м���
			PreNodePointer->next = list->next;
			//free(list);�Ż�
		}
		free(list);// �Ż�,����һ
	}
	return listHeadPointer;
}

LinkListNode* SingleLinkList_deleteByAddr(LinkListNode* list,LinkListNode* pointer)
{// �ٶ���ʼ����pointer ָ�� ����ͷ���

	LinkListNode* listHeadPointer = NULL;
	LinkListNode* PreNodePointer = NULL;
	
	if( NULL == list || pointer == NULL ) // �ձ��NeedleΪ��
		return list;

	if( list == pointer ) // ɾ��ͷ���,��������ͷ
	{
		listHeadPointer = list->next;
		free(list);
		return listHeadPointer; // ���ų�listHeadPointer == NULL;
	}

	listHeadPointer = list; // ����ͷ���
	do // ����һ��������,ֱ�� �ҵ����,�����������Ҳ������
	{
		PreNodePointer = list;//��ʱ���渡���ǰ���ڵ�
		list = list->next;
	}while( pointer != list->next && NULL != list->next );

	if( pointer == list ) // ����ҵ����
	{
		if( NULL == list->next )// �����β���
		{
			PreNodePointer->next = NULL;
			//free(list);�Ż�
		}else{ // ���м���
			PreNodePointer->next = list->next;
			//free(list);�Ż�
		}
		free(list);// �Ż�,����һ
	}

	return listHeadPointer;
}

// ��
LinkListNode* SingleLinkList_select(LinkListNode* list,ElementType data)
{
	while( data != list->data && NULL != list->next )
		list = list->next;

	if( data == list->data )
		return list;
	return NULL;
}

// ��
int SingleLinkList_updateByData(LinkListNode* list,ElementType oldData,ElementType newData)
{
	LinkListNode* thisNode;

	if( NULL == (thisNode = SingleLinkList_select(list,oldData) ) )
	{
		return 0; // failure
	}else
	{
		thisNode->data = newData;
		return 1; // success
	}
}

// �������߷���

// ������ǰ�����
LinkListNode* SingleLinkList_selectPreByData(LinkListNode* list,ElementType data)
{// ��API����ʱӦ�ж�NULL
	LinkListNode* PreNodePointer = NULL;
	
	/* if( data ==list->data ) // ͷ���
	 * {
	 *    PreNodePointer = NULL;
	 * }
	 */

	do // ����һ��������,ֱ�� �ҵ�����,�����������Ҳ������
	{
		PreNodePointer = list;//��ʱ���渡���ǰ���ڵ�
		list = list->next;
	}while( data != list->data && NULL != list->next );

	return PreNodePointer;
}

LinkListNode* SingleLinkList_selectPreByAddr(LinkListNode* list,LinkListNode* pointer)
{
	LinkListNode* PreNodePointer = NULL;
	
	/* if( pointer == list ) // ͷ���
	 * {
	 *    PreNodePointer = NULL;
	 * }
	 */

	do // ����һ��������,ֱ�� �ҵ�����,�����������Ҳ������
	{
		PreNodePointer = list;//��ʱ���渡���ǰ���ڵ�
		list = list->next;
	}while( pointer != list->next && NULL != list->next );

	return PreNodePointer;
}
// ������β���
LinkListNode* SingleLinkList_selectRearByAddr(LinkListNode* list)
{
	while( NULL != list->next)
	{
		list = list->next;
	}

	return list;
}