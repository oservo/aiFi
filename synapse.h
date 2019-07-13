#ifndef PANN__SYNAPSE
#define PANN__SYNAPSE

// [INCLUDE] //
#include "popc.h"

#include "axon.h"
#include "dendrite.h"
#include "neuron.h"

// [/INCLUDE] //

// [DEFINE] //
//#define REQUIRED STUFFS HERE
// [/DEFINE] //

// -- V2 -- //

enumeration {
	synapseExcitatory,
	synapseInhibitory
} synapseType;

subject dendrite dendrite; //FD!
subject axon axon; //FD!

subject synapse {
	synapseType type;
  axon ptr preSynapticAxon;
  dendrite ptr postSynapticDendrite;
} synapse;


prototype synapseProto {

} synapseProto;

#ifdef Cplusplus
extern "C" {
#endif

// [DECLARATION] //

// [/DECLARATION] //

#ifdef Cplusplus
}
#endif
#endif
