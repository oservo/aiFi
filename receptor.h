#ifndef AIFI__RECEPTOR
#define AIFI__RECEPTOR

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
	rtExcitatory,
	rtInhibitory
} receptorType;

subject receptor {
	receptorType type;
	message message;

} receptor;

prototype receptorProto {

} receptorProto;

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
