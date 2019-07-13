#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "popc.h"
#include "dbc.h"

#include "linkedList.h"
#include "tree.h"

property treeProperty {

} treeProperty;

void treeInsertNode(treeNode ptr2d root, linkedListCompareDelegate compare, any ptr object) {
	treeNode ptr node = (treeNode ptr) malloc (sizeof (treeNode));
	dbcEnsure (node != NULL, "Memory Allocation Error");

	node->object = object;
	node->left = NULL;
	node->right = NULL;

	if (*root == NULL) {
		*root = node;
		return;
	}

	while (1) {
		//if (compare((*root)->data, data) > 0) {
		if (compare((*root)->object, object) > 0) {
			if ((*root)->left != NULL) {
				*root = (*root)->left;
			} 
			else {
				(*root)->left = node;
				break;
			}
		} 
		else {
			if ((*root)->right != NULL) {
				*root = (*root)->right;
			} 
			else {
				(*root)->right = node;
				break;
			}
		}
	}
}

void inOrder(treeNode ptr root, linkedListDisplayDelegate display) {
	if (root != NULL) {
		inOrder(root->left, display);
		display(root->object);
		inOrder(root->right, display);
	}
}
void postOrder(treeNode ptr root, linkedListDisplayDelegate display) {
	if (root != NULL) {
		postOrder(root->left, display);
		postOrder(root->right, display);
		display(root->object);
	}
}
void preOrder(treeNode ptr root, linkedListDisplayDelegate display) {
	if (root != NULL) {
		display(root->object);
		preOrder(root->left, display);
		preOrder(root->right, display);
	}
}