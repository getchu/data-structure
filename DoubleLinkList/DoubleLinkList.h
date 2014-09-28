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

// ��������,��ʼ��,����һ�����ݽ��
DLinkListNode* DoubleLinkList_init(ElementType data);
// ��,�����½���ַ
DLinkListNode* DoubleLinkList_insertBehind(DLinkListNode* preNodePointer, ElementType data);//��
DLinkListNode* DoubleLinkList_insertBefore(DLinkListNode* backNodePointer, ElementType data);//ǰ
// ɾ,��������ͷָ��
DLinkListNode* DoubleLinkList_deleteByData(DLinkListNode* list,ElementType data);
DLinkListNode* DoubleLinkList_deleteByAddr(DLinkListNode* list,DLinkListNode* pointer);
// ��,�������ݽ���ַ
DLinkListNode* DoubleLinkList_select(DLinkListNode* list,ElementType data);
// ��,{1:"success",0:"failure"}
int DoubleLinkList_updateByData(DLinkListNode* list,ElementType oldData,ElementType newData);

// һ�����߷���
// ������β���
DLinkListNode* DoubleLinkList_selectRearByAddr(DLinkListNode *list);

#endif // !DoubleLinkList