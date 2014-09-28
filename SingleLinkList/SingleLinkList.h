#ifndef SingleLinkList
#define SingleLinkList

#ifndef malloc_h
#include <malloc.h>
#endif // !malloc_h

#ifndef NULL
#define NULL (0)
#endif // !NULL

#ifndef ElementType
#define ElementType int
#endif

typedef struct SingleLinkListStruct
{
	ElementType data;
	struct SingleLinkListStruct* next;
} LinkListNode;

// 工厂方法:构造一个数据结点
LinkListNode* SingleLinkList_init(ElementType data);
// 增,返回新结点地址
LinkListNode* SingleLinkList_insert(LinkListNode* frontNodePointer, ElementType data);
// 删,返回链表头指针
LinkListNode* SingleLinkList_deleteByData(LinkListNode* list,ElementType data);
LinkListNode* SingleLinkList_deleteByAddr(LinkListNode* list,LinkListNode* pointer);
// 查,返回该数据结点地址
LinkListNode* SingleLinkList_select(LinkListNode* list,ElementType data);
// 改{1:"success",0:"failure"}
int SingleLinkList_updateByData(LinkListNode* list,ElementType oldData,ElementType newData);

// 三个工具方法
// 遍历找前驱结点
LinkListNode* SingleLinkList_selectPreByData(LinkListNode* list,ElementType data);
LinkListNode* SingleLinkList_selectPreByAddr(LinkListNode* list,LinkListNode* pointer);
// 遍历找尾结点
LinkListNode* SingleLinkList_selectRearByAddr(LinkListNode*list);

#endif