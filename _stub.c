#include <stdio.h>
#include <stdlib.h>

#include "popc.h"
#include "_stub.h"

stubSingleton ptr stubSingletonNew () {
	static stubSingleton ptr sp = NULL;
		
	if (sp == NULL) {
		sp = (stubSingleton ptr) malloc (sizeof (stubSingleton));
		dbcEnsure (sp != NULL, "Memory Allocation Error!");
	}
	//implement interfaces
	return sp;
} 

stub ptr stubNew () {
  stub ptr s = (stub ptr) malloc (sizeof (stub));
	dbcEnsure (s != NULL, "Memory Allocation Error!");
	//set properties
  return s;
}

void stubDel (stub ptr s) {
  // PENDING! need to clean-up inner objects
	free (s);
	s = NULL;
}
