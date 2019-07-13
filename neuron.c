#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "popc.h"
#include "dbc.h"



#include "activation.h"
#include "axon.h"
#include "dendrite.h"
#include "neuron.h"
#include "layer.h"
#include "network.h"
#include "linkedList.h"

property neuronProperty {

} neuronProperty;

// -- V2/ ------------------------------------------------------------------------------------------------------ //

neuron ptr neuronConstruct (activationTransferType att) {
	neuron ptr n = (neuron ptr) malloc (sizeof (neuron));
	dbcEnsure (n != NULL, "Memory Allocation Error");

	n -> dendriteTotalCount = 0;
	n -> dendriteLinearVector = NULL; // to be allocated through networkAddLayer ()
	n -> axon = axonConstruct ();
	n -> act = activationConstruct (att);
	n -> act -> att = att;
	
	n -> bias = networkRandomizer ();
	return n;
}

/* PENDING 
*/
void neuronDestruct (neuron ptr neuron) {
	free (neuron);
}

neuronProto ptr neuronProtoInstance () {
	
	static neuronProto ptr this = NULL;
	
	// TODO lock() immediately here (before the following block) //
	if (this == NULL) {
		this = (neuronProto ptr) malloc (sizeof (neuronProto));
		dbcEnsure (this != NULL, "Memory Allocation Error");

		this -> ProtoInstance					= neuronProtoInstance;

		this -> construct						= neuronConstruct;
		this -> destruct						= neuronDestruct;
	}
	// TODO unlock() immediately here (after the above block) //

	return this;
}

void neuronPropagateForward (neuron ptr n, linkedListNode ptr layerNode) {
	double activationSum = 0;
	layer /* ptr currentLayer, */ ptr previousLayer; //, ptr nextLayer;

	//currentLayer = (layer ptr) layerNode -> object;

	// FIRST LAYER NEURON/
	if (layerNode -> previous == NULL) {
		n -> axon -> output = n -> dendriteLinearVector[0] -> input;		
	}
	// SUBSEQUENT LAYER NEURON/
	else {
		// POST SYNAPTIC MESSAGE RECEPTION/ 
		previousLayer = (layer ptr) layerNode -> previous -> object;
		for (int i = 0; i < previousLayer -> neuronTotalCount; i++) {
			n -> dendriteLinearVector[i] -> input = previousLayer -> neuronLinearVector[i] -> axon -> output;
		}

		// STIMULUS/ 
		for (int i = 0; i < n -> dendriteTotalCount; i++) {
			activationSum +=  n -> dendriteLinearVector[i] -> input * n -> dendriteLinearVector[i] -> weight;
		}
		activationSum += n -> bias; //add bias

		// ACTION POTENTIAL/
		n -> axon -> output = activationTransfer (n -> act, activationSum);
	}
}

double neuronCalculateDeltaError (neuron ptr n, linkedListNode ptr currentLayerNode) {
	layer ptr currentLayer, ptr nextLayer = NULL;
	//double summation;
	
	currentLayer = (layer ptr) currentLayerNode -> object;

	//output layer
	if (layerGetType (currentLayerNode) == ltOutput) {
		n -> error = (n -> axon -> target - n -> axon -> output);
		n -> deltaError = n -> error * activationTransferDerivative (n -> act, n -> axon -> output);
		currentLayer -> aggregateError += abs (n -> error);
	}
	// hidden layer
	else if (layerGetType (currentLayerNode) == ltHidden) {
		nextLayer = (layer ptr) currentLayerNode -> next -> object;

 		// xnetworkPropagateBackward errors
		for (int i = 0; i < (currentLayer -> neuronTotalCount); i++) {
			currentLayer -> neuronLinearVector[i] -> deltaError = 0;

			//summation = 0;
			for (int j = 0; j < nextLayer -> neuronTotalCount; j++) {
				currentLayer -> neuronLinearVector[i] -> deltaError += 
					(nextLayer -> neuronLinearVector[j] -> dendriteLinearVector[i] -> weight) * 
					(nextLayer -> neuronLinearVector[j] -> deltaError)
				;
			}
      currentLayer -> neuronLinearVector[i] -> deltaError *= 
				(currentLayer -> neuronLinearVector[i] -> axon -> output) * 
				(1 - currentLayer -> neuronLinearVector[i] -> axon -> output)
			;
		}
	}
	// input layer
	else if (layerGetType (currentLayerNode) == ltInput) {
		//nothing to be be done here! Kept the block for brevity.		
	}

	return 0; //???? n -> error;
}

void neuronLearnFromDeltaError (neuron ptr n, linkedListNode ptr currentLayerNode, double learningRate, double learningMomentumRate) {
	layer ptr currentLayer;
	
	currentLayer = (layer ptr) currentLayerNode -> object;

	if (layerGetType (currentLayerNode) == ltInput) {
		//nothing to be be done here! Kept the block for brevity.		
	}
	else {
		for (int i = 0; i < (currentLayer -> neuronTotalCount); i++) {
			n = currentLayer -> neuronLinearVector[i];
			// update bias
			n -> bias += (learningRate * learningMomentumRate * 1 * n -> deltaError);

			// update weight
			for (int j = 0; j < n -> dendriteTotalCount; j++) {
				n -> dendriteLinearVector[j] -> weight += 
					learningRate * learningMomentumRate *  
					n -> deltaError * n -> dendriteLinearVector[j] -> input
				;
			}
		}
	}
}