#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "popc.h"
#include "dbc.h"

#include "activation.h"
#include "neuron.h"
#include "network.h"

#include "layer.h"

property layerProperty {

} layerProperty;

// -- V2/ ------------------------------------------------------------------------------------------------------ //

/* PENDING
layerProto ptr	layerProtoInstance () {
	static layerProto ptr this = NULL;
	
	// TODO lock() immediately here (before the following block)
	if (this == NULL) {
		this = malloc (sizeof (layerProto));

		this -> ProtoInstance			= layerProtoInstance;

		this -> construct				= layerConstruct;
		this -> destruct				= layerDestruct;

		this -> setOutputs			= layerSetOutputs;
		this -> setErrors			  = layerSetErrors;
	}
	// TODO unlock() immediately here (after the above block)


	return this;
}
*/

layer ptr layerConstruct (int neuronPlaneCount, int neuronRowCount, int neuronColumnCount, activationTransferType att) {
	int neuronTotalCount;
	
	neuronPlaneCount = neuronPlaneCount <= 0 ? 1 : neuronPlaneCount;
	neuronRowCount = neuronRowCount <= 0 ? 1 : neuronRowCount;
	neuronColumnCount = neuronColumnCount <= 0 ? 1 : neuronColumnCount;
  neuronTotalCount = neuronPlaneCount * neuronRowCount * neuronColumnCount;
	
	layer ptr tempLayer = (layer ptr) malloc (sizeof (layer));
	dbcEnsure (tempLayer != NULL, "Memory Allocation Error");
		
  tempLayer -> neuronPlaneCount  = neuronPlaneCount;
  tempLayer -> neuronRowCount = neuronRowCount;
  tempLayer -> neuronColumnCount = neuronColumnCount;
	tempLayer -> neuronTotalCount = neuronTotalCount;
  tempLayer -> neuronLinearVector = (neuron ptr2d ) malloc (neuronTotalCount * sizeof (neuron ptr));
	dbcEnsure (tempLayer -> neuronLinearVector != NULL, "Memory Allocation Error");
	tempLayer -> att = att;
  for (int i = 0; i < neuronTotalCount; i++)
		tempLayer -> neuronLinearVector[i] = neuronConstruct (att)
	;
  return tempLayer;
}

void layerDestruct (layer ptr l) {
	free (l);
}

void layerPropagateBackward (linkedListNode ptr currentLayerNode, double learningRate, double learningMomentumRate) {
		layerCalculateDeltaError (currentLayerNode);
		layerLearnFromDeltaError (currentLayerNode, learningRate, learningMomentumRate);
}

void layerCalculateDeltaError (linkedListNode ptr layerNode) {
	layer ptr l = (layer ptr) layerNode -> object;

	l -> aggregateError = 0;
	l -> aggregateDeltaError = 0;

	for (int i = 0; i < l -> neuronTotalCount; i++) {
		neuronCalculateDeltaError (l -> neuronLinearVector[i], layerNode);
	}
}

void layerLearnFromDeltaError (linkedListNode ptr layerNode, double learningRate, double learningMomentumRate) {
	layer ptr l = (layer ptr) layerNode -> object;
	for (int i = 0; i < l -> neuronTotalCount; i++) {
		neuronLearnFromDeltaError (l -> neuronLinearVector[i], layerNode, learningRate, learningMomentumRate);
	}
}

/* NO NEED
void layerSetInput (layer ptr l, double ptr3d inputMatrix) {
  int temp = 0;
  while (temp != (l -> neuronTotalCount)) {
		(l -> outputMatrix)[temp] = inputs[temp];
		temp++;
  }
}

void layerProcessInput (layer ptr l) {
  int temp = 0;
  while (temp != (l -> neuronTotalCount)) {
		(l -> outputMatrix)[temp] = inputs[temp];
		temp++;
  }
}

void layerGetOutput (layer ptr n) {

}
*/

void layerPropagateForward (linkedListNode ptr currentLayerNode) {
	layer ptr currentLayer;
	int index;
	neuron ptr currentNeuron;

	currentLayer = (layer ptr) currentLayerNode -> object;

	index = 0;
	for (int p  = 0; p < currentLayer -> neuronPlaneCount ; p++){
		for (int r = 0; r < currentLayer -> neuronRowCount; r++){
			for (int c = 0; c < currentLayer -> neuronColumnCount; c++){
				//index ++ is simpler! index = (p * currentLayer -> neuronRowCount * currentLayer -> neuronColumnCount) + (r * currentLayer -> neuronColumnCount) + c; 
				//MIGHT NEED FIXING:
				currentNeuron = (neuron ptr) currentLayer -> neuronLinearVector[index];
				neuronPropagateForward (currentNeuron, currentLayerNode);

				index ++;
			}
		}
	}
}

layerType layerGetType (linkedListNode ptr currentLayerNode) {
	layerType lt;
	if (currentLayerNode -> next == NULL) {
		lt = ltOutput;
	}
	else if (currentLayerNode -> previous == NULL) {
		lt = ltInput;
	}
	else if (currentLayerNode -> next != NULL && currentLayerNode -> previous != NULL) {
		lt = ltHidden;
	}
	return lt;
}


/*
void layerSetError (layer ptr l, double ptr3d outputMatrix) {
  int temp = 0;
  while (temp != (l -> neuronTotalCount)) {
		(l -> errorMatrix)[temp] = 0.5 * pow ((target[temp] - (l -> outputMatrix)[temp]) , 2);
		temp++;
  }
}

void layerTrain (layer ptr l, double ptr3d inputMatrix, double ptr3d outputMatrix) {
	//PENDING
	
}

void layerInitialize () {
	//x

}
*/
