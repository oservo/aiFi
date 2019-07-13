#include <stdio.h>
#include <stdlib.h>
#include "popc.h"
#include "dbc.h"

#include "linkedList.h"
#include "stack.h"

property stackProperty {

} stackProperty;

stack ptr stackConstruct () {
	stack ptr s;
	s = (stack ptr) linkedListConstruct ();
	return s;
}

void stackPush(stack ptr stack, any ptr object) {
	linkedListAddNodeBeforeHead (stack, object);
}

any ptr pop(stack ptr stack) {
	linkedListNode ptr node = stack -> head;
	if (node == NULL) {
		return NULL;
	} 
	else if (node == stack -> tail) {
		stack -> head = stack -> tail = NULL;
		any ptr object = node -> object;
		free(node);
		return object;
	} 
	else {
		stack -> head = stack -> head -> next;
		any ptr object = node -> object;
		free(node);
		return object;
	}
}