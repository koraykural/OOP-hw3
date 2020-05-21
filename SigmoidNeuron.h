/*
* Author
* Koray Kural
* 150170053
*/
#ifndef NEURON_CLASS
#include "Neuron.h"
#define NEURON_CLASS
#endif

#include <cmath> // Exp function

class SigmoidNeuron : public Neuron
{
public:
  SigmoidNeuron(double);
  ~SigmoidNeuron();
  void activate();
};

SigmoidNeuron::SigmoidNeuron(double z_in = 0.0) : Neuron(z_in) { }

SigmoidNeuron::~SigmoidNeuron() { }

void SigmoidNeuron::activate()
{
  a = 1 / (1 + exp(-z));
}