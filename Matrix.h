#ifndef MATRIX_CLASS
#define MATRIX_CLASS
#endif

#include <iostream>
using namespace std;

class Matrix
{
private:
  unsigned col_size;
  unsigned row_size;
  double **values;
public:
  Matrix(unsigned, unsigned, double);
  Matrix(const Matrix &in);
  ~Matrix();
  Matrix operator*(Matrix &);
  Matrix operator+(Matrix &);
  void set_values(double);
  void set_value(unsigned, unsigned, double);
  double get_value(unsigned, unsigned) const;
  unsigned get_rows() const;
  unsigned get_cols() const;
  void print();
};

Matrix::Matrix(unsigned row_size_in, unsigned col_size_in, double values_in = 0.0)
{
  col_size = col_size_in;
  row_size = row_size_in;
  values = new double*[row_size];
  for (int i = 0; i < row_size; i++)
    values[i] = new double[col_size];
  set_values(values_in);
}

Matrix::Matrix(const Matrix &in)
{
  col_size = in.get_cols();
  row_size = in.get_rows();
  for (int i = 0; i < row_size; i++)
    for (int j = 0; j < col_size; j++)
      values[i][j] = in.get_value(i, j);
}

Matrix::~Matrix()
{
  for (int i = 0; i < row_size; i++)
    delete [] values[i];
  delete [] values;
}

void Matrix::set_values(double values__in)
{
  for (int i = 0; i < row_size; i++)
    for (int j = 0; j < col_size; j++)
      values[i][j] = values__in;
}

void Matrix::set_value(unsigned row, unsigned col, double value__in)
{
  values[row][col] = value__in;
}

Matrix Matrix::operator*(Matrix &in)
{
  Matrix result(row_size, in.get_cols(), 0.0);
  if(col_size == in.get_rows())
  {
    double temp;
    for (int i = 0; i < row_size; i++)
      for (int j = 0; j < in.get_cols(); j++)
      {
        temp = 0.0;
        for (int k = 0; k < col_size; k++)
          temp += get_value(i, k) * in.get_value(k, j);
        result.set_value(i, j, temp);
      }
    return result;
  }
  else
  {
    throw "Matrix sizes does not match for multiplication";
  }
}

Matrix Matrix::operator+(Matrix &in)
{
  if(col_size != in.col_size || row_size != in.row_size)
    throw "Matrix sizes does not match for addition";

  Matrix result(row_size, col_size, 0.0);
  unsigned i,j;
  for (i = 0; i < row_size; i++)
    for (j = 0; j < col_size; j++)
      result.set_value(i, j, ( get_value(i, j) + in.get_value(i, j) ));
  return result;
}

unsigned Matrix::get_cols() const
{
  return col_size;
}

unsigned Matrix::get_rows() const
{
  return row_size;
}

double Matrix::get_value(unsigned row, unsigned col) const
{
  return values[row][col];
}

void Matrix::print()
{
  for (int i = 0; i < row_size; i++) {
    for (int j = 0; j < col_size; j++)
      cout << values[i][j] << " ";
    cout << endl;
  }
    
  
}