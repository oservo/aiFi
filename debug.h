#ifndef PANN__DEBUG
#define PANN__DEBUG

// [INCLUDE] //
#include "popc.h"

#include "neuron.h"
#include "layer.h"
#include "network.h"

// [/INCLUDE] //

#ifdef Cplusplus
extern "C" {
#endif

void debugDisplayWeightsForward (layer ptr tempLayer, neuron ptr tempNeuron);

void debugDisplayWeightsBackward (layer ptr tempLayer, neuron ptr tempNeuron);

void debugDisplayOutputMatrix (layer ptr l);

void debugDisplayErrorMatrix (layer ptr l);

void debugDisplayWeightMatrix (layer ptr from_layer);

void debugDisplayLayer (layer ptr l);

void debugDisplayNetwork (network ptr network);

void debugNetwork (network ptr network);

//debugProto ptr debugCtor ();

#ifdef Cplusplus
}
#endif
#endif
