#ifndef PANN__NEUROTRANSMITTER
#define PANN__NEUROTRANSMITTER

/* [INCLUDE] *************/
#include "popc.h"
#include "message.h"
/* [/INCLUDE] ************/

/* [DEFINE] *************/
//#define REQUIRED STUFFS HERE
/* [/DEFINE] ************/

/* [CONST] *************/
//#define REQUIRED STUFFS HERE
/* [/CONST] ************/

/* [TYPE] *************/

enumeration {
	neurotransmitterExcitatory,
	neurotransmitterInhibitory
} neurotransmitterType;

subject neurotransmitter {
	neurotransmitterType type;
	message message;
} neurotransmitter;

prototype neurotransmitterProto {

} neurotransmitterProto;

/* [/TYPE] ************/

/* [VARIABLE] *************/

/* [/VARIABLE] ************/

/* [DECLARATION] *************/
#ifdef Cplusplus
extern "C" {
#endif



#ifdef Cplusplus
}
#endif
/* [/DECLARATION] ************/

#endif
