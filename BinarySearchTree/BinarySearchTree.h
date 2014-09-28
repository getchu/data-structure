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

// 工厂方法:初始化结点
BSTreeNode* BinarySearchTree_init(ElementType data);
// 增,并返回该结点地址
BSTreeNode* BinarySearchTree_insert(BSTreeNode *tree, ElementType data);
// 删,{1:"success",0:"failure"}
int BinarySearchTree_delete(BSTreeNode *tree, ElementType data);
// 查,返回该数据结点地址
BSTreeNode* BinarySearchTree_select(BSTreeNode *tree, ElementType data);




#endif // !BinarySearchTree