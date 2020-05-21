#include <iostream>
#include <string>
#include "Network.h"

using namespace std;

void readFile(char* filename, int &num_layers, int *&num_neurons, int *&neuron_types, int *&inputs);
void free_memory(int *&num_neurons, int *&neuron_types, int *&inputs);


int main(int argc, char *argv[])
{
  // Check number of arguments provided
  if(argc != 2) {
    cerr << "One argument is expected!";
		exit(1);
  }

  // Get file name
  char* filename = argv[1];

  int num_layers;
  int *num_neurons, *neuron_types, *inputs;

  try
  {
    readFile(filename, num_layers, num_neurons, neuron_types, inputs);
  }
  catch(const char* msg)
  {
    cerr << msg << endl;
    free_memory(num_neurons, neuron_types, inputs);
    exit(1);
  }

  Network network(num_layers, num_neurons, neuron_types);

  network.set_inputs(inputs);
  network.calculate();

  free_memory(num_neurons, neuron_types, inputs);
  return 0;
}




void readFile(char* filename, int &num_layers, int *&num_neurons, int *&neuron_types, int *&inputs)
{
  // Open file
  FILE *file;
  if( !(file = fopen( filename, "r+" )) )
  {
    throw "File couldnot be opened";
  }
  else
  {
    fscanf(file, "%d", &num_layers); 

    num_neurons = new int(num_layers);
    for (int i = 0; i < num_layers; i++)
    {
      fscanf(file, "%d", &num_neurons[i]);
    }

    neuron_types = new int(num_layers);
    for (int i = 0; i < num_layers; i++)
    {
      fscanf(file, "%d", &neuron_types[i]);
      if(neuron_types[i] < 0 || neuron_types[i] > 2)
        throw "Unidentified activation function!";
    }

    inputs = new int(num_neurons[0]);
    for (int i = 0; i < num_neurons[0]; i++)
    {
      fscanf(file, "%d", &inputs[i]);
      if(feof(file) && i != num_neurons[0] - 1)
        throw "Input shape does not match!";
    }
    
    if(!feof(file))
      throw "Input shape does not match!";

    fclose(file);
  }
}

void free_memory(int *&num_neurons, int *&neuron_types, int *&inputs)
{
  delete [] num_neurons;
  delete [] neuron_types;
  delete [] inputs;
}