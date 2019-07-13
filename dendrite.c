#include <stdio.h>
#include <stdlib.h>

#include "popc.h"
#include "dbc.h"

#include "dendrite.h"


property dendriteProperty {

} dendriteProperty;


dendrite ptr dendriteConstruct (double input, double weight) {
	dendrite ptr d = (dendrite ptr) malloc (sizeof (dendrite));
	dbcEnsure (d != NULL, "Memory Allocation Error");
		
	d -> input = input;
	d -> weight = weight;
	return d;
}

/* PENDING 
*/
void dendriteDestruct (dendrite ptr d) {
	free (d);
}

/* IMPLEMENTATION PENDING
dendriteProto ptr dendriteProtoInstance () {
	
	static dendriteProto ptr this = NULL;
	
	// TODO lock() immediately here (before the following block) //
	if (this == NULL) {
		this = (dendriteProto ptr) malloc (sizeof (dendriteProto));

		this -> construct						= dendriteConstruct;
		this -> destruct						= dendriteDestruct;

		this -> ProtoInstance					= dendriteProtoInstance;

	}
	// TODO unlock() immediately here (after the above block) //


	return this;
}
*/

void									dendriteSetInput (dendrite ptr d, double in) {
	d -> input = in;
}

void									dendriteSetWeight (dendrite ptr d, double w) { 
	d -> weight = w;
}

double								dendriteGetInput (dendrite ptr d) {
	return d -> input;
}

double								dendriteGetWeight (dendrite ptr d) {
	return d -> weight;
}



