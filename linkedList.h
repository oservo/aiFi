#ifndef DATA_STRUCTURE__LINKED_LIST
#define DATA_STRUCTURE__LINKED_LIST

/* <INCLUDE> *************/
#include "popc.h"
/* </INCLUDE> ************/

/* <DEFINE> *************/
//#define REQUIRED STUFFS HERE
/* </DEFINE> ************/

/* <CONST> *************/
//#define REQUIRED STUFFS HERE
/* </CONST> ************/

/* <TYPE> *************/
typedef void (fnPtr linkedListDisplayDelegate) (object ptr obj);
typedef int (fnPtr linkedListCompareDelegate) (object ptr obj1, object ptr obj2);

subject linkedListNode linkedListNode;
subject linkedListNode {
	// block header //
	linkedListNode ptr previous;
	linkedListNode ptr next;
	// /block header //

	// block body //
	void ptr obj;
	// /block body //
} linkedListNode;

subject linkedList {
	linkedListNode ptr head;
	linkedListNode ptr tail;
	linkedListNode ptr current;
} linkedList;

pattern linkedListProto {

} linkedListProto;

/* </TYPE> ************/

/* <VARIABLE> *************/

/* </VARIABLE> ************/

/* <DECLARATION> *************/
#ifdef Cplusplus
extern "C" {
#endif

// Initializes the linked list
linkedListProto ptr	linkedListProtoNew ();

// Initializes the linked list
linkedList ptr 					linkedListNew ();

// Destroy the linked list
void 										linkedListDel (linkedList ptr ll);

// Initializes the linked list cell
linkedListNode ptr linkedListNewNode ();

// Destroy the linked list cell
void linkedListDelNode (linkedListNode ptr lln);

// Adds data to the linked list’s head
linkedListNode ptr 			linkedListAddNodeBeforeHead (linkedList ptr ll, object ptr obj);

// Adds data to the linked list’s head
linkedListNode ptr 			linkedListInsertNode (linkedList ptr ll, object ptr obj); 

// Adds data to the linked list’s tail
linkedListNode ptr 			linkedListAddNodeAfterTail (linkedList ptr ll, object ptr obj);

// Removes a cell from the linked list
void 										linkedListDeleteNode (linkedList ptr ll, linkedListNode ptr lln);

// Returns a pointer to the cell containing a specific data item
linkedListNode ptr 			linkedListGetNode (linkedList ptr ll, linkedListCompareDelegate llCmp, object ptr obj);

// display linkedList
void 										linkedListDisplay (linkedList ptr ll, linkedListDisplayDelegate display);


#ifdef Cplusplus
}
#endif
/* </DECLARATION> ************/

#endif
