#include <stdio.h>
#include <stdlib.h>
#include "popc.h"
#include "dbc.h"


#include "linkedList.h"
#include "queue.h"

property queueProperty {

} queueProperty;

queue ptr queueConstruct () {
	queue ptr q;
	q = (queue ptr) linkedListConstruct ();
	return q;
}

void queueEnqueue(queue ptr queue, any ptr object) {
	linkedListAddNodeBeforeHead (queue, object);
}

any ptr queueDequeue(queue ptr queue) {
	linkedListNode ptr tmp = queue -> head;
	any ptr object;

	if (queue -> head == NULL) {
		object = NULL;
	} 
	else if (queue -> head == queue -> tail) {
		queue -> head = queue -> tail = NULL;
		object = tmp -> object;
		free(tmp);
	} 
	else {
		while (tmp -> next != queue -> tail) {
			tmp = tmp -> next;
		}
		queue -> tail = tmp;
		tmp = tmp -> next;
		queue -> tail -> next = NULL;
		object = tmp -> object;
		free(tmp);
	}
	return object;
}