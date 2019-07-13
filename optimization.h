#ifndef PANN__OPTIMIZATION
#define PANN__OPTIMIZATION

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

subject optimization {

} optimization;

prototype optimizationProto {

} optimizationProto;

/* [/TYPE] ************/

/* [VARIABLE] *************/

/* [/VARIABLE] ************/

/* [DECLARATION] *************/
#ifdef Cplusplus
extern "C" {
#endif

double gradientDescent ();
double stochasticGradientDescent ();
double adagrad ();
double adam ();


#ifdef Cplusplus
}
#endif
/* [/DECLARATION] ************/

#endif
