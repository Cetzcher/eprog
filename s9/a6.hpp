#ifndef A6_H
#define A6_H

/*
00  01  02
10  11  12
20  21  22

wenn die formel stimmt
idx(j, k) = j * (j+1) / 2 + k

dann ist idx(1, 2) = idx(2, 0)

Zeilenweise?
[00, 10, 20, 01, 11, 21, 02, 12, 22]
  0   1   2   3   4   5   6   7   8

Spaltenweise
[00, 01, 02, 10, 11, 12, 20, 21, 22]
  0  1   2   3   4   5   6   7   8
*/

class MatrixL {

    private: 
        double* coeff;
        int dim;
    
        int calcSize();
        int calcIndex(int j, int k);
        bool isWithinBounds(int j, int k);

    public:
        MatrixL(int N);
        ~MatrixL();

        void setVal(int j, int k, double val);
        double getVal(int j, int k);

        int getDimension();

        static MatrixL* scan(int n);
        void print();
        double colSumNorm();
        double rowSumNorm();

};

#endif