#include "a2.hpp"
#include <iostream>
#include <string>

// a2 and a3
// g++ ./a2.hpp ./a2.cpp

using std::cout;
using std::endl;

University::University() {
    this->numStudents = 0;
    this->city = "noWhere";
    this->name = "noName";
}

void University::graduate() {
    if(numStudents > 0)
        numStudents--;
}

void University::newStudent() {
    numStudents++;
}

std::string University::getCity() {
    return city;
}

std::string University::getName() {
    return name;
}

int University::getNumStudents() {
    return numStudents;
}

void University::setCity(std::string _city) {
    city = _city;
}

void University::setName(std::string _name) {
    name = _name;
}

void University::plot() {
    cout << " Name | " << "City | " << "Student count | " << endl;
    cout << name << " | " << city << " | " << numStudents << " | " << endl;
}

int main() {
    University u;
    u.setCity("city Name");
    u.setName("some name");
    u.graduate();
    u.graduate();
    u.graduate();
    u.newStudent();
    u.newStudent();
    u.plot();
    return 0;
}