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

// ��������:����һ�����ݽ��
LinkListNode* SingleLinkList_init(ElementType data);
// ��,�����½���ַ
LinkListNode* SingleLinkList_insert(LinkListNode* frontNodePointer, ElementType data);
// ɾ,��������ͷָ��
LinkListNode* SingleLinkList_deleteByData(LinkListNode* list,ElementType data);
LinkListNode* SingleLinkList_deleteByAddr(LinkListNode* list,LinkListNode* pointer);
// ��,���ظ����ݽ���ַ
LinkListNode* SingleLinkList_select(LinkListNode* list,ElementType data);
// ��{1:"success",0:"failure"}
int SingleLinkList_updateByData(LinkListNode* list,ElementType oldData,ElementType newData);

// �������߷���
// ������ǰ�����
LinkListNode* SingleLinkList_selectPreByData(LinkListNode* list,ElementType data);
LinkListNode* SingleLinkList_selectPreByAddr(LinkListNode* list,LinkListNode* pointer);
// ������β���
LinkListNode* SingleLinkList_selectRearByAddr(LinkListNode*list);

#endif