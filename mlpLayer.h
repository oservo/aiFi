#ifndef AIFI__MLP_LAYER
#define AIFI__MLP_LAYER

// <INCLUDE> //
#include "popc.h"

#include "cell.h"
#include "layer.h"
#include "mlp.h"
#include "activation.h"
#include "loss.h"
#include "optimization.h"
// </INCLUDE> //

// <DELEGATION> //
// pending/
//delegation bool (fnPtr onMlpLayerPropagateForwardBeginDelegate) (mlp ptr nw, double ptr1d inputTable1d, int inputRowMax, int inputColumnMax, double ptr1d targetTable1d, int targetRowMax, int targetColumnMax, int epochCurrent);
//delegation bool (fnPtr onMlpLayerPropagateForwardEndDelegate) (mlp ptr nw, double ptr1d inputTable1d, int inputRowMax, int inputColumnMax, double ptr1d targetTable1d, int targetRowMax, int targetColumnMax, int epochCurrent);

//delegation bool (fnPtr onMlpLayerPropagateBackwardCalculationBeginDelegate) (mlp ptr nw, double ptr inputTuple1d, int inputColumnMax, double ptr targetTuple1d, int targetColumnMax);
//delegation bool (fnPtr onMlpLayerPropagateBackwardCalculationEndDelegate) (mlp ptr nw, double ptr inputTuple1d, int inputColumnMax, double ptr targetTuple1d, int targetColumnMax);
//delegation bool (fnPtr onMlpLayerPropagateBackwardLearningBeginDelegate) (mlp ptr nw, double ptr inputTuple1d, int inputColumnMax, double ptr targetTuple1d, int targetColumnMax);
//delegation bool (fnPtr onMlpLayerPropagateBackwardLearningEndDelegate) (mlp ptr nw, double ptr inputTuple1d, int inputColumnMax, double ptr targetTuple1d, int targetColumnMax);
// </DELEGATION> //

/* <FORWARD DECLARATION> *************/
subject mlp mlp; //FD!
/* </FORWARD DECLARATION> ************/


// <DEFINE> //
//#define REQUIRED STUFFS HERE
// </DEFINE> //

// -- V2 -- //

// <SUBJECT> //
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
	cellConnectionCount ptr 					connectionCount1d;
	cellInput ptr2d 							input2d;
	cellWeight ptr2d 							weight2d;
	cellOutput ptr 								output1d;
	cellTarget ptr 								target1d;
	cellError ptr 								outputError1d;
	cellDeltaError ptr 						outputDeltaErrorGradient1d;
	cellDeltaError ptr 						previousOutputDeltaErrorGradient1d;
	cellBias ptr 									bias1d;
	cellDeltaBias ptr 						biasDeltaGradient1d;
	cellDeltaBias ptr 						previousBiasDeltaGradient1d;
	
	activation ptr2d 		actFn2d;
	loss ptr2d 					lossFn2d;
	optimization ptr2d	optFn2d;
	// /cell vector
} mlpLayer;
// </SUBJECT> //

// <PROTOTYPE> //
pattern mlpLayerSingleton {
  mlpLayer ptr 								(fnPtr mlpLayerAppend) (mlp ptr nw, int cellCount, layerType lt, cellType ct, activationFunctionType aft, lossFunctionType lft, optimizationFunctionType oft);
 	void 											(fnPtr mlpLayerDel) (mlpLayer ptr l);

	void (fnPtr propagateForward) (mlpLayer ptr previousLayer, mlpLayer ptr currentLayer);
	void (fnPtr propagateBackward) (mlpLayer ptr previousLayer, mlpLayer ptr currentLayer, mlpLayer ptr nextLayer, double learningRate, double learningMomentumRate);

  void 											(fnPtr setInput) (mlpLayer ptr l, double ptr2d input2d);
  //PENDING void 											(fnPtr setError) (mlpLayer ptr l, double ptr target);
} mlpLayerSingleton;

// </PROTOTYPE> //
 
#ifdef Cplusplus
extern "C" {
#endif

//
mlpLayerSingleton ptr	mlpLayerSingletonNew ();
// /

//
mlpLayer ptr 					mlpLayerAppend (mlp ptr nw, int cellCount, layerType lt, cellType ct, activationFunctionType aft, lossFunctionType lft, optimizationFunctionType oft);
void								mlpLayerDel (mlpLayer ptr l);

void mlpLayerPropagateForward (mlpLayer ptr previousLayer, mlpLayer ptr currentLayer);
void mlpLayerPropagateBackward (mlpLayer ptr previousLayer, mlpLayer ptr currentLayer, mlpLayer ptr nextLayer, double learningRate, double learningMomentumRate);

void 								mlpLayerSetInput (mlpLayer ptr l, double ptr2d input2d);
//PENDING void 								mlpLayerSetError (mlpLayer ptr l, double ptr target);
// /




#ifdef Cplusplus
}
#endif
#endif


