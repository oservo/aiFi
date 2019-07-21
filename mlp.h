#ifndef AIFI__MLP
#define AIFI__MLP

/* <INCLUDE> *************/
#include "popc.h"

#include "cell.h"
#include "layer.h"
#include "activation.h"
#include "loss.h"
#include "optimization.h"
#include "mlpLayer.h"
#include "training.h"
/* </INCLUDE> ************/

// <DELEGATION> //
delegation bool (fnPtr onMlpTrainEpochBeginDelegate) (mlp ptr nw, double ptr1d inputTable1d, int inputRowMax, int inputColumnMax, double ptr1d targetTable1d, int targetRowMax, int targetColumnMax, int epochCurrent);
delegation bool (fnPtr onMlpTrainEpochEndDelegate) (mlp ptr nw, double ptr1d inputTable1d, int inputRowMax, int inputColumnMax, double ptr1d targetTable1d, int targetRowMax, int targetColumnMax, int epochCurrent);

delegation bool (fnPtr onMlpTrainTupleBeginDelegate) (mlp ptr nw, double ptr inputTuple1d, int inputColumnMax, double ptr targetTuple1d, int targetColumnMax);
delegation bool (fnPtr onMlpTrainTupleEndDelegate) (mlp ptr nw, double ptr inputTuple1d, int inputColumnMax, double ptr targetTuple1d, int targetColumnMax);
// </DELEGATION> //

/* <DEFINE> *************/
//#define REQUIRED STUFFS HERE
/* </DEFINE> ************/

/* <CONST> *************/
//#define REQUIRED STUFFS HERE
/* </CONST> ************/

/* <ENUMERATION> *************/
/* </ENUMERATION> *************/

/* <SUBJECT> *************/

subject mlp {
	// <header>
	annType annt;
	int totalLayerCount;
	int inputLayerCount;
	int hiddenLayerCount;
	int outputLayerCount;
	double error;
	double deltaErrorGradient;
	// </header>

	// <body>
	mlpLayer ptr2d layer2d;
	//mlpLayerSingleton ptr2d layerProto2d;
	// </body>

	// <footer>
	int epochMax;
	int epochTally;
	int epochCurrent;
	int tupleMax;
	int tupleTally;
	int tupleCurrent;
	double ptr2d refInput2d; //ref only
	double ptr2d refTarget2d; //ref only
	double ptr2d refOutput2d; //ref only

	onMlpTrainEpochBeginDelegate onTrainEpochBegin;
	onMlpTrainEpochEndDelegate onTrainEpochEnd;
	onMlpTrainTupleBeginDelegate onTrainTupleBegin;
	onMlpTrainTupleEndDelegate onTrainTupleEnd;
	// </footer>
} mlp;

/* </SUBJECT> *************/

/* <PROTOTYPE> *************/

pattern mlpSingleton {
	mlp ptr	(fnPtr mlpNew) ();
	void (fnPtr mlpDel) (mlp ptr nn);

	void (fnPtr addLayer) (mlp ptr nw, int cellCount, layerType lt, cellType ct, activationFunctionType aft, lossFunctionType lft, optimizationFunctionType oft);

	void (fnPtr train) (mlp ptr nn, double ptr1d inputTable1d, int inputTupleMax, int inputColumnMax, double ptr1d targetTable1d, int targetTupleMax, int targetColumnMax, trainingType tt, int epochMax, int batchSize, double learningRate, double learningMomentumRate);
	void (fnPtr trainTuple) (mlp ptr nn, trainingType tt, double ptr input1d, double ptr target1d, double learningRate, double learningMomentumRate);

	void (fnPtr predict) (mlp ptr nn, double ptr2d input2d); 
	void (fnPtr predictTuple) (mlp ptr nn, double ptr input1d);

	void (fnPtr setInput) (mlp ptr nn, double ptr input1d);
	void (fnPtr setTarget) (mlp ptr nn, double ptr target1d);
	void (fnPtr propagateForward) (mlp ptr nn);
	void (fnPtr propagateBackward) (mlp ptr nn, double learningRate, double learningMomentumRate);
} mlpSingleton;

/* </PROTOTYPE> ************/

/* <VARIABLE> *************/

/* </VARIABLE> ************/

/* <DECLARATION> *************/
#ifdef Cplusplus
extern "C" {
#endif

//
mlpSingleton ptr mlpSingletonNew ();
// /

//
mlp ptr mlpNew ();
void mlpDel (mlp ptr nn);

void mlpAddInputLayer ();
void mlpAddHiddenLayer ();
void mlpAddOutputLayer ();
void mlpAddLayer (mlp ptr nn, int cellCount, layerType lt, cellType ct, activationFunctionType aft, lossFunctionType lft, optimizationFunctionType oft);

void mlpTrain (mlp ptr nn, double ptr1d inputTable1d, int inputTupleMax, int inputColumnMax, double ptr1d targetTable1d, int targetTupleMax, int targetColumnMax, trainingType tt, int epochMax, int batchSize, double learningRate, double learningMomentumRate);
void mlpTrainTuple (mlp ptr nn, trainingType tt, double ptr input1d, double ptr target1d, double learningRate, double learningMomentumRate);

void mlpPredict (mlp ptr nn, double ptr2d input2d);
void mlpPredictTuple (mlp ptr nn, double ptr input1d);

void mlpSetInput (mlp ptr nn, double ptr input1d);
void mlpSetTarget (mlp ptr nn, double ptr target1d);
void mlpPropagateForward (mlp ptr nn);
void mlpPropagateBackward (mlp ptr nn, double learningRate, double learningMomentumRate);
// /


#ifdef Cplusplus
}
#endif
/* </DECLARATION> ************/

#endif
