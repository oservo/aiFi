#ifndef PANN__LOSS
#define PANN__LOSS

// [INCLUDE] //
#include "popc.h"
// [/INCLUDE] //

// [DEFINE] //
//#define REQUIRED STUFFS HERE
// [/DEFINE] //

// [TYPE] //
subject loss{

} loss;


prototype lossProto{

} lossProto;

// [/TYPE] //

// [DECLARATION] //

#ifdef Cplusplus
extern "C" {
#endif

double quadraticMeanSquaredError (double t, double o);
double meanSquaredLogarithmicError (double t, double o);
double l2 (double t, double o);
double l1 (double t, double o);
double meanAbsoluteError (double t, double o);
double meanAbsolutePercentageError (double t, double o);
double relativeEntropy (double t, double o);
double crossEntropy (double t, double o);
double kullbackLeiblerDivergence (double t, double o);
double negativeLogarithmicLikelihood (double t, double o);
double poisson (double t, double o);
double cosineProximity (double t, double o);
double hinge (double t, double o);
double squaredHinge (double t, double o);

double l1 (double t, double o);


#ifdef Cplusplus
}
#endif

// [/DECLARATION] //

#endif
