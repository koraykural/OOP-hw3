#include <iostream>

#ifndef NEURON_CLASS
#include "Neuron.h"
#define NEURON_CLASS
#endif

#include "SigmoidNeuron.h"
#include "ReluNeuron.h"
#include "LReluNeuron.h"

using namespace std;

class Layer
{
private:
  Neuron **neurons;
  int num_neurons;
public:
  Layer();
  ~Layer();
  void set_neurons(int, int);
  void set_value(int, double);
  void set_values(int *);
  double get_value(int);
  int get_num_neurons();
  void activate_neurons();
};

Layer::Layer() { }

Layer::~Layer()
{
  for (int i = 0; i < num_neurons; i++)
  {
    delete neurons[i];
  }
  delete [] neurons;
}

void Layer::set_neurons(int num_neurons_in, int neuron_type)
{
  num_neurons = num_neurons_in;
  // Allocate array of pointers
  neurons = new Neuron*[num_neurons];

  for (int i = 0; i < num_neurons; i++)
  {
    if(neuron_type == 0)
    {
      neurons[i] = new SigmoidNeuron(); 
    }
    else if(neuron_type == 1)
    {
      neurons[i] = new ReluNeuron();
    }
    else if(neuron_type == 2)
    {
      neurons[i] = new ReluNeuron();
    }
    else
    {
      cerr << "Invalid neuron type";
      exit(1);
    }
  }
}

void Layer::set_values(int *values_in)
{
  for (int i = 0; i < num_neurons; i++)
  {
    neurons[i]->set_a(values_in[i]);
    neurons[i]->set_z(values_in[i]);
  }
}

void Layer::set_value(int neuron_index, double value_in)
{
  neurons[neuron_index]->set_z(value_in);
}

int Layer::get_num_neurons()
{
  return num_neurons;
}

double Layer::get_value(int neuron_index)
{
  return neurons[neuron_index]->get_a();
}

void Layer::activate_neurons()
{
  for (int i = 0; i < num_neurons; i++)
  {
    neurons[i]->activate();
  }
}