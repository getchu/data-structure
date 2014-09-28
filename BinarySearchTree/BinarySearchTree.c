#include "BinarySearchTree.h"

BSTreeNode* BinarySearchTree_init(ElementType data)
{
	BSTreeNode* newNodePointer = NULL;

	newNodePointer = (BSTreeNode *)malloc(sizeof(BSTreeNode));
	newNodePointer->data = data;
	newNodePointer->left = NULL;
	newNodePointer->right = NULL;

	return newNodePointer;
}

// 增,并返回该结点地址
BSTreeNode* BinarySearchTree_insert(BSTreeNode *tree, ElementType data)
{
	BSTreeNode* newNodePointer = NULL;
	BSTreeNode* parentNodePointer = NULL;

	if( !tree ) // 空树
	{
		return BinarySearchTree_init(data);
	}

	 // 已存在相同的数据则不再插入
	if ( (newNodePointer = BinarySearchTree_select(tree,data)) )
		return newNodePointer;

	newNodePointer = BinarySearchTree_init(data);
	while( tree ) //遍历直到叶子
	{
		parentNodePointer = tree;//保存父结点
		if( data < tree->data )
		{
			tree = tree->left;
		}else{
			tree = tree->right;
		}
	}
	
	if( data < parentNodePointer->data ) //插入
	{
		parentNodePointer->left = newNodePointer;
	}else{
		parentNodePointer->right = newNodePointer;
	}

	return newNodePointer;
}

// 删
int BinarySearchTree_delete(BSTreeNode *tree, ElementType data)
{
	// 遍历直到:tree该结点数据域等于形参data;
	// parentNode是pBSTreeNode结点的父节点;

	BSTreeNode *parentNode = NULL;
	char founded = 0;

	if( !tree )
		return 0; // 空树 delete failure
	
	do{ //遍历查找
		if( data == tree->data )
		{
			founded = 1;
		}else
		{
			parentNode = tree; //保存父结点
			if( data < tree->data )
			{
				tree = tree->left;
			}else
			{
				tree = tree->right;
			}
		}
	}while( !founded && tree );
	
	if( tree )
		return 0; // 找不到该结点 delete failure

	/* 如果找到该结点,有四种情况:
	 * 1.无孩子的叶子结点;
	 * 2.有左右孩子;
	 * 3.有右孩子;
	 * 4.有左孩子;
	 */

	if( NULL == tree->left && NULL == tree->right )//该结点是叶子结点
	{
		if( data < parentNode->data) //该结点在父节点的左子树
		{
			parentNode->left = NULL;
		}else                        //该结点是父节点的右子树
		{
			parentNode->right = NULL;
		}

	}
/* 优化代码存储空间
	else if( tree->left && tree->right ) //该结点有两个孩子
	{
		if( data < parentNode->data) //该结点在父节点的左子树
		{
			parentNode->left = tree->right;
		}else                       //该结点是父节点的右子树
		{
			parentNode->right = tree->right;
		}
	}
	else if( NULL== tree->left && tree->right ) //该结点有右孩子
	{
		if( data < parentNode->data) //该结点在父节点的左子树
		{
			parentNode->left = tree->right;  // 把孙子交给爷爷结点管理
		}else                       //该结点是父节点的右子树
		{
			parentNode->right = tree->right;  // 把孙子交给爷爷结点管理
		}
	}
	else if( tree->left && NULL == tree->right ) //该结点有左孩子
	{
		if( data < parentNode->data) //该结点在父节点的左子树
		{
			parentNode->left = tree->left;   // 把孙子交给爷爷结点管理
		}else                       //该结点是父节点的右子树
		{
			parentNode->right = tree->left; // 把孙子交给爷爷结点管理
		}
	}
*/
	// 优化后的代码如下
	else if( tree->left && NULL == tree->right ) //该结点有左孩子
	{
		if( data < parentNode->data) //该结点在父节点的左子树
		{
			parentNode->left = tree->left;   // 把孙子交给爷爷结点管理
		}else                       //该结点是父节点的右子树
		{
			parentNode->right = tree->left; // 把孙子交给爷爷结点管理
		}
	}else // 优化点:无论有两个孩子或右孩子, 都会把该结点的右孩子交给爷爷管理
	{
		if( data < parentNode->data) //该结点在父节点的左子树
		{
			parentNode->left = tree->right;  // 把孙子交给爷爷结点管理
		}else                       //该结点是父节点的右子树
		{
			parentNode->right = tree->right;  // 把孙子交给爷爷结点管理
		}
	}
	// 优化结束

	// 再见!
	free(tree);
	return 1; // delete success
}

// 查
BSTreeNode* BinarySearchTree_select(BSTreeNode *tree, ElementType data)
{
	char founded = 0;

	while( !founded && tree )
	{
		if( data == tree->data )
			founded = 1;
		else if( data < tree->data )
			tree = tree->left;
		else
			tree = tree->right;
	}

	/* if( NULL == tree )
	 *    return NULL;
	 */
	return tree;
}