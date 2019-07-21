#include "popc.h"
#include "loss.h"

loss ptr lossNew (lossFunctionType lft) {
	loss ptr lf = (loss ptr) malloc ( sizeof (loss));
	dbcEnsure (lf != NULL, "Memory Allocation Error!");
		
	lf -> lft = lft;
  switch (lft) {
		case lftActualError:
			lf -> lossTransferFunction = lossActualError;
			lf -> lossTransferFunctionPrime = lossActualErrorPrime;
			break;
	
		default:
			dbcRequire (false, "Unknown actionvation function parameter in lossNew ().");
  }
	return lf;
}

void lossDel (loss ptr lf) {
	free (lf);
}

double lossActualError (double t, double o) {
	return  (t - o);
}

double lossActualErrorPrime (double t, double o) {
	// PENDING
	dbcAssert (false, "[PENDING] Not Implemented");
	return 0 * t * o;
}

double lossMeanAbsoluteError (double t, double o) {
	// PENDING
	dbcAssert (false, "[PENDING] Not Implemented");
	return  (t - o);
}

double lossMeanAbsoluteErrorPrime (double t, double o) {
	// PENDING
	dbcAssert (false, "[PENDING] Not Implemented");
	return t - o;
}

