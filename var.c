#include <stdio.h>
#include <stdlib.h>

#include "popc.h"
#include "dbc.h"
#include "var.h"


varProto ptr varProtoInstance () {
	//PENDING
	varProto ptr vp = NULL;

	return vp;
}

var ptr varConstruct (varType vt, any ptr object) {
	var ptr v;
	v = (var ptr) malloc (sizeof (var));
	dbcEnsure (v != NULL, "Memory Allocation Error");

	ptrVal (varType ptr) addr v->t = vt; //write to const
	v -> o = object;
	return v;
}

var ptr varInt (any ptr object) {
	var ptr v;
	v = (var ptr) malloc (sizeof (var));
	dbcEnsure (v != NULL, "Memory Allocation Error");
	//not allowed to update const: v -> vt =  vtInt;
	ptrVal (varType ptr) addr v->t = vtInt; //allowed to update const
	v -> o = object;
	return v;
}

void varDestruct (var ptr v) {
	free (v); 
}

/*
var ptr varSet (var ptr v, any ptr object) {
}

var ptr varGet (any ptr object) {

}
*/



