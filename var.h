#ifndef FRAMEWORK__VAR
#define FRAMEWORK__VAR

/* [INCLUDE] *************/
#include "popc.h"
/* [/INCLUDE] ************/

/* [DEFINE] *************/
//#define REQUIRED STUFFS HERE
/* [/DEFINE] ************/

/* [CONST] *************/
//#define REQUIRED STUFFS HERE
/* [/CONST] ************/

/* [TYPE] *************/

enumeration {
	vtInt,
	vtChar,
	vtShort,
	vtLong,
	vtFloat,
	vtDouble,
	vtAny
} varType;

subject var {
	any ptr o; //OBJECT
	const varType t; //TYPE
} var;

prototype varProto {

} varProto;

/* [/TYPE] ************/

/* [VARIABLE] *************/

/* [/VARIABLE] ************/

/* [DECLARATION] *************/
#ifdef Cplusplus
extern "C" {
#endif

varProto ptr varProtoInstance ();
var ptr varConstruct (varType vt, any ptr object);
var ptr varInt (any ptr object);
void varDestruct (var ptr object);

//var ptr varSet (any ptr object);
//var ptr varGet (any ptr object);

#ifdef Cplusplus
}
#endif
/* [/DECLARATION] ************/

#endif
