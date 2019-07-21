#ifndef AIFI__LAYER
#define AIFI__LAYER

// <INCLUDE> //
#include "popc.h"

#include "cell.h"
#include "activation.h"
#include "loss.h"
#include "optimization.h"
// </INCLUDE> //

// <DEFINE> //
//#define REQUIRED STUFFS HERE
// </DEFINE> //

// -- V2 -- //
enumeration layerType {
	ltInput,
	ltHidden,
	ltOutput,
} layerType;


// <layer components>
typedef	int layerIndex;
typedef	int layerCellCount;
typedef	double layerError;
typedef	double layerDeltaError;
// </layer components>




#ifdef Cplusplus
extern "C" {
#endif



#ifdef Cplusplus
}
#endif
#endif


