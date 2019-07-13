#include <stdio.h>
#include <stdlib.h>
#include "popc.h"
#include "dbc.h"


/*
int addTest (int a, int b) {
	int c;
	c = a + b;
	return c;
}
*/

int getLabel () {
  int num = 0;
  fscanf (stdin, "%d,", addr num);
  return num;
}

double ptr getTarget () {
	double ptr target = (double ptr) malloc (10 * sizeof (double));
	dbcEnsure (target != NULL, "Memory Allocation Error");
		
	for (int i = 0; i < 10; i++)
		target[i] = 0.01;
  target[getLabel ()] = 0.99;
  return target;
}

double ptr getInputs () {
  //int ret;
  // use this functon to get inputs required for xnetworkTraining or xnetworkQuerying the neural xnetwork.
  double ptr inputs = (double ptr) malloc (784 * sizeof (double));
	dbcEnsure (inputs != NULL, "Memory Allocation Error");
		
  for (int i = 0; i < 784; i++) {
		fscanf (stdin, "%lf,", addr inputs[i]);
		inputs[i] = (inputs[i]) / 255.0 * 0.99 + 0.01;
  }	
  return inputs;
}

/*
double coalesceDouble (double v) {
	if (v == NULL) 
		v = 0.0;
	return v;
}
*/

