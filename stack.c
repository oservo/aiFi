#include <stdio.h>
#include <stdlib.h>
#include "popc.h"


#include "linkedList.h"
#include "stack.h"

stack ptr stackNew () {
	stack ptr s;
	s = (stack ptr) linkedListNew ();
	return s;
}

void stackPush(stack ptr stack, object ptr obj) {
	linkedListAddNodeBeforeHead (stack, obj);
}

object ptr stackPop(stack ptr stack) {
	linkedListNode ptr cell = stack -> head;
	if (cell == NULL) {
		return NULL;
	} 
	else if (cell == stack -> tail) {
		stack -> head = stack -> tail = NULL;
		object ptr obj = cell -> obj;
		free(cell);
		return obj;
	} 
	else {
		stack -> head = stack -> head -> next;
		object ptr obj = cell -> obj;
		free(cell);
		return obj;
	}
}