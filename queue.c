#include <stdio.h>
#include <stdlib.h>
#include "popc.h"



#include "linkedList.h"
#include "queue.h"

queue ptr queueNew () {
	queue ptr q;
	q = (queue ptr) linkedListNew ();
	return q;
}

void queueEnqueue(queue ptr queue, object ptr obj) {
	linkedListAddNodeBeforeHead (queue, obj);
}

object ptr queueDequeue(queue ptr queue) {
	linkedListNode ptr tmp = queue -> head;
	object ptr obj;

	if (queue -> head == NULL) {
		obj = NULL;
	} 
	else if (queue -> head == queue -> tail) {
		queue -> head = queue -> tail = NULL;
		obj = tmp -> obj;
		free(tmp);
	} 
	else {
		while (tmp -> next != queue -> tail) {
			tmp = tmp -> next;
		}
		queue -> tail = tmp;
		tmp = tmp -> next;
		queue -> tail -> next = NULL;
		obj = tmp -> obj;
		free(tmp);
	}
	return obj;
}