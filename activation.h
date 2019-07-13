#ifndef PANN__ACTIVATION
#define PANN__ACTIVATION

// [INCLUDE] //
#include "popc.h"

// [/INCLUDE] //

// [DEFINE] //
//#define REQUIRED STUFFS HERE
// [/DEFINE] //

// -- V2 -- //

delegation double (fnPtr activationTransferDelegate) (double x);
delegation double (fnPtr activationTransferDerivativeDelegate) (double x);

enumeration {
	attIdentity,
	attBinary,
	attLogisticSigmoid,								// Logistic
	attBipolarSigmoid,								// Bipolar Sigmoid
	attArcTan, 												// Arc Tangent
	attHyperbolicTan, 								// Hyperbolic Tangent
	attExponentialLinerUnit, 					// Exponential Linear Unit
	attRectifiedLinerUnit, 						// Rectified Linear Unit
	attLeakyRectifiedLinerUnit, 			// Leakey Rectified Linear Unit
	attParametricRectifiedLinerUnit,	// Parametric Rectified Linear Unit
	attSoftMax
} activationTransferType;

subject activation {
	activationTransferType att;
	activationTransferDelegate activationTransferFunction;
	activationTransferDerivativeDelegate activationTransferFunctionDerivative;
} activation;


prototype activationProto activationProto;

prototype activationProto {
	activationProto ptr (fnPtr protoInstance) ();
	
	double (fnPtr sigmoid) (double x);
	double (fnPtr sigmoidDerivative) (double x);
	double (fnPtr transfer) (double x);
	double (fnPtr transferDerivative) (double x);
	void (fnPtr setActivationType) (activationTransferType activationTransferType);	
} activationProto;

#ifdef Cplusplus
extern "C" {
#endif

activationProto ptr activationProtoInstance ();
activation ptr activationConstruct ();
void activationDestruct (activation ptr);

double activationBipolarSigmoid (double x);

double activationBipolarSigmoidDerivative (double x);

double activationLogisticSigmoid (double x);

double activationLogisticSigmoidDerivative (double x);


double activationHyperbolicTan (double x);

double activationHyperbolicTanDerivative (double x);


double activationRectifiedLinearUnit (double x);

double activationRectifiedLinearUnitDerivative (double x);


double activationTransfer (activation ptr act, double x);

double activationTransferDerivative (activation ptr act, double x);

void activationSetActivationTransferType (activation ptr act, activationTransferType att);

	
#ifdef Cplusplus
}
#endif
#endif
