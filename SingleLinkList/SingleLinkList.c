#include "SingleLinkList.h"

// 初始化
LinkListNode* SingleLinkList_init(ElementType data)
{
	LinkListNode* pointer = NULL;

	pointer = (LinkListNode *)malloc(sizeof(LinkListNode));
	pointer->data = data;
	pointer->next = NULL;

	return pointer;
}

// 增
LinkListNode* SingleLinkList_insert(LinkListNode* frontNodePointer, ElementType data)
{
	LinkListNode* newNodePointer = NULL;

	if( NULL == frontNodePointer ) // 空表
		return SingleLinkList_init(data);

	newNodePointer = SingleLinkList_init(data);
	if( NULL != frontNodePointer->next) // 有后继
		newNodePointer->next = frontNodePointer->next;
	frontNodePointer->next = newNodePointer;

	return newNodePointer;
}

// 删,返回链表头指针
LinkListNode* SingleLinkList_deleteByData(LinkListNode* list,ElementType data)
{// 假定初始浮标list 指向 链表头结点

	LinkListNode* listHeadPointer = NULL;
	LinkListNode* PreNodePointer = NULL;
	
	if( NULL == list) //空表
		return NULL;

	if( data == list->data ) // 数据在头结点,不管头结点是否有后继
	{
		listHeadPointer = list->next;
		free(list);
		return listHeadPointer;
	}

	/*
	 * if( NULL == pointer->next) // 头结点也是尾结点且找不到数据,则删除失败
	 * {
	 * }
	 */

	listHeadPointer = list; // 保存头结点
	do // 往下一个结点遍历,直到 找到数据,或遍历完后仍找不到结果
	{
		PreNodePointer = list;//临时保存浮标的前驱节点
		list = list->next;
	}while( data != list->data && NULL != list->next );

	if( data == list->data ) // 如果找到数据
	{
		if( NULL == list->next )// 数据在尾节点
		{
			PreNodePointer->next = NULL;
			//free(list);优化
		}else{ // 有后继,且非头结点,则数据在中间结点
			PreNodePointer->next = list->next;
			//free(list);优化
		}
		free(list);// 优化,二合一
	}
	return listHeadPointer;
}

LinkListNode* SingleLinkList_deleteByAddr(LinkListNode* list,LinkListNode* pointer)
{// 假定初始浮标pointer 指向 链表头结点

	LinkListNode* listHeadPointer = NULL;
	LinkListNode* PreNodePointer = NULL;
	
	if( NULL == list || pointer == NULL ) // 空表或Needle为空
		return list;

	if( list == pointer ) // 删除头结点,返回新链头
	{
		listHeadPointer = list->next;
		free(list);
		return listHeadPointer; // 不排除listHeadPointer == NULL;
	}

	listHeadPointer = list; // 保存头结点
	do // 往下一个结点遍历,直到 找到结点,或遍历完后仍找不到结果
	{
		PreNodePointer = list;//临时保存浮标的前驱节点
		list = list->next;
	}while( pointer != list->next && NULL != list->next );

	if( pointer == list ) // 如果找到结点
	{
		if( NULL == list->next )// 结点是尾结点
		{
			PreNodePointer->next = NULL;
			//free(list);优化
		}else{ // 在中间结点
			PreNodePointer->next = list->next;
			//free(list);优化
		}
		free(list);// 优化,二合一
	}

	return listHeadPointer;
}

// 查
LinkListNode* SingleLinkList_select(LinkListNode* list,ElementType data)
{
	while( data != list->data && NULL != list->next )
		list = list->next;

	if( data == list->data )
		return list;
	return NULL;
}

// 改
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

// 三个工具方法

// 遍历找前驱结点
LinkListNode* SingleLinkList_selectPreByData(LinkListNode* list,ElementType data)
{// 此API调用时应判断NULL
	LinkListNode* PreNodePointer = NULL;
	
	/* if( data ==list->data ) // 头结点
	 * {
	 *    PreNodePointer = NULL;
	 * }
	 */

	do // 往下一个结点遍历,直到 找到数据,或遍历完后仍找不到结果
	{
		PreNodePointer = list;//临时保存浮标的前驱节点
		list = list->next;
	}while( data != list->data && NULL != list->next );

	return PreNodePointer;
}

LinkListNode* SingleLinkList_selectPreByAddr(LinkListNode* list,LinkListNode* pointer)
{
	LinkListNode* PreNodePointer = NULL;
	
	/* if( pointer == list ) // 头结点
	 * {
	 *    PreNodePointer = NULL;
	 * }
	 */

	do // 往下一个结点遍历,直到 找到数据,或遍历完后仍找不到结果
	{
		PreNodePointer = list;//临时保存浮标的前驱节点
		list = list->next;
	}while( pointer != list->next && NULL != list->next );

	return PreNodePointer;
}
// 遍历找尾结点
LinkListNode* SingleLinkList_selectRearByAddr(LinkListNode* list)
{
	while( NULL != list->next)
	{
		list = list->next;
	}

	return list;
}