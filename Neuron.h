/*
* Author
* Koray Kural
* 150170053
*/
class Neuron
{
protected:
  double z;
  double a;
public:
  Neuron(double);
  virtual void activate() = 0;
  void set_z(double);
  void set_a(double);
  double get_a();
};

Neuron::Neuron(double z_in)
{
  z = z_in;
}

double Neuron::get_a()
{
  return a;
}

void Neuron::set_z(double in)
{
  z = in;
}

void Neuron::set_a(double in)
{
  a = in;
}