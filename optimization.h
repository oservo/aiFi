#ifndef AIFI__OPTIMIZATION
#define AIFI__OPTIMIZATION

/* <INCLUDE> *************/
#include "popc.h"
/* </INCLUDE> ************/

/* <DEFINE> *************/
//#define REQUIRED STUFFS HERE
/* </DEFINE> ************/

/* <CONST> *************/
//#define REQUIRED STUFFS HERE
/* </CONST> ************/

delegation double (fnPtr optimizationFunctionDelegate) ();
delegation double (fnPtr optimizationFunctionPrimeDelegate) ();

/* <TYPE> *************/
enumeration optimizationFunctionType {
	oftGradientDescent,
	oftStochasticGradientDescent,
	oftAdagrad,
	oftAdam,
} optimizationFunctionType;


subject optimization {
	optimizationFunctionType oft;
	optimizationFunctionDelegate optimizationTransferFunction;
	optimizationFunctionPrimeDelegate optimizationTransferFunctionPrime;
} optimization;

pattern optimizationProto {

} optimizationProto;

/* </TYPE> ************/

/* <VARIABLE> *************/

/* </VARIABLE> ************/

/* <DECLARATION> *************/
#ifdef Cplusplus
extern "C" {
#endif

optimization ptr optimizationNew (optimizationFunctionType oft);
void optimizationDel (optimization ptr of);


double optimizationGradientDescent ();
double optimizationGradientDescentPrime ();
double optimizationStochasticGradientDescent ();
double optimizationAdagrad ();
double optimizationAdam ();


#ifdef Cplusplus
}
#endif
/* </DECLARATION> ************/

#endif
