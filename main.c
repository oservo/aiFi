#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

#include "popc.h"
#include "dbc.h"

#include "neuron.h"
#include "layer.h"
#include "network.h"
#include "function.h"

#define PRG_MAIN

property mainProperty {

} mainProperty;


int trainAndPredict (int start, int end) {
	int ret = 0;
  //int trainDataRows = 10;
  //int testDataRows = 10;
  int epochMax = 9999;
  //double score = 0;
	//double ptr3d inputMatrix = NULL, ptr3d outputTargetMatrix = NULL;
	networkProto ptr nwp;
	network ptr nw;
	int dataCount = 12;
	double dataIn[12][2] = {
			{0, 1},
			{1, 0},
			{1, 1},
			{0, 0}, 
			{0, 1},
			{1, 0},
			{1, 1},
			{0, 0}, 
			{0, 1},
			{1, 0},
			{1, 1},
			{0, 0}, 
	};
	double dataOut[12][1] = {
			{1},
			{1},
			{0},
			{0},
			{1},
			{1},
			{0},
			{0},
			{1},
			{1},
			{0},
			{0},
	};

	nwp = networkProtoInstance (); // get singleton instance of networkProto
	nw = nwp -> construct ();

	nwp -> addLayer (nw, 1, 2, 1, attLogisticSigmoid);
	nwp -> addLayer (nw, 1, 2, 1, attLogisticSigmoid);
	nwp -> addLayer (nw, 1, 1, 1, attLogisticSigmoid);
	//networkSetEpoch (nn, epoch);

	printf ("==TRAININIG==\n");
  for (int j = 0; j < epochMax; j++) {
		int toggle = 0;
		if (j % 1000 == 0){
			printf ("Epoch: %0d\n", j+1);
			toggle = 1 - toggle;
		}
		//if (j == epochMax -1) {
		//	toggle = 1;
		//}
		for (int r = start; r < dataCount; r++) {
			nwp -> train (nw, (double ptr) dataIn[r], (double ptr) dataOut[r], LEARNING_RATE, LEARNING_MOMENTUM_RATE);

			if (toggle == 1) {
				printf ("%f XOR %f = %f. Predicted: %f\n", dataIn[r][0], dataIn[r][1], dataOut[r][0], ((layer ptr) nw -> layerLinkedList -> tail -> object) -> neuronLinearVector[0] -> axon -> output ); 
			}
		}
  }

	printf ("==TRIAL==\n");
	for (int r = start; r < end; r++) {
		nwp -> predict (nw, dataIn[r]);
		printf ("%f XOR %f = %f. Predicted: %f\n", dataIn[r][0], dataIn[r][1], dataOut[r][0], ((layer ptr) nw -> layerLinkedList -> tail -> object) -> neuronLinearVector[0] -> axon -> output ); 
	}

	return ret;
}

int main () {
	trainAndPredict (0, 4);
}
