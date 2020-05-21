#ifndef MATRIX_CLASS
#define MATRIX_CLASS
#include "Matrix.h"
#endif

#include "Layer.h"

class Network
{
private:
  Layer* layers;
  int num_layers;
public:
  Network(int, int*, int*);
  void set_inputs(int *);
  void calculate();
  ~Network();
};

Network::Network(int num_layers_in, int *num_neurons, int *neuron_types)
{
  num_layers = num_layers_in;
  layers = new Layer[num_layers];
  for (int i = 0; i < num_layers; i++)
  {
    layers[i].set_neurons(num_neurons[i], neuron_types[i]);
  }
}

Network::~Network()
{
  delete [] layers;
}

void Network::set_inputs(int *inputs)
{
  layers[0].set_values(inputs);
}

void Network::calculate()
{
  // Print first layer
  int num_neurons_input = layers[0].get_num_neurons();
  cout << "Layer 0:" << endl;
  for (int i = 0; i < num_neurons_input; i++)
  {
    cout << layers[0].get_value(i) << endl;
  }
  for (int i = 1; i < num_layers; i++)
  {
    // Num of neurons of input layer and layer to be calculated
    int num_layers_in = layers[i-1].get_num_neurons();
    int num_layers_out = layers[i].get_num_neurons();

    // Create matrices
    Matrix W(num_layers_out, num_layers_in, 0.1);
    Matrix B(num_layers_out, 1, 0.1);
    Matrix A(num_layers_in, 1, 0.0);
    Matrix Z(num_layers_out, 1, 0.0);

    // Set values of A matrix
    for (int j = 0; j < num_layers_in; j++)
    {
      A.set_value(j, 0, layers[i-1].get_value(j));
    }

    // Calculate Z matrix
    Z = W * A + B;

    // Set Z matrix to next layer
    for (int j = 0; j < num_layers_out; j++)
    {
      layers[i].set_value(j, Z.get_value(j, 0));
    }

    // Activate neurons of output layer
    layers[i].activate_neurons();

    // Print
    cout << "Layer " << i << ":" << endl;
    for (int j = 0; j < num_layers_out; j++)
    {
      cout << layers[i].get_value(j) << endl;
    }
    
  }
   
}