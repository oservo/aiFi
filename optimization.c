#include "popc.h"
#include "optimization.h"

optimization ptr optimizationNew (optimizationFunctionType oft) {
	optimization ptr of = (optimization ptr) malloc ( sizeof (optimization));
	dbcEnsure (of != NULL, "Memory Allocation Error!");
		
	of -> oft = oft;
  switch (oft) {
		case oftGradientDescent:
			of -> optimizationTransferFunction = optimizationGradientDescent;
			of -> optimizationTransferFunctionPrime = optimizationGradientDescentPrime;
			break;
		/* PENDING
		case oftStochasticGradientDescent:
			of -> optimizationTransferFunction = optimizationStochasticGradientDescent;
			of -> optimizationTransferFunctionPrime = optimizationStochasticGradientDescentPrime;
			break;
		*/	
		default:
			dbcRequire (false, "Unknown actionvation function request.");
  }
	return of;
}

void optimizationDel (optimization ptr of) {
	free (of);
}

double optimizationGradientDescent () {
	//PENDING
	return 0.0;
}

double optimizationGradientDescentPrime () {
	//PENDING
	return 0.0;
}

double optimizationStochasticGradientDescent () {
	//PENDING
	return 0.0;
}

double optimizationStochasticGradientDescentPrime () {
	//PENDING
	return 0.0;
}
