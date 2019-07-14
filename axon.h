#ifndef AIFI__AXON
#define AIFI__AXON

/* [INCLUDE] *************/
#include "popc.h"
#include "neurotransmitter.h"

/* [/INCLUDE] ************/

/* [DEFINE] *************/
//#define REQUIRED STUFFS HERE
/* [/DEFINE] ************/

/* [CONST] *************/
//#define REQUIRED STUFFS HERE
/* [/CONST] ************/

/* [TYPE] *************/

subject axon {
	//TODO:V3: neurotransmitter ptr neurotransmitter;
	//TODO:V3: struct synapse ptr synapse;
	double target;
	double output;
	//??double gradient;
} axon;

prototype axonProto {

} axonProto;

/* [/TYPE] ************/

/* [VARIABLE] *************/

/* [/VARIABLE] ************/

/* [DECLARATION] *************/
#ifdef Cplusplus
extern "C" {
#endif

axon ptr 					axonConstruct ();
void 							axonDestruct (axon ptr axon);
axonProto ptr	axonProtoInstance ();


#ifdef Cplusplus
}
#endif
/* [/DECLARATION] ************/

#endif
