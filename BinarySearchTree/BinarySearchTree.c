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

// ��,�����ظý���ַ
BSTreeNode* BinarySearchTree_insert(BSTreeNode *tree, ElementType data)
{
	BSTreeNode* newNodePointer = NULL;
	BSTreeNode* parentNodePointer = NULL;

	if( !tree ) // ����
	{
		return BinarySearchTree_init(data);
	}

	 // �Ѵ�����ͬ���������ٲ���
	if ( (newNodePointer = BinarySearchTree_select(tree,data)) )
		return newNodePointer;

	newNodePointer = BinarySearchTree_init(data);
	while( tree ) //����ֱ��Ҷ��
	{
		parentNodePointer = tree;//���游���
		if( data < tree->data )
		{
			tree = tree->left;
		}else{
			tree = tree->right;
		}
	}
	
	if( data < parentNodePointer->data ) //����
	{
		parentNodePointer->left = newNodePointer;
	}else{
		parentNodePointer->right = newNodePointer;
	}

	return newNodePointer;
}

// ɾ
int BinarySearchTree_delete(BSTreeNode *tree, ElementType data)
{
	// ����ֱ��:tree�ý������������β�data;
	// parentNode��pBSTreeNode���ĸ��ڵ�;

	BSTreeNode *parentNode = NULL;
	char founded = 0;

	if( !tree )
		return 0; // ���� delete failure
	
	do{ //��������
		if( data == tree->data )
		{
			founded = 1;
		}else
		{
			parentNode = tree; //���游���
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
		return 0; // �Ҳ����ý�� delete failure

	/* ����ҵ��ý��,���������:
	 * 1.�޺��ӵ�Ҷ�ӽ��;
	 * 2.�����Һ���;
	 * 3.���Һ���;
	 * 4.������;
	 */

	if( NULL == tree->left && NULL == tree->right )//�ý����Ҷ�ӽ��
	{
		if( data < parentNode->data) //�ý���ڸ��ڵ��������
		{
			parentNode->left = NULL;
		}else                        //�ý���Ǹ��ڵ��������
		{
			parentNode->right = NULL;
		}

	}
/* �Ż�����洢�ռ�
	else if( tree->left && tree->right ) //�ý������������
	{
		if( data < parentNode->data) //�ý���ڸ��ڵ��������
		{
			parentNode->left = tree->right;
		}else                       //�ý���Ǹ��ڵ��������
		{
			parentNode->right = tree->right;
		}
	}
	else if( NULL== tree->left && tree->right ) //�ý�����Һ���
	{
		if( data < parentNode->data) //�ý���ڸ��ڵ��������
		{
			parentNode->left = tree->right;  // �����ӽ���үү������
		}else                       //�ý���Ǹ��ڵ��������
		{
			parentNode->right = tree->right;  // �����ӽ���үү������
		}
	}
	else if( tree->left && NULL == tree->right ) //�ý��������
	{
		if( data < parentNode->data) //�ý���ڸ��ڵ��������
		{
			parentNode->left = tree->left;   // �����ӽ���үү������
		}else                       //�ý���Ǹ��ڵ��������
		{
			parentNode->right = tree->left; // �����ӽ���үү������
		}
	}
*/
	// �Ż���Ĵ�������
	else if( tree->left && NULL == tree->right ) //�ý��������
	{
		if( data < parentNode->data) //�ý���ڸ��ڵ��������
		{
			parentNode->left = tree->left;   // �����ӽ���үү������
		}else                       //�ý���Ǹ��ڵ��������
		{
			parentNode->right = tree->left; // �����ӽ���үү������
		}
	}else // �Ż���:�������������ӻ��Һ���, ����Ѹý����Һ��ӽ���үү����
	{
		if( data < parentNode->data) //�ý���ڸ��ڵ��������
		{
			parentNode->left = tree->right;  // �����ӽ���үү������
		}else                       //�ý���Ǹ��ڵ��������
		{
			parentNode->right = tree->right;  // �����ӽ���үү������
		}
	}
	// �Ż�����

	// �ټ�!
	free(tree);
	return 1; // delete success
}

// ��
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