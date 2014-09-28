#include "DoubleLinkList.h"

// 初始化
DLinkListNode* DoubleLinkList_init(ElementType data)
{
	DLinkListNode *newNodePointer;

	newNodePointer = (DLinkListNode *)malloc(sizeof(DLinkListNode));
	newNodePointer->data = data;
	newNodePointer->pre = NULL;
	newNodePointer->next = NULL;

	return newNodePointer;
}
// 增
DLinkListNode* DoubleLinkList_insertBehind(DLinkListNode* preNodePointer, ElementType data)
{
	DLinkListNode *newNodePointer = NULL;

	if( NULL == preNodePointer ) // 空表
		return DoubleLinkList_init(data);
	
	newNodePointer = DoubleLinkList_init(data);
	if( NULL == preNodePointer->next ) // 无后继结点,即尾结点
	{
		preNodePointer->next = newNodePointer;
		newNodePointer->pre = preNodePointer;
	}
	else if( NULL == preNodePointer->pre ) // 无前继结点,即头结点
	{
		preNodePointer->next = newNodePointer;
		newNodePointer->pre = preNodePointer;
	}else // 中间结点
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

	if( NULL == backNodePointer ) // 空表
		return DoubleLinkList_init(data);
	
	newNodePointer = DoubleLinkList_init(data);
	if( NULL == backNodePointer->next ) // 无后继结点,即尾结点
	{
		newNodePointer->next = backNodePointer;
		backNodePointer->pre = newNodePointer;
	}
	else if( NULL == backNodePointer->pre ) // 无前继结点,即头结点
	{
		newNodePointer->next = backNodePointer;
		backNodePointer->pre = newNodePointer;
	}else // 中间结点
	{ 
		newNodePointer->next = backNodePointer;
		newNodePointer->pre = backNodePointer->pre;

		backNodePointer->pre = newNodePointer;
		newNodePointer->pre->next = newNodePointer;
	}

	return newNodePointer;
}
// 删,返回链表头指针
DLinkListNode* DoubleLinkList_deleteByData(DLinkListNode* list,ElementType data)
{
	DLinkListNode *listHeadPointer = NULL;

	if( NULL == list ) //空表
		return NULL;

	if( data == list->data ) // 数据在头结点,分离并删除
	{
		if( NULL != list->next) // 头结点是否有后继
		{
			listHeadPointer = list->next;
			listHeadPointer->pre = NULL;
		}
		free(list);
		return listHeadPointer;
	}

	listHeadPointer = list; // 保存起始浮标
	do
	{ // 向后遍历
		list = list->next;
	}while( data != list->data && NULL != list->next );

	if( data == list->data ) // 找到数据结点,判断指针特征,分离并删除
		if( NULL == list->next ) // 无后继的结点,即尾结点
		{
			list->pre->next = NULL; //构件"分离"处理
			free(list);
		}else
		{ // 有后继的结点,且非头结点,则为中间结点
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

	if( list == pointer )//目标在头结点
	{
		if( NULL != list->next) //有后继(否则是单结点的链表)
		{
			listHead = list->next;
			listHead->pre = NULL;
		}
		free(list);// free(pointer);
		return listHead;
	}

	listHead = list;
	do{ //往下遍历
		list = list->next;
	}while( pointer != list && NULL != list->next );
	
	if( pointer == list)
	{
		if( NULL == list->next )//在尾结点
		{
			list->pre->next = NULL;
			// free(list);优化
		}else
		{//在中间结点
			list->pre->next = list->next;
			list->next->pre = list->pre;
			//free(list);优化
		}
		free(list);// 优化,二合一
	}
	return listHead;
}

// 查
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

// 改
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

// 一个工具方法
// 遍历找尾结点
DLinkListNode* DoubleLinkList_selectRearByAddr(DLinkListNode *list)
{
	while( NULL != list->next)
	{
		list = list->next;
	}

	return list;
}