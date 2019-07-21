#ifndef AIFI__ANN
#define AIFI__ANN

// <INCLUDE> //
#include "popc.h"
// </INCLUDE> //

// <DEFINE> //
// </DEFINE> //



// -- V2/ ------------------------------------------------------------------------------------------------------ //


// <TYPE>
enumeration annType {
	anntFeedForward,
	anntRadialBasisFunction,
	anntDeepFeedForward,
	anntRecurrentNeuralNetwork,
	anntLongShortTermMemory,
	anntGatedRecurrentUnit,
	anntMultiLayerPerceptron,
	anntAutoEncoder,
	anntAutoEncoderVariational,
	anntAutoEncoderDenoising,
	anntAutoEncoderSparse,
	anntMarcovChain,
	anntHopfieldNetwork,
	anntBoltzmannMachine,
	anntBoltzmannMachineRestricted,
	anntDeepBeliefNetwork,
	anntDeepConvolutional,
	anntDeconvolutionalNetwork,
	anntDeepConvolutionalInverseGraphicsNetwork,
	anntGenerativeAdversialNetwork,
	anntLiquidStateMachine,
	anntExtremeLearningMachine,
	anntEchoStateNetwork,
	anntDeepResidualNetwork,
	anntKohonenNetwork,
	anntSupportVectorMachine,
	anntNeuralTuringMachine,
} annType;



// </TYPE>

#ifdef Cplusplus
extern "C" {
#endif


double annRandomizer ();


#ifdef Cplusplus
}
#endif
#endif

