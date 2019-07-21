/* 
	NOTES
	https://en.wikipedia.org/wiki/Activation_function
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "popc.h"


#include "activation.h"


//// V2 /////////////////////////////////////////////////////////////////////////////////////////////////

/*	PENDING!
	Formula: f(x) {return x}
	Returns:

double activationIdentity (double x) {
  return x;
}
*/

/*	PENDING!
	Formula:
	Returns: 

double activationIdentityPrime (double x) {
	// formula: f(x) {return 1}
	// returns: 1
  return x - x + 1;
}
*/

/*	PENDING!
	Formula:
	Returns:
double activationBinary (double x) {
  return 0;
}
*/

/*	PENDING!
	Formula:
	Returns: 
double activationBinaryPrime (double x) {
  return 0;
}
*/

/*
	Formula:
	Returns: 
*/
double activationLogisticSigmoid (double x) {
  return 1 / (1 + exp (-x));
}

/*
	Formula:
	Returns: 
*/
double activationLogisticSigmoidPrime (double x) {
  return activationLogisticSigmoid (x) * (1 - activationLogisticSigmoid (x));
}

/*	PENDING
	Formula:
	Returns: 
double activationBipolarSigmoid (double x) {
  return (2 / (1 + exp (-x))) - 1;
}
*/

/*	PENDING
	Formula:
	Returns: 
double activationBipolarSigmoidPrime (double x) {
  return (1/2) * (1 + activationBipolarSigmoid (x)) * (1 - activationBipolarSigmoid (x));
}
*/

/*
	Formula:
	Returns: 
*/
double activationHyperbolicTan (double x) {
	if (x < -20.0) {
		return -1.0; // approximation is correct to 30 decimals
	}
	else if (x > 20.0) {
		return 1.0;	
	}
	else {
		return tanh (x);
	}
}

/*
	Formula:
	Returns: 
*/
double activationHyperbolicTanPrime (double x) {
  return 1 - pow (activationHyperbolicTan (x), 2);
}

/*	PENDING
	Formula:
	Returns: 
double activationArcTan (double x) {
  return tanh (x);
}
*/

/*	PENDING
	Formula:
	Returns: 
double activationArcTanPrime (double x) {
  return 1 - pow(x, 2);
}
*/

/*
	Formula:
	Returns: 
*/
double activationRectifiedLinerUnit (double x) {
  return x <= 0 ? 0 : x;
}

/*
	Formula:
	Returns: 
*/
double activationRectifiedLinerUnitPrime (double x) {
  return x <= 0 ? 0 : 1;
}

/*
	Formula:
	Returns: 
*/
double activationLeakyRectifiedLinerUnit (double x) {
  return x <= 0 ? 0.01 * x : x;
}

/*
	Formula:
	Returns: 
*/
double activationLeakyRectifiedLinerUnitPrime (double x) {
  return x <= 0 ? 0.01 : 1;
}

/*	PENDING
	Formula:
	Returns: 
double activationParametricRectifiedLinerUnit (double x) {
  return tanh (x);
}
*/

/*	PENDING
	Formula:
	Returns: 
double activationParametricRectifiedLinerUnitPrime (double x) {
  return 1 - pow(x, 2);
}
*/

/*	PENDING
	Formula:
	Returns: 
double activationExponentialLinerUnit (double x) {
  return tanh (x);
}
*/

/*	PENDING
	Formula:
	Returns: 
double activationExponentialLinerUnitPrime (double x) {
  return 1 - pow(x, 2);
}
*/

 double activationTransfer (activation ptr act, double x) {
  return act -> activationTransferFunction (x);
}

 double activationTransferPrime (activation ptr act, double x) {
  return act -> activationTransferFunctionPrime (x);
}


/* IMPLEMENTATION PENDING
activationI ptr activationProtoNew () {
	static activationI ptr this = NULL;
	
	// TODO lock() immediately here (before the following block)
	if (this == NULL) {
		this = malloc (sizeof (activationI));

		this -> activationNew		= activationNew;

		this -> sigmoid				 = activationSigmoid;
		this -> sigmoidPrime	   = activationSigmoidPrime;
		this -> perform				 = activationPerform;
		this -> performPrime	   = activationPerformPrime;
	}
	// TODO unlock() immediately here (after the above block)


	return this;
}
*/

activation ptr activationNew (activationFunctionType aft) {
	activation ptr act = (activation ptr) malloc ( sizeof (activation));
	dbcEnsure (act != NULL, "Memory Allocation Error!");
		
	act -> aft = aft;
  switch (aft) {
		case aftLogisticSigmoid:
			act -> activationTransferFunction = activationLogisticSigmoid;
			act -> activationTransferFunctionPrime = activationLogisticSigmoidPrime;
			break;
	
		case aftHyperbolicTan:
			act -> activationTransferFunction = activationHyperbolicTan;
			act -> activationTransferFunctionPrime = activationHyperbolicTanPrime;
			break;

		/*	PENDING
		case aftRectifiedLinerUnit:
			act -> activationTransferFunction = activationRectifiedLinearUnit;
			act -> activationTransferFunctionPrime = activationRectifiedLinearUnitPrime;
			break;

		case attBipolarSigmoid:
			act -> activationTransferFunction = activationBipolarSigmoid;
			act -> activationTransferFunctionPrime = activationBipolarSigmoidPrime;
			break;
		*/

		case aftNone:
			act -> activationTransferFunction = NULL;
			act -> activationTransferFunctionPrime = NULL;
			break;
		default:
			dbcRequire (false, "Unknown actionvation function request.");
  }
	return act;
}

void activationDel (activation ptr act) {
	free (act);
}
