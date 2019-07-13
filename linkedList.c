#include <stdio.h>
#include <stdlib.h>

#include "popc.h"
#include "dbc.h"


#include "linkedList.h"

property linkedListProperty {

} linkedListProperty;

// Initializes the linked list
linkedListProto ptr linkedListProtoInstance () {
	linkedListProto ptr proto = (linkedListProto ptr) malloc (sizeof (linkedListProto));
	dbcEnsure (proto != NULL, "Memory Allocation Error");
	return proto;
}

// Initializes the linked list
linkedList ptr linkedListConstruct () {
	linkedList ptr ll = (linkedList ptr) malloc (sizeof (linkedList));
	dbcEnsure (ll != NULL, "Memory Allocation Error");

	ll -> head = NULL;
	ll -> current = NULL;
	ll -> tail = NULL;
	return ll;
}

// Initializes the linked list
void linkedListDestruct (linkedList ptr ll) {
	// PENDING
	// TODO: loop through the list and free all objects
	free (ll);
}

linkedListNode ptr linkedListConstructNode () {
	linkedListNode ptr lln = (linkedListNode ptr) malloc (sizeof (linkedListNode));
	dbcEnsure (lln != NULL, "Memory Allocation Error");

	lln -> previous = NULL;
	lln -> next = NULL;
	lln -> object = NULL;
	return lln;
}

// Initializes the linked list
void linkedListDestructNode (linkedListNode ptr lln) {
	// PENDING
	// TODO: loop through the list and free all objects
	free (lln);
}

// Adds data to the linked list
linkedListNode ptr linkedListInsertNode (linkedList ptr ll, any ptr object) {
	return linkedListAddNodeAfterTail (ll, object);
}

/* PENDING
//update
void linkedListUpdateNode (linkedList ptr ll, linkedListNode ptr lln, any ptr object) {
	//PENDING
}
*/

// Adds data to the linked list’s head
linkedListNode ptr linkedListAddNodeBeforeHead (linkedList ptr ll, any ptr object) {
	linkedListNode ptr node = linkedListConstructNode ();
	node -> object = object;
	node -> previous = NULL; 
	if (ll -> head == NULL) {
		node -> next = NULL;
		ll -> tail = node;
	} 
	else {
		node -> next = ll -> head;
	}
	ll -> head = node;
	return node;
}

// Adds data to the linked list’s tail
linkedListNode ptr linkedListAddNodeAfterTail (linkedList ptr ll, any ptr object) {
	linkedListNode ptr node = (linkedListNode ptr) malloc (sizeof (linkedListNode));
	dbcEnsure (node != NULL, "Memory Allocation Error");

	node -> object = object;
	node -> next = NULL;
	if (ll -> head == NULL) {
		node -> previous = NULL;
		ll -> head = node;
	} 
	else {
		node -> previous = ll -> tail;
		ll -> tail -> next = node;
	}
	ll -> tail = node;	
	return node;
}

// Removes a node from the linked list
void linkedListDeleteNode (linkedList ptr ll, linkedListNode ptr node) {
	if (node == ll -> head) {
		if (ll -> head -> next == NULL) {
			ll -> head = NULL;
			ll -> tail = NULL;
			free (node);
		} 
		else {
			ll -> head = ll -> head -> next;
			ll -> head -> previous = NULL;
			free (node);
		}
	} 
	else {
		linkedListNode ptr tmpNode = ll -> head -> next;
		while (tmpNode != NULL && tmpNode != node) {
			tmpNode = tmpNode -> next;
		}
		if (tmpNode != NULL) {
			tmpNode -> previous -> next = tmpNode -> next;
			if (tmpNode -> next != NULL) tmpNode -> next -> previous = tmpNode -> previous;
			free (node);
		}
	}
	
}

// Returns a pointer to the node containing a specific data item
linkedListNode ptr linkedListGetNode (linkedList ptr ll, linkedListCompareDelegate compareCallback, void ptr object) {
	linkedListNode ptr node = ll -> head;
	while (node != NULL) {
		if (compareCallback(node -> object, object) == 0) {
			return node;
		}
		node = node -> next;
	}
	return NULL;
}

void linkedListDisplay (linkedList ptr ll, linkedListDisplayDelegate displayCallback) {
	printf("\nLinked List\n");
	linkedListNode ptr current = ll -> head;
	while (current != NULL) {
		displayCallback(current -> object);
		current = current -> next;
	}
}