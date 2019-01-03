#ifndef A2
#define A2

#include <string>

class University {

    private: 
        int numStudents;
        std::string city;
        std::string name;

    public: 
        University();

        void graduate();
        void newStudent();
        void plot();

        std::string getCity();
        std::string getName();
        int getNumStudents();

        void setCity(std::string city);
        void setName(std::string name);
        

};

#endif