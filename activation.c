/* 
	NOTES
	https://en.wikipedia.org/wiki/Activation_function
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "popc.h"
#include "dbc.h"

#include "activation.h"


property activationProperty {
	activationTransferType att;

} activationProperty;

/*
activationProperty ap = {
  attLogisticSigmoid 
};
*/

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

double activationIdentityDerivative (double x) {
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
double activationBinaryDerivative (double x) {
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
double activationLogisticSigmoidDerivative (double x) {
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
double activationBipolarSigmoidDerivative (double x) {
  return (1/2) * (1 + activationBipolarSigmoid (x)) * (1 - activationBipolarSigmoid (x));
}
*/

/*
	Formula:
	Returns: 
*/
double activationHyperbolicTan (double x) {
  return tanh (x);
}

/*
	Formula:
	Returns: 
*/
double activationHyperbolicTanDerivative (double x) {
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
double activationArcTanDerivative (double x) {
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
double activationRectifiedLinerUnitDerivative (double x) {
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
double activationLeakyRectifiedLinerUnitDerivative (double x) {
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
double activationParametricRectifiedLinerUnitDerivative (double x) {
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
double activationExponentialLinerUnitDerivative (double x) {
  return 1 - pow(x, 2);
}
*/

double activationTransfer (activation ptr act, double x) {
  return act -> activationTransferFunction (x);
}

double activationTransferDerivative (activation ptr act, double x) {
  return act -> activationTransferFunctionDerivative (x);
}


/* IMPLEMENTATION PENDING
activationProto ptr activationProtoInstance () {
	static activationProto ptr this = NULL;
	
	// TODO lock() immediately here (before the following block)
	if (this == NULL) {
		this = malloc (sizeof (activationProto));

		this -> ctor					= activationCtor;

		this -> sigmoid				 = activationSigmoid;
		this -> sigmoidDerivative	   = activationSigmoidDerivative;
		this -> perform				 = activationPerform;
		this -> performDerivative	   = activationPerformDerivative;
	}
	// TODO unlock() immediately here (after the above block)


	return this;
}
*/

activation ptr activationConstruct (activationTransferType att) {
	activation ptr act = (activation ptr) malloc ( sizeof (activation));
	dbcEnsure (act != NULL, "Memory Allocation Error");
		
	act -> att = att;
  switch (att) {
		case attLogisticSigmoid:
			act -> activationTransferFunction = activationLogisticSigmoid;
			act -> activationTransferFunctionDerivative = activationLogisticSigmoidDerivative;
			break;
	
		/*	PENDING
		case attBipolarSigmoid:
			act -> activationTransferFunction = activationBipolarSigmoid;
			act -> activationTransferFunction = activationBipolarSigmoidDerivative;
			break;
		*/

		case attHyperbolicTan:
			act -> activationTransferFunction = activationHyperbolicTan;
			act -> activationTransferFunction = activationHyperbolicTanDerivative;
			break;

		default:
			dbcRequire (false, "Unknown actionvation function request.");
  }
	return act;
}

void activationDestruct (activation ptr act) {
	free (act);
}
