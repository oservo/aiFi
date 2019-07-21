#ifndef AIFI__LOSS
#define AIFI__LOSS

// <INCLUDE> //
#include "popc.h"
// </INCLUDE> //

// <DEFINE> //
//#define REQUIRED STUFFS HERE
// </DEFINE> //

delegation double (fnPtr lossFunctionDelegate) (double t, double o);
delegation double (fnPtr lossFunctionPrimeDelegate) (double t, double o);

// <TYPE> //
enumeration lossFunctionType {
	lftQuadraticMeanSquaredError,
	lftMeanSquaredLogarithmicError,
	lftActualError,
	lftL1,
	lftL2,
	lftMeanAbsoluteError,
	lftMeanAbsolutePercentageError,
	lftRelativeEntropy,
	lftCrossEntropy,
	lftKullbackLeiblerDivergence,
	lftNegativeLogarithmicLikelihood,
	lftPoisson,
	lftCosineProximity,
	lftHinge,
	lftSquaredHinge,
} lossFunctionType;

subject loss{
	lossFunctionType lft;
	lossFunctionDelegate lossTransferFunction;
	lossFunctionPrimeDelegate lossTransferFunctionPrime;
} loss;


pattern lossProto {

} lossProto;

// </TYPE> //

// <DECLARATION> //

#ifdef Cplusplus
extern "C" {
#endif
loss ptr lossNew (lossFunctionType lft);
void lossDel (loss ptr act);

double lossQuadraticMeanSquaredError (double t, double o);
double lossMeanSquaredLogarithmicError (double t, double o);
double lossL1 (double t, double o);
double lossL2 (double t, double o);
double lossActualError (double t, double o);
double lossActualErrorPrime (double t, double o);
double lossMeanAbsoluteError (double t, double o);
double lossMeanAbsoluteErrorPrime (double t, double o);
double lossMeanAbsolutePercentageError (double t, double o);
double lossRelativeEntropy (double t, double o);
double lossCrossEntropy (double t, double o);
double lossKullbackLeiblerDivergence (double t, double o);
double lossNegativeLogarithmicLikelihood (double t, double o);
double lossPoisson (double t, double o);
double lossCosineProximity (double t, double o);
double lossHinge (double t, double o);
double lossSquaredHinge (double t, double o);


#ifdef Cplusplus
}
#endif

// </DECLARATION> //

#endif
