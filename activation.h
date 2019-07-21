#ifndef AIFI__ACTIVATION
#define AIFI__ACTIVATION

// <INCLUDE> //
#include "popc.h"

// </INCLUDE> //

// <DEFINE> //
//#define REQUIRED STUFFS HERE
// </DEFINE> //

// -- V2 -- //

delegation double (fnPtr activationTransferDelegate) (double x);
delegation double (fnPtr activationTransferPrimeDelegate) (double x);

enumeration activationFunctionType {
	aftNone,
	aftIdentity,
	aftBinary,
	aftLogisticSigmoid,								// Logistic
	aftBipolarSigmoid,								// Bipolar Sigmoid
	aftArcTan, 												// Arc Tangent
	aftHyperbolicTan, 								// Hyperbolic Tangent
	aftExponentialLinerUnit, 					// Exponential Linear Unit
	aftRectifiedLinerUnit, 						// Rectified Linear Unit
	aftLeakyRectifiedLinerUnit, 			// Leakey Rectified Linear Unit
	aftParametricRectifiedLinerUnit,	// Parametric Rectified Linear Unit
	aftSoftMax
} activationFunctionType;

subject activation {
	activationFunctionType aft;
	activationTransferDelegate activationTransferFunction;
	activationTransferPrimeDelegate activationTransferFunctionPrime;
} activation;


pattern activationProto activationProto;
pattern activationProto {
	activation ptr (fnPtr activationNew) (activationFunctionType aft);
	void (fnPtr activationDel) ();
	
	double (fnPtr sigmoid) (double x);
	double (fnPtr sigmoidPrime) (double x);
	double (fnPtr transfer) (double x);
	double (fnPtr transferPrime) (double x);
	void (fnPtr setActivationFunctionType) (activationFunctionType aft);	
} activationProto;


#ifdef Cplusplus
extern "C" {
#endif

activationProto ptr activationProtoNew ();

activation ptr activationNew (activationFunctionType aft);
void activationDel (activation ptr);

 double activationBipolarSigmoid (double x);

 double activationBipolarSigmoidPrime (double x);

 double activationLogisticSigmoid (double x);

 double activationLogisticSigmoidPrime (double x);


 double activationHyperbolicTan (double x);

 double activationHyperbolicTanPrime (double x);


 double activationRectifiedLinearUnit (double x);

 double activationRectifiedLinearUnitPrime (double x);


 double activationTransfer (activation ptr act, double x);

 double activationTransferPrime (activation ptr act, double x);

void activationSetFunctionType (activation ptr act, activationFunctionType aft);

	
#ifdef Cplusplus
}
#endif
#endif
