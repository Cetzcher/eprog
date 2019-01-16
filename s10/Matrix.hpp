#ifndef MATRIX
#define MATRIX

#include "Vector.hpp"

class Matrix
{
  public:
    enum Type
    {
        F,
        L,
        U
    };

    Matrix();
    Matrix(int dim, Matrix::Type type, double lower, double upper);
    Matrix(int dim, Matrix::Type type);
    ~Matrix();

    double getEntry(int i, int j);
    void setEntry(int i, int j, double val);

    double columnSumNorm();
    double rowSumNorm();

    void print();
    void scan();

    static Matrix* createMatrix(int n, Matrix::Type type);

    Matrix operator* (const Vector& vec);
    int getSize() const;

  private:

    int calcSize();
    int calcIndex(int i, int j);
    bool isInBounds(int i, int j);

    void init(int dim, Matrix::Type type);
    double* arr;
    int dim;
    Matrix::Type type;
};



#endif