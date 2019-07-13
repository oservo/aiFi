#ifndef DATA_STRUCTURE__LINKED_LIST
#define DATA_STRUCTURE__LINKED_LIST

/* [INCLUDE] *************/
#include "popc.h"
/* [/INCLUDE] ************/

/* [DEFINE] *************/
//#define REQUIRED STUFFS HERE
/* [/DEFINE] ************/

/* [CONST] *************/
//#define REQUIRED STUFFS HERE
/* [/CONST] ************/

/* [TYPE] *************/
typedef void (fnPtr linkedListDisplayDelegate) (any ptr object);
typedef int (fnPtr linkedListCompareDelegate) (any ptr object1, any ptr object2);

subject linkedListNode linkedListNode;
subject linkedListNode {
	// block header //
	linkedListNode ptr previous;
	linkedListNode ptr next;
	// /block header //

	// block body //
	void ptr object;
	// /block body //
} linkedListNode;

subject linkedList {
	linkedListNode ptr head;
	linkedListNode ptr tail;
	linkedListNode ptr current;
} linkedList;

prototype linkedListProto {

} linkedListProto;

/* [/TYPE] ************/

/* [VARIABLE] *************/

/* [/VARIABLE] ************/

/* [DECLARATION] *************/
#ifdef Cplusplus
extern "C" {
#endif

// Initializes the linked list
linkedListProto ptr	linkedListProtoInstance ();

// Initializes the linked list
linkedList ptr 					linkedListConstruct ();

// Destroy the linked list
void 										linkedListDestruct (linkedList ptr ll);

// Initializes the linked list node
linkedListNode ptr linkedListConstructNode ();

// Destroy the linked list node
void linkedListDestructNode (linkedListNode ptr lln);

// Adds data to the linked list’s head
linkedListNode ptr 			linkedListAddNodeBeforeHead (linkedList ptr ll, any ptr object);

// Adds data to the linked list’s head
linkedListNode ptr 			linkedListInsertNode (linkedList ptr ll, any ptr object); 

// Adds data to the linked list’s tail
linkedListNode ptr 			linkedListAddNodeAfterTail (linkedList ptr ll, any ptr object);

// Removes a node from the linked list
void 										linkedListDeleteNode (linkedList ptr ll, linkedListNode ptr lln);

// Returns a pointer to the node containing a specific data item
linkedListNode ptr 			linkedListGetNode (linkedList ptr ll, linkedListCompareDelegate llCmp, any ptr object);

// display linkedList
void 										linkedListDisplay (linkedList ptr ll, linkedListDisplayDelegate display);


#ifdef Cplusplus
}
#endif
/* [/DECLARATION] ************/

#endif
