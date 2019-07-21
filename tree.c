#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "popc.h"


#include "linkedList.h"
#include "tree.h"

void treeInsertNode(treeNode ptr2d root, linkedListCompareDelegate compare, object ptr obj) {
	treeNode ptr cell = (treeNode ptr) malloc (sizeof (treeNode));
	dbcEnsure (cell != NULL, "Memory Allocation Error!");

	cell->obj = obj;
	cell->left = NULL;
	cell->right = NULL;

	if (*root == NULL) {
		*root = cell;
		return;
	}

	while (1) {
		//if (compare((*root)->data, data) > 0) {
		if (compare((*root)->obj, obj) > 0) {
			if ((*root)->left != NULL) {
				*root = (*root)->left;
			} 
			else {
				(*root)->left = cell;
				break;
			}
		} 
		else {
			if ((*root)->right != NULL) {
				*root = (*root)->right;
			} 
			else {
				(*root)->right = cell;
				break;
			}
		}
	}
}

void inOrder(treeNode ptr root, linkedListDisplayDelegate display) {
	if (root != NULL) {
		inOrder(root->left, display);
		display(root->obj);
		inOrder(root->right, display);
	}
}

void postOrder(treeNode ptr root, linkedListDisplayDelegate display) {
	if (root != NULL) {
		postOrder(root->left, display);
		postOrder(root->right, display);
		display(root->obj);
	}
}

void preOrder(treeNode ptr root, linkedListDisplayDelegate display) {
	if (root != NULL) {
		display(root->obj);
		preOrder(root->left, display);
		preOrder(root->right, display);
	}
}