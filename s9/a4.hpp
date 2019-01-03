#ifndef A4_H
#define A4_H

class Triangle {

    private:
        double a[2];
        double b[2];
        double c[2];

        double getSideA();
        double getSideB();
        double getSideC();

    public:
        void setX(double, double);
        void setY(double, double);
        void setZ(double, double);
        double area();
        double getPerimeter();
        bool isEquilateral();

};

#endif
