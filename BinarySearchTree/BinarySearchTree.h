#pragma once

#ifndef BinarySearchTree
#define BinarySearchTree
#include "BinarySearchTree.h"

#ifndef ElementType
#define ElementType int
#endif

#ifndef malloc_h
#define malloc_h
#include <malloc.h>
#endif // !malloc_h

#ifndef NULL
#define NULL (0)
#endif

typedef struct BinarySearchTreeStruct{
	ElementType data;
	struct BinarySearchTreeStruct *left,*right;
} BSTreeNode;

// ��������:��ʼ�����
BSTreeNode* BinarySearchTree_init(ElementType data);
// ��,�����ظý���ַ
BSTreeNode* BinarySearchTree_insert(BSTreeNode *tree, ElementType data);
// ɾ,{1:"success",0:"failure"}
int BinarySearchTree_delete(BSTreeNode *tree, ElementType data);
// ��,���ظ����ݽ���ַ
BSTreeNode* BinarySearchTree_select(BSTreeNode *tree, ElementType data);




#endif // !BinarySearchTree