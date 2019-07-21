#include <stdio.h>
#include <stdlib.h>

#include "popc.h"


#include "activation.h"
#include "loss.h"
#include "optimization.h"
#include "ann.h"
#include "cell.h"
#include "mlp.h"
#include "training.h"

mlpSingleton ptr mlpSingletonNew () {
	static mlpSingleton ptr np = NULL;
		
		if (np == NULL) {
			np = (mlpSingleton ptr) malloc (sizeof (mlpSingleton));
			dbcEnsure (np != NULL, "Memory Allocation Error!");
			np -> mlpNew 											= mlpNew;
			np -> mlpDel 											= mlpDel;
			
			np -> addLayer 										= mlpAddLayer;

			np -> train 											= mlpTrain;
			np -> trainTuple 											= mlpTrainTuple;

			np -> predict 										= mlpPredict;
			np -> predictTuple 										= mlpPredictTuple;

			np -> setInput 										= mlpSetInput;
			np -> setTarget 									= mlpSetTarget;
			np -> propagateForward 						= mlpPropagateForward;
			np -> propagateBackward 					= mlpPropagateBackward;
		}
		return np;
	} 

mlp ptr mlpNew () {
  mlp ptr nw = (mlp ptr) malloc (sizeof (mlp));
	dbcEnsure (nw != NULL, "Memory Allocation Error!");
	nw -> annt = anntMultiLayerPerceptron;
	nw -> layer2d = NULL;
	nw -> inputLayerCount = 0;
	nw -> hiddenLayerCount = 0;
	nw -> outputLayerCount = 0;
	nw -> totalLayerCount = 0;

	nw -> onTrainEpochBegin = NULL; 
	nw -> onTrainEpochEnd = NULL; 
	nw -> onTrainTupleBegin = NULL; 
	nw -> onTrainTupleEnd = NULL; 

  return nw;
}

void mlpDel (mlp ptr nw) {
  // PENDING! need to clean-up inner objects
	free (nw);
	nw = NULL;
}

void mlpAddInputLayer () {

}

void mlpAddHiddenLayer () {

}

void mlpAddOutputLayer () {

}

void mlpAddLayer (
	mlp ptr nw, 
	int cellCount, 
	layerType lt, 
	cellType ct, 
	activationFunctionType aft, 
	lossFunctionType lft, 
	optimizationFunctionType oft
) {
	/*
	subject mlpLayer {
		// header
		layerIndex index;
		layerCellCount cellCount;
		layerType lt;
		cellType ct;
		layerError error;
		layerDeltaError deltaErrorGradient;
		activationFunctionType aft;
		lossFunctionType lft;
		optimizationFunctionType oft;
		double learningRate;
		double learningMomentumRate;
		// /header

		// cell vector
		cellConnectionCount ptr 			connectionCount1d;
		cellInput ptr2d 							input2d;
		cellWeight ptr2d 							weight2d;
		cellOutput ptr 								output1d;
		cellTarget ptr 								target1d;
		cellError ptr 								outputError1d;
		cellDeltaError ptr 						outputDeltaErrorGradient1d;
		cellBias ptr 									bias1d;
		cellDeltaBias ptr 						biasDeltaGradient1d;
		
		activation ptr2d 		actFn2d;
		loss ptr2d 					lossFn2d;
		optimization ptr2d	optFn2d;
		// /cell vector
	} mlpLayer;
	*/

	//mlpLayer ptr currentLayer;

	mlpLayerAppend (nw, cellCount, lt, ct, aft, lft, oft);
}

// Propagation/
void mlpPropagateForward (mlp ptr nw) {
	mlpLayer ptr previousLayer, 
		ptr currentLayer 
		//ptr nextLayer
	;
	/*
	printf ("SL\t\
		II:0\tII:1\tIO:0\tIO:1\t\
		HW:00\tHW:01\tHW:10\tHW:11\tHO:0\tHO:1\t\
		OW:00\tOW:01\tOO:0\n"
	);
	int sl = 0;
	*/

	//#pragma omp parallel for
	for (int index = 1; index < nw -> totalLayerCount; index ++) {
		previousLayer = index == 0 ? NULL : nw -> layer2d [index - 1];
		currentLayer = nw -> layer2d  [index];
		//nextLayer = index == nw -> totalLayerCount - 1 ? NULL : nw -> layer2d [index + 1];
		mlpLayerPropagateForward (previousLayer, currentLayer);
	}
	/*
	printf ("%d\t\
		%lf\t%lf\t%lf\t%lf\t\
		%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t\
		%lf\t%lf\t%lf\n",
		sl ++, 
		nw -> layer2d [0] -> input2d [0][0], nw -> layer2d [0] -> input2d [0][1], nw -> layer2d [0] -> output1d [0],  nw -> layer2d [0] -> output1d [1],
		nw -> layer2d [1] -> weight2d [0][0], nw -> layer2d [1] -> weight2d [0][1], nw -> layer2d [1] -> weight2d [1][0],  nw -> layer2d [1] -> weight2d [1][1], nw -> layer2d [1] -> output1d [0],  nw -> layer2d [1] -> output1d [1],
		nw -> layer2d [2] -> weight2d [0][0], nw -> layer2d [2] -> weight2d [0][1], nw -> layer2d [2] -> output1d [0]
	);
	*/
}

// Back Propagation/
void mlpPropagateBackward (mlp ptr nw, double learningRate, double learningMomentumRate) {
	mlpLayer ptr previousLayer, 
		ptr currentLayer, 
		ptr nextLayer
	;
	
	//#pragma omp parallel for
	for (int index = nw -> totalLayerCount - 1; index > 0; index --) {
		previousLayer = index == 0 ? NULL : nw -> layer2d [index - 1];
		currentLayer = nw -> layer2d [index];
		nextLayer = index == nw -> totalLayerCount - 1 ? NULL : nw -> layer2d [index + 1];
		mlpLayerPropagateBackward (previousLayer, currentLayer, nextLayer, learningRate, learningMomentumRate);
	}
}


void mlpTrain (mlp ptr nn, double ptr1d inputTable1d, int inputTupleMax, int inputColumnMax, double ptr1d targetTable1d, int targetTupleMax, int targetColumnMax, trainingType tt, int epochMax, int batchSize, double learningRate, double learningMomentumRate) {

	dbcRequire (tt == ttOnlineTraining, "Only Online Training Type is allowed.");
	dbcRequire (batchSize == 1, "Only batch size of 1 is allowed, due to the  Online Training Type implementation.");

	// reset epoch statistics fn ()/
	nn -> epochTally = 0;
  for (int epoch = 0; epoch < epochMax; epoch ++) {
		if (nn -> onTrainEpochBegin != NULL && nn -> onTrainEpochBegin (nn, inputTable1d, inputTupleMax, inputColumnMax, targetTable1d, targetTupleMax, targetColumnMax, epoch) == /* should we skip? */ true) 
			continue
		;

		// reset table statistics fn ()/
		nn -> tupleTally = 0;
		//#pragma omp parallel for
		for (int r = 0; r < inputTupleMax; r ++) {
			//mlp ptr nw, double ptr inputTuple1d, int inputColumnMax, double ptr targetTuple1d, int targetColumnMax
			if (nn -> onTrainTupleBegin != NULL && nn -> onTrainTupleBegin (nn, addr inputTable1d [r * inputColumnMax], inputColumnMax, addr targetTable1d[r * targetColumnMax], targetColumnMax) == /* should we skip? */ true) 
				continue
			;

			mlpTrainTuple (nn, tt, addr inputTable1d [r * inputColumnMax], /*(double ptr)*/ addr targetTable1d [r * targetColumnMax], learningRate, learningMomentumRate);
	
			// update table statistics fn ()/
			nn -> tupleTally ++;
	
			if (nn -> onTrainTupleEnd != NULL)
				nn -> onTrainTupleEnd (nn, addr inputTable1d [r * inputColumnMax], inputColumnMax, addr targetTable1d[r * targetColumnMax], targetColumnMax)
			;

		}
		// update epoch statistics fn ()/
		nn -> epochTally ++;

		if (nn -> onTrainEpochEnd != NULL)
			nn -> onTrainEpochEnd (nn, inputTable1d, inputTupleMax, inputColumnMax, targetTable1d, targetTupleMax, targetColumnMax, epoch)
		;

  }
}


void mlpTrainTuple (mlp ptr nw, trainingType tt, double ptr input1d, double ptr target1d, double learningRate, double learningMomentumRate) {
	dbcRequire (tt == ttOnlineTraining, "Given Training Type not implemented yet.");

	mlpSetInput (nw, input1d);
	mlpSetTarget (nw, target1d);

  mlpPropagateForward (nw);
  mlpPropagateBackward (nw, learningRate, learningMomentumRate);
}

void mlpPredict (mlp ptr nn, double ptr2d input2d) {
	int inputEndTuple = sizeof (input2d);
	//#pragma omp parallel for
	for (int r = 0; r < inputEndTuple; r ++) {
		mlpPredictTuple (nn, input2d [r]);
		//printf ("%f XOR %f = %f. Predicted: %f\n", dataIn [r][0], dataIn [r][1], dataOut [r][0], ((layer ptr) nw -> layerLinkedList -> tail -> obj) -> neuron1d [0] -> axon -> output ); 
		//printf ("%f XOR %f = %f. Target: %f; Predicted: %f.\n", input2d [r][0], input2d [r][1], dataOut [r][0], nw -> layer2d [nw -> totalLayerCount - 1] -> target1d [0], nw -> layer2d [nw -> totalLayerCount - 1] -> output1d [0] ); 
	}


}

void mlpPredictTuple (mlp ptr nw, double ptr input1d) {
	mlpSetInput (nw, input1d);

  mlpPropagateForward (nw);
}

void mlpSetInput (mlp ptr nw, double ptr input1d) {
	mlpLayer ptr inputLayer = nw -> layer2d [0];
	//#pragma omp parallel for
	for (int c = 0; c < inputLayer -> cellCount; c ++) {
		// <output = input>
		//inputLayer -> input2d [c][0] = input1d [c]; // We could omit this line. Kept for brevity.
		inputLayer -> output1d [c] = input1d [c];
		// </output = input>
	}
}

void mlpSetTarget (mlp ptr nw, double ptr target1d) {
	mlpLayer ptr outputLayer = nw -> layer2d [nw -> totalLayerCount - 1];
	//#pragma omp parallel for
	for (int c = 0; c < outputLayer -> cellCount; c ++) {
		outputLayer -> target1d [c] = target1d [c];
	}
}



