#ifndef DoubleLinkList
#define DoubleLinkList

#ifndef malloc_h
#include <malloc.h>
#endif // !malloc_h

#ifndef NULL
#define NULL (0)
#endif // !NULL

#ifndef ElementType
#define ElementType int
#endif

typedef struct DoubleLinkListStruct
{
	struct DoubleLinkListStruct *pre,*next;
	ElementType data;
} DLinkListNode;

// 工厂方法,初始化,构造一个数据结点
DLinkListNode* DoubleLinkList_init(ElementType data);
// 增,返回新结点地址
DLinkListNode* DoubleLinkList_insertBehind(DLinkListNode* preNodePointer, ElementType data);//后
DLinkListNode* DoubleLinkList_insertBefore(DLinkListNode* backNodePointer, ElementType data);//前
// 删,返回链表头指针
DLinkListNode* DoubleLinkList_deleteByData(DLinkListNode* list,ElementType data);
DLinkListNode* DoubleLinkList_deleteByAddr(DLinkListNode* list,DLinkListNode* pointer);
// 查,返回数据结点地址
DLinkListNode* DoubleLinkList_select(DLinkListNode* list,ElementType data);
// 改,{1:"success",0:"failure"}
int DoubleLinkList_updateByData(DLinkListNode* list,ElementType oldData,ElementType newData);

// 一个工具方法
// 遍历找尾结点
DLinkListNode* DoubleLinkList_selectRearByAddr(DLinkListNode *list);

#endif // !DoubleLinkList