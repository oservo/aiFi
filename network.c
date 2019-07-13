#include <stdio.h>
#include <stdlib.h>

#include "popc.h"
#include "dbc.h"

#include "activation.h"
#include "axon.h"
#include "dendrite.h"
#include "neuron.h"
#include "layer.h"
#include "network.h"
#include "linkedList.h"

property networkProperty {

} networkProperty;

networkProperty np;

// -- V2/ ------------------------------------------------------------------------------------------------------ //
networkProto ptr networkProtoInstance () {
	static networkProto ptr np = NULL;
		
		if (np == NULL) {
			np = (networkProto ptr) malloc (sizeof (networkProto));
			dbcEnsure (np != NULL, "Memory Allocation Error");

			np -> ProtoInstance 							= networkProtoInstance;
			np -> construct 									= networkConstruct;
			np -> destruct 										= networkDestruct;
			np -> randomizer 									= networkRandomizer;
			//del np -> makeConnections 			= networkMakeConnections;
			np -> addLayer 										= networkAddLayer;
			np -> train 											= networkTrain;
			np -> predict 										= networkPredict;
			np -> setInput 										= networkSetInput;
			np -> setOutputTarget 						= networkSetOutputTarget;
			np -> propagateForward 						= networkPropagateForward;
			np -> propagateBackward 					= networkPropagateBackward;
			//del np -> constructArchitecture = networkConstructArchitecture;
			//del np -> getRandomInputs 			= networkGetRandomInputs;
			np -> randomizer 									= networkRandomizer;
		}
		return np;
	} 

network ptr networkConstruct () {
  network ptr nw = (network ptr) malloc (sizeof (network));
	dbcEnsure (nw != NULL, "Memory Allocation Error");

  //nw -> inputLayer = NULL;
  //nw -> outputLayer = NULL;
	nw -> layerLinkedList = linkedListConstruct ();
  return nw;
}


void networkDestruct (network ptr nw) {
  // FACT: INCOMPLETE!
	linkedListDestruct (nw -> layerLinkedList);
	free (nw);
	nw = NULL;
}

void networkAddLayer (network ptr nw, int neuronPlaneCount, int neuronRowCount, int neuronColumnCount, activationTransferType att) {
	int index = 0, dpc, drc, dcc;
	layer ptr currentLayer;
	linkedListNode ptr tmpLayerNode;

	currentLayer = layerConstruct (neuronPlaneCount, neuronRowCount, neuronColumnCount, att);
	tmpLayerNode = linkedListInsertNode (nw -> layerLinkedList, currentLayer);

	index = 0;
	for (int p  = 0; p < neuronPlaneCount ; p++) {
		for (int r = 0; r < neuronRowCount; r++) {
			for (int c = 0; c < neuronColumnCount; c++) {
				if (tmpLayerNode -> previous != NULL) {
					dpc = ((layer ptr) tmpLayerNode -> previous -> object) -> neuronPlaneCount;  
					drc = ((layer ptr) tmpLayerNode -> previous -> object) -> neuronRowCount;  
					dcc = ((layer ptr) tmpLayerNode -> previous -> object) -> neuronColumnCount;  
				}
				else {
					dpc = 1;  
					drc = 1;  
					dcc = 1;  
				}
				//index ++ IS EVEN SIMPLER! index = (p * neuronRowCount * neuronColumnCount) + (r * neuronColumnCount) + c; 

				((neuron ptr) currentLayer -> neuronLinearVector[index]) -> dendritePlaneCount = dpc;  
				currentLayer -> neuronLinearVector[index] -> dendriteRowCount = drc;  
				currentLayer -> neuronLinearVector[index] -> dendriteColumnCount = dcc;  
				currentLayer -> neuronLinearVector[index] -> dendriteTotalCount = dpc * drc * dcc;  
			  currentLayer -> neuronLinearVector[index] -> dendriteLinearVector = (dendrite ptr2d) malloc ((dpc * drc * dcc) * sizeof (dendrite ptr));
				dbcEnsure (currentLayer -> neuronLinearVector[index] -> dendriteLinearVector != NULL, "Memory Allocation Error");

				//dendrites
				for (int i = 0; i < dpc * drc * dcc; i++)
					((neuron ptr) currentLayer -> neuronLinearVector[index]) -> dendriteLinearVector[i] = dendriteConstruct (0.0, networkRandomizer());

				//axon
				((neuron ptr) currentLayer -> neuronLinearVector[index]) -> axon = axonConstruct (0.0, 0.0);  

				index ++;
			}
		}
	}
}

// Propagation/
void networkPropagateForward (network ptr nw) {
	//PENDING
	//int index; 
	//double summation = 0;
	//layer ptr currentLayer = NULL; //, ptr previousLayer = NULL;

	linkedListNode ptr llNodeWalker = nw -> layerLinkedList -> head;
	while (llNodeWalker != NULL) {
		//currentLayer = (layer ptr) llNodeWalker -> object;
		layerPropagateForward (llNodeWalker);
		llNodeWalker = llNodeWalker -> next;
	}
}

// Back Propagation/
void networkPropagateBackward (network ptr nw, double learningRate, double learningMomentumRate) {
	linkedListNode ptr currentLayerNode;
	//layer ptr currentLayer, ptr nextLayer, ptr previousLayer;

	currentLayerNode = nw -> layerLinkedList -> tail;
	while (currentLayerNode != nw -> layerLinkedList -> head) {
		//currentLayer = (layer ptr) currentLayerNode -> object;
		layerPropagateBackward (currentLayerNode, learningRate, learningMomentumRate);
		currentLayerNode = currentLayerNode -> previous;
	}

}


void networkTrain (network ptr nw, double ptr inputMatrix, double ptr outputTargetMatrix, double learningRate, double learningMomentumRate) {
	networkSetInput (nw, inputMatrix);
	networkSetOutputTarget (nw, outputTargetMatrix);

  networkPropagateForward (nw);
  networkPropagateBackward (nw, learningRate, learningMomentumRate);
}

void networkPredict (network ptr nw, double ptr inputMatrix) {
	networkSetInput (nw, inputMatrix);

  networkPropagateForward (nw);
}

void networkSetInput (network ptr nw, double ptr inputMatrix) {
	int index = 0;

	layer ptr inputLayer = (layer ptr) nw -> layerLinkedList -> head -> object;
	for (int p  = 0; p < inputLayer -> neuronPlaneCount ; p++){
		for (int r = 0; r < inputLayer -> neuronRowCount; r++){
			for (int c = 0; c < inputLayer -> neuronColumnCount; c++){
				//index ++ is simpler! index = (p * inputLayer -> neuronRowCount * inputLayer -> neuronColumnCount) + (r * inputLayer -> neuronColumnCount) + c; 

				((neuron ptr) inputLayer -> neuronLinearVector[index]) -> dendriteLinearVector[0] -> input = inputMatrix[index];
				index ++;
			}
		}
	}
}

void networkSetOutputTarget (network ptr nw, double ptr outputTargetMatrix) {
	int index = 0;

	layer ptr outputLayer = (layer ptr) nw -> layerLinkedList -> tail -> object;
	for (int p  = 0; p < outputLayer -> neuronPlaneCount ; p++){
		for (int r = 0; r < outputLayer -> neuronRowCount; r++){
			for (int c = 0; c < outputLayer -> neuronColumnCount; c++){
				//index ++ is simpler! index = (p * outputLayer -> neuronRowCount * outputLayer -> neuronColumnCount) + (r * outputLayer -> neuronColumnCount) + c; 
				outputLayer -> neuronLinearVector[index] -> axon -> target = outputTargetMatrix[index];
				index ++;
			}
		}
	}	
}

double networkRandomizer () {
  return rand () % 1000000 / 999998.0 + 0.000001;
}

