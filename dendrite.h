#ifndef AIFI__DENDRITE
#define AIFI__DENDRITE

/* [INCLUDE] *************/
#include "popc.h"
#include "receptor.h"
/* [/INCLUDE] ************/

/* [DEFINE] *************/
//#define REQUIRED STUFFS HERE
/* [/DEFINE] ************/

/* [CONST] *************/
//#define REQUIRED STUFFS HERE
/* [/CONST] ************/

/* [TYPE] *************/

subject dendrite {
	//TODO:V3: receptor ptr receptor;
	//TODO:V3: struct synapse ptr synapse;
	double input;
	double weight;
} dendrite;

prototype dendriteProto {
	
} dendriteProto;

/* [/TYPE] ************/

/* [VARIABLE] *************/

/* [/VARIABLE] ************/

/* [DECLARATION] *************/
#ifdef Cplusplus
extern "C" {
#endif

dendriteProto ptr			dendriteProtoInstance ();

dendrite ptr 					dendriteConstruct ();
void 									dendriteDestruct (dendrite ptr d);

void									dendriteSetInput (dendrite ptr d, double in);
void									dendriteSetWeight (dendrite ptr d, double w);

double								dendriteGetInput (dendrite ptr d);
double								dendriteGetWeight (dendrite ptr d);

#ifdef Cplusplus
}
#endif
/* [/DECLARATION] ************/

#endif
