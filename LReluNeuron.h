/*
* Author
* Koray Kural
* 150170053
*/
#ifndef NEURON_CLASS
#include "Neuron.h"
#define NEURON_CLASS
#endif

class LReluNeuron : public Neuron
{
public:
  LReluNeuron(double);
  ~LReluNeuron();
  void activate();
};

LReluNeuron::LReluNeuron(double z_in = 0.0) : Neuron(z_in) { }

LReluNeuron::~LReluNeuron() { }

void LReluNeuron::activate()
{
  a = (0.1 * z > z) ? (0.1 * z) : z;
}