#include <stdio.h>
#include <stdlib.h>

#include "popc.h"
#include "training.h"

trainingSingleton ptr trainingSingletonNew () {
	static trainingSingleton ptr sp = NULL;
		
	if (sp == NULL) {
		sp = (trainingSingleton ptr) malloc (sizeof (trainingSingleton));
		dbcEnsure (sp != NULL, "Memory Allocation Error!");
	}
	//implement interfaces
	return sp;
} 

training ptr trainingNew () {
  training ptr s = (training ptr) malloc (sizeof (training));
	dbcEnsure (s != NULL, "Memory Allocation Error!");
	//set properties
  return s;
}

void trainingDel (training ptr s) {
  // PENDING! need to clean-up inner objects
	free (s);
	s = NULL;
}
