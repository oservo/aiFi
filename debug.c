#include <stdio.h>
#include <stdlib.h>

#include "popc.h"
#include "dbc.h"

#include "neuron.h"
#include "layer.h"
#include "network.h"

#include "debug.h"


property debugProperty {

} debugProperty;

/* IMPLEMENTATION PENDING
void debugDisplayWeightsForward (layer ptr tempLayer, neuron ptr tempNeuron) {
  if (tempNeuron -> weightsForward == NULL)
	return;
  for (int i = 0; i < tempLayer -> nextLayer -> neuronTotalCount; i++)
	printf ("%lf ", ptrVal ((tempNeuron -> weightsForward)[i] -> weight));
  printf ("\n");
}

void debugDisplayWeightsBackward (layer ptr tempLayer, neuron ptr tempNeuron) {
  if (tempNeuron -> weightsBackward == NULL)
	return;
  for (int i = 0; i < tempLayer -> previousLayer -> neuronTotalCount; i++)
	printf ("%lf ", ptrVal ((tempNeuron -> weightsBackward)[i] -> weight));
  printf ("\n");
}

void debugDisplayOutputMatrix (layer ptr l) {
  printf ("Output Matrix\n");
  for (int i = 0; i < (l -> neuronTotalCount); i++)
	printf ("%lf ", (l -> outputMatrix)[i]);
  printf ("\n");
}

void debugDisplayErrorMatrix (layer ptr l) {
  printf ("\nError Matrix\n");
  for (int i = 0; i < (l -> neuronTotalCount); i++)
	printf ("%lf ", (l -> errorMatrix)[i]);
  printf ("\n");
}

void debugDisplayWeightMatrix (layer ptr from_layer) {
  if (from_layer -> nextLayer == NULL)
	return;
  printf ("\nWeight Matrix\n");
  for (int i = 0; i < (from_layer -> neuronTotalCount); i++) {
	for (int j = 0; j < (from_layer -> nextLayer -> neuronTotalCount); j++)
	  printf ("%lf ", (from_layer -> weightMatrix)[i][j]);
	printf ("\n");
  }
  printf ("\n");
}

void debugDisplayLayer (layer ptr l) {
  debugDisplayOutputMatrix (l);
  debugDisplayErrorMatrix (l);
  debugDisplayWeightMatrix (l);
}

void debugDisplayNetwork (network ptr network) {
  layer ptr tempLayer = network -> inputLayer;
  int layer_count = 1;
  while (tempLayer != NULL) {
		printf ("\nLayer %d ", layer_count++);
		printf ("[Bias: %lf]", tempLayer -> bias);
		printf ("\n-------\n");
		debugDisplayLayer (tempLayer);
		tempLayer = tempLayer -> nextLayer;
  }
}

void debugNetwork (network ptr network) {
  networkAddLayer (network, 2);
  networkAddLayer (network, 2);
 	(network -> outputLayer -> bias) = 0.35;
  networkAddLayer (network, 2);
 	(network -> outputLayer -> bias) = 0.60;
  double ptr2d w = (network -> inputLayer -> weightMatrix);
  w[0][0] = 0.15;
  w[0][1] = 0.20;
  w[1][0] = 0.25;
  w[1][1] = 0.30;
  w = (network -> inputLayer -> nextLayer -> weightMatrix);
  w[0][0] = 0.40;
  w[0][1] = 0.45;
  w[1][0] = 0.50;
  w[1][1] = 0.55;
  double inputs[2] = {0.05, 0.10};
  networkPropagateForward (network, inputs);
  double target[2] = {0.01, 0.99};
  for (int i = 0; i < 10; i++) 
		networkPropagateBackward (network, target);
  networkPropagateForward (network, inputs);
  debugDisplayNetwork (network);
}

debugProto ptr debugCtor () {
	
	static debugProto ptr this = NULL;
	
	// TODO lock() immediately here (before the following block)
	if (this == NULL) {
		this = malloc (sizeof (debugProto));

		this -> ctor						= debugCtor;
		this -> displayWeightsForward   	= debugDisplayWeightsForward;
		this -> displayWeightsBackward  	= debugDisplayWeightsBackward;
		this -> displayOutputMatrix	 	= debugDisplayOutputMatrix;
		this -> displayErrorMatrix	  	= debugDisplayErrorMatrix;
		this -> displayWeightMatrix	 	= debugDisplayWeightMatrix;
		this -> displayLayer				= debugDisplayLayer;
		this -> displayNetwork		  	= debugDisplayNetwork;
		this -> network				 	= debugNetwork;

	}
	// TODO unlock() immediately here (after the above block)


	return this;
}
*/
