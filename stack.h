#ifndef DATA_STRUCTURE__STACK
#define DATA_STRUCTURE__STACK

/* <INCLUDE> *************/
#include "popc.h"
#include "linkedList.h"
/* </INCLUDE> ************/

/* <DEFINE> *************/
//#define REQUIRED STUFFS HERE
/* </DEFINE> ************/

/* <CONST> *************/
//#define REQUIRED STUFFS HERE
/* </CONST> ************/

/* <TYPE> *************/

typedef linkedList stack;

pattern stackProto {

} stackProto;

/* </TYPE> ************/

/* <VARIABLE> *************/

/* </VARIABLE> ************/

/* <DECLARATION> *************/
#ifdef Cplusplus
extern "C" {
#endif

stack ptr stackNew ();
void stackPush (stack ptr stack, object ptr obj);
void ptr stackPop (stack ptr stack);

#ifdef Cplusplus
}
#endif
/* </DECLARATION> ************/

#endif
