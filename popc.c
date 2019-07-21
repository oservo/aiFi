#include <stdio.h>
#include <stdlib.h>

#include "popc.h"


varProto ptr varProtoNew () {
	//PENDING
	varProto ptr vi = NULL;
	vi = (varProto ptr) malloc (sizeof (varProto));
	dbcEnsure (vi != NULL, "Memory Allocation Error!");

	return vi;
}

var ptr varNew (varType vt, object ptr obj) {
	var ptr v;
	v = (var ptr) malloc (sizeof (var));
	dbcEnsure (v != NULL, "Memory Allocation Error!");

	ptrVal (varType ptr) addr v->t = vt; //write to const
	v -> o = obj;
	return v;
}

/*
var ptr varInt (object ptr obj) {
	var ptr v;
	v = (var ptr) malloc (sizeof (var));
	dbcEnsure (v != NULL, "Memory Allocation Error!");
	//not allowed to update const: v -> vt =  vtInt;
	ptrVal (varType ptr) addr v->t = vtInt; //allowed to update const
	v -> o = obj;
	return v;
}
*/

void varDel (var ptr v) {
	free (v); 
}

/*
var ptr varSet (var ptr v, object ptr obj) {
}

var ptr varGet (object ptr obj) {

}
*/


arraySingleton ptr arraySingletonNew () {
	static arraySingleton ptr sp = NULL;
		
	if (sp == NULL) {
		sp = (arraySingleton ptr) malloc (sizeof (arraySingleton));
		dbcEnsure (sp != NULL, "Memory Allocation Error!");
	}
	//implement interfaces
	return sp;
} 

array ptr arrayNew () {
  array ptr s = (array ptr) malloc (sizeof (array));
	dbcEnsure (s != NULL, "Memory Allocation Error!");
	//set properties
  return s;
}

void arrayDel (array ptr s) {
  // PENDING! need to clean-up inner objects
	free (s);
	s = NULL;
}


stringSingleton ptr stringSingletonNew () {
	static stringSingleton ptr sp = NULL;
		
	if (sp == NULL) {
		sp = (stringSingleton ptr) malloc (sizeof (stringSingleton));
		dbcEnsure (sp != NULL, "Memory Allocation Error!");
	}
	//implement interfaces
	return sp;
} 

string ptr stringNew () {
  string ptr s = (string ptr) malloc (sizeof (string));
	dbcEnsure (s != NULL, "Memory Allocation Error!");
	//set properties
  return s;
}

void stringDel (string ptr s) {
  // PENDING! need to clean-up inner objects
	free (s);
	s = NULL;
}

