/*
* Author
* Koray Kural
* 150170053
*/
#ifndef NEURON_CLASS
#include "Neuron.h"
#define NEURON_CLASS
#endif

class ReluNeuron : public Neuron
{
public:
  ReluNeuron(double);
  ~ReluNeuron();
  void activate();
};

ReluNeuron::ReluNeuron(double z_in = 0.0) : Neuron(z_in) { }

ReluNeuron::~ReluNeuron() { }

void ReluNeuron::activate()
{
  a = z > 0 ? z : 0;
}