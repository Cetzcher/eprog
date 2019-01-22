#ifndef IVECTOR
#define IVECTOR

#include "Fraction.hpp"

class IVector {

    private:
        int* items;
        int length;

        void copyValsToThis(const IVector& ref);


    public:
        IVector(int n);
        IVector(const IVector& rhs);

        ~IVector();

        IVector& operator=(const IVector& rhs);

        int getCoef(int idx) const;
        void setCoef(int idx, int val);
        int getLength() const;

        static IVector* primefactors(int m);

        void print() const;
};

#endif