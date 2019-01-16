#ifndef VECTOR
#define VECTOR

class Vector {
    private: 
        double* arr;
        int size;

    public: 

        Vector(int size);
        ~Vector();
        int getSize() const;
        double get(int i) const;
        void set(int i, double v);
        void print();
};

#endif