#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "popc.h"


#include "cell.h"
#include "activation.h"
#include "loss.h"
#include "optimization.h"
//#include "activation.h"
#include "ann.h"
#include "mlp.h"
#include "layer.h"
#include "mlpLayer.h"


mlpLayerSingleton ptr	mlpLayerSingletonNew () {
	static mlpLayerSingleton ptr this = NULL;
	
	// TODO lock() immediately here (before the following block)
	if (this == NULL) {
		this = malloc (sizeof (mlpLayerSingleton));
		this -> mlpLayerAppend				= mlpLayerAppend;
		this -> mlpLayerDel				= mlpLayerDel;

		this -> propagateForward				= mlpLayerPropagateForward;
		this -> propagateBackward				= mlpLayerPropagateBackward;

		this -> setInput			= mlpLayerSetInput;
		//PENDING this -> setError			  = mlpLayerSetError;
	}
	// TODO unlock() immediately here (after the above block)


	return this;
}

mlpLayer ptr mlpLayerAppend (mlp ptr nw, int cellCount, layerType lt, cellType ct, activationFunctionType aft, lossFunctionType lft, optimizationFunctionType oft) {
	mlpLayer ptr tempLayer;
	int previousLayerCellCount;
	int currentLayerIndex;
	
	currentLayerIndex = nw -> totalLayerCount;

	dbcRequire (cellCount > 0, "Unacceptable number of cells provided for mlpLayer: %d", currentLayerIndex);

	if (currentLayerIndex > 0) {
		previousLayerCellCount = nw -> layer2d [currentLayerIndex - 1] -> cellCount;  
	}
	else {
		previousLayerCellCount = 1;
	}

	switch (lt) {
		case ltInput:
			dbcRequire (nw -> inputLayerCount == 0 && nw -> totalLayerCount == 0, "Input Layer must be added first and once.");
			nw -> inputLayerCount ++;
			nw -> totalLayerCount ++;
			break;

		case ltHidden:
			dbcRequire (nw -> inputLayerCount == 1 && nw -> outputLayerCount == 0, "Hidden Layer must be added in between input layer and output layer.");
			nw -> hiddenLayerCount ++;
			nw -> totalLayerCount ++;
			break;

		case ltOutput:
			dbcRequire (nw -> inputLayerCount == 1 && nw -> outputLayerCount == 0, "Output Layer must be added at last and once.");
			nw -> outputLayerCount ++;
			nw -> totalLayerCount ++;
			break;

	}

	if (nw -> totalLayerCount == 1) {
		nw -> layer2d = (mlpLayer ptr2d) malloc (nw -> totalLayerCount * sizeof (mlpLayer ptr));
 	}
	else {
		nw -> layer2d = (mlpLayer ptr2d) realloc (nw -> layer2d, nw -> totalLayerCount * sizeof (mlpLayer ptr));
	}
	dbcEnsure (nw -> layer2d != NULL, "Memory Allocation Error!");

	tempLayer = (mlpLayer ptr) malloc (sizeof (mlpLayer));
	dbcEnsure (tempLayer != NULL, "Memory Allocation Error! for mlpLayer: %d", currentLayerIndex);

	// <layer header>
	tempLayer -> index = currentLayerIndex;	
	tempLayer -> cellCount = cellCount;
	tempLayer -> lt = lt;
	tempLayer -> ct = ct;
	tempLayer -> error = 0.0;
	tempLayer -> deltaErrorGradient = 0.0;
	tempLayer -> aft = aft;
	tempLayer -> lft = lft;
	tempLayer -> oft = oft;
	tempLayer -> learningRate = 0.0;
	tempLayer -> learningMomentumRate = 0.0;
	// </layer header>
	
	// <layer cell vector>
	tempLayer -> connectionCount1d = (cellConnectionCount ptr) malloc (cellCount * sizeof (cellConnectionCount));
	dbcEnsure (tempLayer -> connectionCount1d != NULL, "Memory Allocation Error!");

	tempLayer -> input2d = (cellInput ptr2d) malloc (cellCount * sizeof (cellInput ptr));
	dbcEnsure (tempLayer -> input2d != NULL, "Memory Allocation Error!");

	tempLayer -> weight2d = (cellWeight ptr2d) malloc (cellCount * sizeof (cellWeight ptr));
	dbcEnsure (tempLayer -> weight2d != NULL, "Memory Allocation Error!");

	tempLayer -> output1d =  (cellOutput ptr) malloc (cellCount * sizeof (cellOutput));
	dbcEnsure (tempLayer -> output1d != NULL, "Memory Allocation Error!");

	tempLayer -> target1d =  (cellTarget ptr) malloc (cellCount * sizeof (cellTarget));
	dbcEnsure (tempLayer -> target1d != NULL, "Memory Allocation Error!");

	tempLayer -> outputError1d =  (cellError ptr) malloc (cellCount * sizeof (cellError));
	dbcEnsure (tempLayer -> outputError1d != NULL, "Memory Allocation Error!");

	tempLayer -> outputDeltaErrorGradient1d =  (cellDeltaError ptr) malloc (cellCount * sizeof (cellDeltaError));
	dbcEnsure (tempLayer -> outputDeltaErrorGradient1d != NULL, "Memory Allocation Error!");

	tempLayer -> previousOutputDeltaErrorGradient1d =  (cellDeltaError ptr) malloc (cellCount * sizeof (cellDeltaError));
	dbcEnsure (tempLayer -> previousOutputDeltaErrorGradient1d != NULL, "Memory Allocation Error!");

	tempLayer -> previousBiasDeltaGradient1d =  (cellDeltaError ptr) malloc (cellCount * sizeof (cellDeltaError));
	dbcEnsure (tempLayer -> previousBiasDeltaGradient1d != NULL, "Memory Allocation Error!");

	tempLayer -> bias1d =  (cellBias ptr) malloc (cellCount * sizeof (cellBias));
	dbcEnsure (tempLayer -> bias1d != NULL, "Memory Allocation Error!");

	tempLayer -> biasDeltaGradient1d =  (cellDeltaBias ptr) malloc (cellCount * sizeof (cellDeltaBias));
	dbcEnsure (tempLayer -> biasDeltaGradient1d != NULL, "Memory Allocation Error!");
	
  tempLayer -> actFn2d =  (activation ptr2d) malloc (cellCount * sizeof (activation ptr));
	dbcEnsure (tempLayer -> actFn2d != NULL, "Memory Allocation Error!");

	tempLayer -> lossFn2d =  (loss ptr2d ) malloc (cellCount * sizeof (loss ptr));
	dbcEnsure (tempLayer -> lossFn2d != NULL, "Memory Allocation Error!");

	tempLayer -> optFn2d =  (optimization ptr2d) malloc (cellCount * sizeof (optimization ptr));
	dbcEnsure (tempLayer -> optFn2d != NULL, "Memory Allocation Error!");
	// </layer cell vector>
	
	//#pragma omp parallel for
  for (int i = 0; i < cellCount; i ++) {
		tempLayer -> connectionCount1d [i] = previousLayerCellCount;  

		tempLayer -> output1d [i] =  0.0;
		tempLayer -> target1d [i] =  0.0;
		tempLayer -> outputError1d [i] =  0.0;
		tempLayer -> outputDeltaErrorGradient1d [i] =  0.0;
		tempLayer -> previousOutputDeltaErrorGradient1d [i] =  0.0;
		tempLayer -> bias1d [i] = annRandomizer();
		tempLayer -> biasDeltaGradient1d [i] =  0.0;
		
		tempLayer -> actFn2d [i] = activationNew (aft);
		tempLayer -> lossFn2d [i] = lossNew (lft);
		tempLayer -> optFn2d [i] = optimizationNew (oft);

		tempLayer -> input2d [i] = (cellInput ptr1d) malloc (previousLayerCellCount * sizeof (cellInput));
		dbcEnsure (tempLayer -> input2d [i] != NULL, "Memory Allocation Error!");

		tempLayer -> weight2d [i] = (cellWeight ptr1d) malloc (previousLayerCellCount * sizeof (cellWeight));
		dbcEnsure (tempLayer -> weight2d [i] != NULL, "Memory Allocation Error!");

		for (int j = 0; j < tempLayer -> connectionCount1d [i]; j ++) {
			tempLayer -> input2d [i][j]  = 0.0;
			tempLayer -> weight2d [i][j]  = annRandomizer();
		}
	}
	nw -> layer2d [currentLayerIndex] = (mlpLayer ptr) malloc (sizeof (mlpLayer));
	dbcEnsure (nw -> layer2d [currentLayerIndex] != NULL, "Memory Allocation Error!");
	nw -> layer2d [currentLayerIndex] = tempLayer;

	return tempLayer; // ignore return value; we've already done everything inside.
}

void mlpLayerDel (mlpLayer ptr l) {
	free (l);
}

/*
mlpLayerType mlpLayerGetType (linkedListNode ptr currentLayerNode) {
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
*/


/* PENDING

void mlpLayerDel (mlpLayer ptr l) {
	// PENDING/
	free (l);
}
*/

void mlpLayerPropagateForward (mlpLayer ptr previousLayer, mlpLayer ptr currentLayer) {
	double dotProduct = 0.0;

	//#pragma omp parallel for
	for (int cc = 0; cc < currentLayer -> cellCount; cc ++) {
		// STIMULUS/ 
		dotProduct = 0.0;
		for (int wc = 0; wc < currentLayer -> connectionCount1d [cc]; wc ++) { // previous mlpLayer cells
			dotProduct += previousLayer -> output1d [wc] * currentLayer -> weight2d [cc][wc]; // sum (Xi * Wi)
		}
		dotProduct += currentLayer -> bias1d [cc]; // sum (Xi * Wi) + b

		// ACTION POTENTIAL/
		currentLayer -> output1d [cc] = currentLayer -> actFn2d [cc] -> activationTransferFunction (dotProduct);
	}


}

void mlpLayerPropagateBackward (mlpLayer ptr previousLayer, mlpLayer ptr currentLayer, mlpLayer ptr nextLayer, double learningRate, double learningMomentumRate) {
	// <CALCULATE SIGNAL ERROR>
	// OUTPUT LAYER/
	if (currentLayer -> lt == ltOutput) {
		//#pragma omp parallel for
		for (int i = 0; i < currentLayer -> cellCount; i ++) {
			//err = (double) currentLayer -> target1d [i] - currentLayer -> output1d [i];
			// declare local block err variable
			double err = 0.0;
			err = currentLayer -> lossFn2d [i] -> lossTransferFunction (currentLayer -> target1d [i], currentLayer -> output1d [i]);
			currentLayer -> outputError1d [i] = err;
			currentLayer -> outputDeltaErrorGradient1d [i] = err * currentLayer -> actFn2d [i] -> activationTransferFunctionPrime (currentLayer -> output1d [i]);
			currentLayer -> error += abs (err);
		}
	}
	// INPUT LAYER/
	else if (currentLayer -> lt == ltInput) {
		//DO NOTHING. KEPT THE BLOCK FO BREVITY
	}
	// HIDDEN LAYER/
	else {
		//#pragma omp parallel for
		for (int i = 0; i < currentLayer -> cellCount; i ++) {
			// declare local block err variable
			double errSum = 0.0;
			for (int j = 0; j < nextLayer -> cellCount; j ++) {
				/*
				currentLayer -> outputDeltaErrorGradient1d [i] += 
					nextLayer -> weight2d [j][i] * 
					nextLayer -> outputDeltaErrorGradient1d [j]
				;
				*/
				errSum += (nextLayer -> weight2d [j][i] * nextLayer -> outputDeltaErrorGradient1d [j]); 
			}
			currentLayer -> outputError1d [i] = errSum;
			currentLayer -> outputDeltaErrorGradient1d [i] = errSum * currentLayer -> actFn2d [i] -> activationTransferFunctionPrime (currentLayer -> output1d [i]) ;
			;
			currentLayer -> error += abs (errSum);

		}
	}
	// </CALCULATE SIGNAL ERROR>


	// <LEARN FROM ERROR>

	// INPUT LAYER/
	if (currentLayer -> lt == ltInput) {
		//DO NOTHING. KEPT THE BLOCK FO BREVITY
	}
	// HIDDEN AND OUTPUT LAYER/
	else {
		//#pragma omp parallel for
		for (int i = 0; i < (currentLayer -> cellCount); i ++) {
			// calc/
				double tmpDeltaWeight = 0.0, tmpDeltaBias = 0.0;

			// update weight/
			for (int j = 0; j < currentLayer -> connectionCount1d [i]; j ++) {
				tmpDeltaWeight = learningRate * currentLayer -> outputDeltaErrorGradient1d [i] * previousLayer -> output1d [j];
				currentLayer -> weight2d [i][j] += tmpDeltaWeight;
				currentLayer -> weight2d [i][j] += learningMomentumRate * currentLayer -> previousOutputDeltaErrorGradient1d [i];
				currentLayer -> previousOutputDeltaErrorGradient1d [i] = tmpDeltaWeight;

			}

			// upate bias/
			tmpDeltaBias = learningRate * currentLayer -> outputDeltaErrorGradient1d [i] * 1.0;

			currentLayer -> bias1d [i] += tmpDeltaBias;
			currentLayer -> bias1d [i] += learningMomentumRate * currentLayer -> previousBiasDeltaGradient1d [i]; 

			currentLayer -> previousBiasDeltaGradient1d [i] = tmpDeltaBias;
		}
	}
	// </LEARN FROM ERROR>
}


void mlpLayerSetInput (mlpLayer ptr l, double ptr2d input2d) {
	//#pragma omp parallel for
	for (int r = 0; r < l -> cellCount; r ++) {
		for (int c = 0; r < l -> connectionCount1d [r]; c ++) {
			l -> input2d [r][c] = input2d [r][c];
		}
	}
}

/* PENDING
void mlpLayerSetError (mlpLayer ptr l, double ptr2d input2d) {
	//#pragma omp parallel for
	for (int r = 0; r < l -> cellCount; r ++) {
		for (int c = 0; r < l -> connectionCount1d [r]; c ++) {
		l -> input2d [r][c] = input2d [r][c];
	}
}
*/