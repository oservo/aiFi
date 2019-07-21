#ifndef DATA_STRUCTURE__QUEUE
#define DATA_STRUCTURE__QUEUE

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

typedef linkedList queue;

pattern queueProto {

} queueProto;

/* </TYPE> ************/

/* <VARIABLE> *************/

/* </VARIABLE> ************/

/* <DECLARATION> *************/
#ifdef Cplusplus
extern "C" {
#endif

queue ptr queueNew ();
void queueEnqueue(queue ptr queue, object ptr obj);
object ptr queueDequeue(queue ptr queue);

#ifdef Cplusplus
}
#endif
/* </DECLARATION> ************/

#endif
