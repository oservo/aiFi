#include <stdio.h>
#include <stdlib.h>

#include "popc.h"
#include "dbc.h"

#include "axon.h"


property axonProperty {

} axonProperty;

axon ptr axonConstruct () {
	axon ptr axo = (axon ptr) malloc (sizeof (axon));
	dbcEnsure (axo != NULL, "Memory Allocation Error");
		
	return axo;
}

/* PENDING 
*/
void axonDestruct (axon ptr axo) {
	free (axo);
}

/* IMPLEMENTATION PENDING
axonProto ptr axonProtoInstance () {
	
	static axonProto ptr this = NULL;
	
	// TODO lock() immediately here (before the following block) //
	if (this == NULL) {
		this = (axonProto ptr) malloc (sizeof (axonProto));

		this -> construct						= axonConstruct;
		this -> destruct						= axonDestruct;

		this -> ProtoInstance					= axonProtoInstance;

	}
	// TODO unlock() immediately here (after the above block) //


	return this;
}
*/

