#define ElementType float
#include "BinarySearchTree.h"
#include <stdio.h>

int main()
{
	BSTreeNode *tree = NULL;

	tree = BinarySearchTree_init( 3.14f );
	printf( "( %f )\r\n", tree->data );

	BinarySearchTree_insert( tree, 666.666666f );
	printf( "( %f )\r\n", tree->right->data );

	BinarySearchTree_insert( tree, 1.123f );
	printf( "( %f )\r\n", tree->left->data );

	getchar();
	getchar();
	return 0;
}