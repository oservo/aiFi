#ifndef PANN__LAYER
#define PANN__LAYER

// [INCLUDE] //
#include "popc.h"

#include "neuron.h"
#include "activation.h"
#include "linkedList.h"
// [/INCLUDE] //

// [DEFINE] //
//#define REQUIRED STUFFS HERE
// [/DEFINE] //

// -- V2 -- //
enumeration layerType {
	ltInput,
	ltHidden,
	ltOutput,
} layerType;

subject neuron neuron; //FD!

subject layer {
	int neuronPlaneCount;
  int neuronRowCount;
  int neuronColumnCount;
	int neuronTotalCount;
  neuron ptr2d neuronLinearVector;

	//NOT_HERE! double bias; 
	//NOT_HERE! double biasDelta;
  activationTransferType att;

	double aggregateError;
	double aggregateDeltaError;
} layer;

prototype layerProto layerProto;
prototype layerProto {
  layerProto ptr (fnPtr ProtoInstance) ();

  layer ptr 								(fnPtr construct) (int neuronsInLayer);
  void 											(fnPtr destruct) (layer ptr l);

  void 											(fnPtr setOutputs) (layer  ptr l, double ptr inputs);
  void 											(fnPtr setErrors) (layer ptr l, double ptr target);
} layerProto;

#ifdef Cplusplus
extern "C" {
#endif



// -- V2/ ------------------------------------------------------------------------------------------------------ //

layerProto ptr	layerProtoInstance ();
layer ptr 					layerConstruct (int neuronPlaneCount, int neuronRowCount, int neuronColumnCount, activationTransferType att);
void								layerDestruct (layer ptr l);

void 								layerCalculateDeltaError (linkedListNode ptr layerNode);
void 								layerLearnFromDeltaError (linkedListNode ptr layerNode, double learningRate, double learningMomentumRate);
void 								layerSetOutputs (layer ptr l, double ptr inputs);
void 								layerSetErrors (layer ptr l, double ptr target);

void 								layerPropagateForward (linkedListNode ptr currentLayerNode);
void 								layerPropagateBackward (linkedListNode ptr currentLayerNode, double learningRate, double learningMomentumRate);
layerType 					layerGetType (linkedListNode ptr currentLayerNode);
	
#ifdef Cplusplus
}
#endif
#endif


