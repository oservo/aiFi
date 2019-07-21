#ifndef AIFI__TRAINING
#define AIFI__TRAINING

/* <INCLUDE> *************/
#include "popc.h"
/* </INCLUDE> ************/

/* <FORWARD DECLARATION> *************/
//
/* </FORWARD DECLARATION> ************/

/* <DEFINE> *************/
//#define
/* </DEFINE> ************/

/* <CONST> *************/
//const
/* </CONST> ************/

/* <ENUMERATION> *************/
enumeration trainingType {
	ttBatchTraining,
	ttOnlineTraining,
} trainingType;
/* </ENUMERATION> *************/


/* <SUBJECT> *************/
subject training {

} training;
/* </SUBJECT> *************/

/* <PROTOTYPE> *************/

pattern trainingSingleton {
	training ptr (fnPtr trainingNew) ();
	void (fnPtr trainingDel) (training ptr obj);
} trainingSingleton;

/* </PROTOTYPE> ************/

/* <VARIABLE> *************/
// variable
/* </VARIABLE> ************/

/* <DECLARATION> *************/
#ifdef Cplusplus
extern "C" {
#endif

trainingSingleton ptr trainingSingletonNew ();

training ptr trainingNew ();
void trainingDel (training ptr obj);


#ifdef Cplusplus
}
#endif
/* </DECLARATION> ************/

#endif
