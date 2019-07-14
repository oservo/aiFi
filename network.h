#ifndef AIFI__NETWORK
#define AIFI__NETWORK

// [INCLUDE] //
#include "popc.h"

#include "layer.h"
#include "axon.h"
#include "dendrite.h"
#include "linkedList.h"
// [/INCLUDE] //

// [DEFINE] //
#define LEARNING_RATE	0.05
#define LEARNING_MOMENTUM_RATE	1
#define SHOW_STATS	1
// [/DEFINE] //



// -- V2/ ------------------------------------------------------------------------------------------------------ //

enumeration {
	/* 
	networkAdaline,
	networkHopfield,
	*/
	networkMlp,
	networkRnn,
	networkCnn,
	networkLstm
} networkType;

subject network {
	linkedList ptr layerLinkedList;
	//int epochMax;
	//int epochTally;

	double aggregateError;
	double aggregateDeltaError;

	//double bias;
	//double biasDelta;

	//TODO: needs immediate implementation/
	//double learningRate;
	//double learningMomentumRate;
	//not this way: double meanSquareError;
	//not this way: double rootMeanSquareError;
	
} network;

prototype networkProto networkProto; //FD!

prototype networkProto {
networkProto ptr	(fnPtr ProtoInstance) ();
network ptr						(fnPtr construct) ();
void									(fnPtr destruct) (network ptr network);

void 									(fnPtr makeConnections) (layer ptr fromLayer, layer ptr toLayer);
void 									(fnPtr addLayer) (network ptr network, int neuronPlaneCount, int neuronRowCount, int neuronColumnCount, activationTransferType att);
void 									(fnPtr train) (network ptr nw, double ptr inputMatrix, double ptr outputTargetMatrix, double learningRate, double learningMomentumRate);
void 									(fnPtr predict) (network ptr nw, double ptr inputMatrix);
void 									(fnPtr setInput) (network ptr nw, double ptr inputMatrix);
void									(fnPtr setOutputTarget) (network ptr nw, double ptr outputTargetMatrix);
void 									(fnPtr propagateForward) (network ptr nw);
void 									(fnPtr propagateBackward) (network ptr nw, double learningRate, double learningMomentumRate);
void 									(fnPtr constructArchitecture) (network ptr network, int inputLayers, int hiddenLayers, int outputLayers);
double ptr 						(fnPtr getRandomInputs) (network ptr network);
double 								(fnPtr randomizer) ();
} networkProto;

#ifdef Cplusplus
extern "C" {
#endif

networkProto ptr	networkProtoInstance ();
network ptr						networkConstruct ();
void									networkDestruct (network ptr network);

//del void 									networkMakeConnections (layer ptr fromLayer, layer ptr toLayer);
void 									networkAddLayer (network ptr network, int neuronPlaneCount, int neuronRowCount, int neuronColumnCount, activationTransferType att);
void 									networkTrain (network ptr nw, double ptr inputMatrix, double ptr outputTargetMatrix, double learningRate, double learningMomentumRate);
void 									networkPredict (network ptr nw, double ptr inputMatrix);
void 									networkSetInput (network ptr nw, double ptr inputMatrix);
void									networkSetOutputTarget (network ptr nw, double ptr outputTargetMatrix);
void 									networkPropagateForward (network ptr nw);
void 									networkPropagateBackward (network ptr nw, double learningRate, double learningMomentumRate);
//del void 									networkConstructArchitecture (network ptr network, int inputLayers, int hiddenLayers, int outputLayers);
//del double ptr 						networkGetRandomInputs (network ptr network);
double 								networkRandomizer ();



#ifdef Cplusplus
}
#endif
#endif

