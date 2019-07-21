#ifndef AIFI__CELL
#define AIFI__CELL

/* <INCLUDE> *************/
#include "popc.h"
#include "activation.h"
#include "loss.h"
#include "optimization.h"

/* </INCLUDE> ************/

/* <DEFINE> *************/
//#define REQUIRED STUFFS HERE
/* </DEFINE> ************/

/* <CONST> *************/
//#define REQUIRED STUFFS HERE
/* </CONST> ************/

/* <TYPE> *************/

enumeration cellType {
	ctInput,
	ctHidden,
	ctOutput,

	ctConvolutional,
	ctInputBackfed,
	ctInputNoisy,
	ctGenerativeAdversarial,
	ctHiddenProbabilistic,
	ctHiddenSpiking,
	ctKernel,
	ctMatchInputOutput,
	ctMemory,
	ctMemoryDifferent,
	ctMemoryLongShortTerm,
	ctMemoryLongTerm,
	ctMemoryShortTerm,
	ctRecurrent,
} cellType;

// <BASIC CELL COMPONENTS>
typedef int 					cellConnectionCount;
typedef double 				cellInput;
typedef double 				cellWeight;
typedef double 				cellOutput;
typedef double 				cellTarget;
typedef double 				cellError;
typedef double 				cellDeltaError;
typedef double 				cellBias;
typedef double 				cellDeltaBias;
// </BASIC CELL COMPONENTS>

// <BASIC CELL>
subject cell {
	cellConnectionCount connectionCount;
	cellInput ptr inputt1d;
	cellWeight ptr weight1d;
	cellOutput output;
	cellTarget target;
	cellError error;
	cellDeltaError deltaErrorGradient;
	cellBias bias;
	cellDeltaBias deltaBias;
	activation actFn;
	loss lossFn;
	optimization optFn;
} cell;
// </BASIC CELL>

// <INPUT CELL>
subject inputCell {
	cellInput input;
	cellOutput output;
} inputCell;

// </INPUT CELL>

// <HIDDEN CELL>
subject hiddenCell {
	cellConnectionCount connectionCount;
	cellInput ptr inputt1d;
	cellWeight ptr weight1d;
	cellOutput output;
	cellError error;
	cellDeltaError deltaErrorGradient;
	cellBias bias;
	cellDeltaBias deltaBias;
	activation actFn;
	loss lossFn;
	optimization optFn;
} hiddenCell;

// </HIDDEN CELL>

// <OUTPUT CELL>
subject outputCell {
	cellConnectionCount connectionCount;
	cellInput ptr inputt1d;
	cellWeight ptr weight1d;
	cellTarget Target;
	cellOutput output;
	cellError error;
	cellDeltaError deltaErrorGradient;
	cellBias bias;
	cellDeltaBias deltaBias;
	activation actFn;
	loss lossFn;
	optimization optFn;
} outputCell;

// </OUTPUT CELL>

pattern cellProto {
	cell ptr (fnPtr cellNew) ();
	void (fnPtr cellDel) (cell ptr c);
} cellProto;

/* </TYPE> ************/

/* <VARIABLE> *************/

/* </VARIABLE> ************/

/* <DECLARATION> *************/
#ifdef Cplusplus
extern "C" {
#endif



#ifdef Cplusplus
}
#endif
/* </DECLARATION> ************/

#endif
