#ifndef PANN__NEURON
#define PANN__NEURON

// [INCLUDE] //
#include "popc.h"

#include "linkedList.h"
#include "activation.h"
#include "dendrite.h"
#include "layer.h"
// [/INCLUDE] //

// [DEFINE] //
//#define REQUIRED STUFFS HERE
// [/DEFINE] //

// -- V2 -- //
subject dendrite dendrite; //FD!
subject axon axon; //FD!

subject neuron {
	int dendritePlaneCount;
	int dendriteRowCount;
	int dendriteColumnCount;
	int dendriteTotalCount;
	dendrite ptr2d dendriteLinearVector;
	axon ptr axon;
	activation ptr act;

	double error;
	double deltaError;

	double bias;
	double biasDelta;
} neuron;

prototype neuronProto neuronProto; //FD!

prototype neuronProto {
  neuronProto ptr (fnPtr ProtoInstance) ();
  neuron ptr (fnPtr construct) ();
  void (fnPtr destruct) (neuron ptr neuron);
} neuronProto;

/* [DECLARATION] ************************/

#ifdef Cplusplus
extern "C" {
#endif
// -- V2/ ------------------------------------------------------------------------------------------------------ //

neuronProto ptr	neuronProtoInstance ();

neuron ptr 					neuronConstruct ();
void 								neuronDestruct (neuron ptr n);
void 								neuronPropagateForward (neuron ptr n, linkedListNode ptr layerNode);
double 							neuronCalculateDeltaError (neuron ptr n, linkedListNode ptr currentLayerNode);
void 								neuronLearnFromDeltaError (neuron ptr n, linkedListNode ptr currentLayerNode, double learningRate, double learningMomentumRate);

#ifdef Cplusplus
}
#endif

/* [/DECLARATION] ************************/

#endif
