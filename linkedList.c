#include <stdio.h>
#include <stdlib.h>

#include "popc.h"



#include "linkedList.h"

// Initializes the linked list
linkedListProto ptr linkedListProtoNew () {
	linkedListProto ptr proto = (linkedListProto ptr) malloc (sizeof (linkedListProto));
	dbcEnsure (proto != NULL, "Memory Allocation Error!");
	return proto;
}

// Initializes the linked list
linkedList ptr linkedListNew () {
	linkedList ptr ll = (linkedList ptr) malloc (sizeof (linkedList));
	dbcEnsure (ll != NULL, "Memory Allocation Error!");

	ll -> head = NULL;
	ll -> current = NULL;
	ll -> tail = NULL;
	return ll;
}

// Initializes the linked list
void linkedListDel (linkedList ptr ll) {
	// PENDING
	// TODO: loop through the list and free all objs
	free (ll);
}

linkedListNode ptr linkedListNewNode () {
	linkedListNode ptr lln = (linkedListNode ptr) malloc (sizeof (linkedListNode));
	dbcEnsure (lln != NULL, "Memory Allocation Error!");

	lln -> previous = NULL;
	lln -> next = NULL;
	lln -> obj = NULL;
	return lln;
}

// Initializes the linked list
void linkedListDelNode (linkedListNode ptr lln) {
	// PENDING
	// TODO: loop through the list and free all objs
	free (lln);
}

// Adds data to the linked list
linkedListNode ptr linkedListInsertNode (linkedList ptr ll, object ptr obj) {
	return linkedListAddNodeAfterTail (ll, obj);
}

/* PENDING
//update
void linkedListUpdateNode (linkedList ptr ll, linkedListNode ptr lln, object ptr obj) {
	//PENDING
}
*/

// Adds data to the linked list’s head
linkedListNode ptr linkedListAddNodeBeforeHead (linkedList ptr ll, object ptr obj) {
	linkedListNode ptr cell = linkedListNewNode ();
	cell -> obj = obj;
	cell -> previous = NULL; 
	if (ll -> head == NULL) {
		cell -> next = NULL;
		ll -> tail = cell;
	} 
	else {
		cell -> next = ll -> head;
	}
	ll -> head = cell;
	return cell;
}

// Adds data to the linked list’s tail
linkedListNode ptr linkedListAddNodeAfterTail (linkedList ptr ll, object ptr obj) {
	linkedListNode ptr cell = (linkedListNode ptr) malloc (sizeof (linkedListNode));
	dbcEnsure (cell != NULL, "Memory Allocation Error!");

	cell -> obj = obj;
	cell -> next = NULL;
	if (ll -> head == NULL) {
		cell -> previous = NULL;
		ll -> head = cell;
	} 
	else {
		cell -> previous = ll -> tail;
		ll -> tail -> next = cell;
	}
	ll -> tail = cell;	
	return cell;
}

// Removes a cell from the linked list
void linkedListDeleteNode (linkedList ptr ll, linkedListNode ptr cell) {
	if (cell == ll -> head) {
		if (ll -> head -> next == NULL) {
			ll -> head = NULL;
			ll -> tail = NULL;
			free (cell);
		} 
		else {
			ll -> head = ll -> head -> next;
			ll -> head -> previous = NULL;
			free (cell);
		}
	} 
	else {
		linkedListNode ptr tmpNode = ll -> head -> next;
		while (tmpNode != NULL && tmpNode != cell) {
			tmpNode = tmpNode -> next;
		}
		if (tmpNode != NULL) {
			tmpNode -> previous -> next = tmpNode -> next;
			if (tmpNode -> next != NULL) tmpNode -> next -> previous = tmpNode -> previous;
			free (cell);
		}
	}
	
}

// Returns a pointer to the cell containing a specific data item
linkedListNode ptr linkedListGetNode (linkedList ptr ll, linkedListCompareDelegate compareCallback, void ptr obj) {
	linkedListNode ptr cell = ll -> head;
	while (cell != NULL) {
		if (compareCallback(cell -> obj, obj) == 0) {
			return cell;
		}
		cell = cell -> next;
	}
	return NULL;
}

void linkedListDisplay (linkedList ptr ll, linkedListDisplayDelegate displayCallback) {
	printf("\nLinked List\n");
	linkedListNode ptr current = ll -> head;
	while (current != NULL) {
		displayCallback(current -> obj);
		current = current -> next;
	}
}