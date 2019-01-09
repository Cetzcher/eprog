#include "a5.hpp"
#include <ctime>
#include <iostream>
#include <cmath>
#include <unistd.h>
#include <iomanip>

using namespace std;

Stopwatch::Stopwatch() {
    started = false;
}

void Stopwatch::startStop() {
    if(started) {
        // stop the clock here, calc time
        end = clock();
    } else {
        start = clock();
    }
    started = !started;
}

void Stopwatch::reset() {
    started = false;
}

void Stopwatch::print() {
    auto diffTimeMS = floor(((double)(end - start)) / CLOCKS_PER_SEC * 1000);
    auto ms = fmodf(diffTimeMS, 1000);
    auto secs = diffTimeMS / 1000;
    auto mins = secs / 60;
    auto hrs = mins / 60;
    secs = floor(fmodf(secs, 60)), mins = floor(fmodf(mins, 60)), hrs = floor(fmodf(hrs, 24));

    cout << "Stopwatch time: " << setfill('0') << setw(2) << hrs
            << ":" << setw(2) << mins 
            << ":" << setw(2) << secs 
            << ":" << setw(3) << ms 
            << endl; 
}


void testFunc() {
    double sum;
    for(int j=0; j<100*1000*1000; ++j)
        sum += 1./j;
}

void jpower3() {
    long double res = 0;
    for(int i = 0; i < 100 * 1000 * 1000; i++) {
        res += pow(i, 3);
    }
}

void jpower3noPow() {
    long double res = 0;
    for(int i = 0; i < 100 * 1000 * 1000; i++) {
        res += i * i * i;
    }
}

int main() {
    cout << "starting" << endl;
    Stopwatch S;
    S.startStop();
    testFunc();
    S.startStop();
    S.print();
    S.reset();
    cout << "sum(pow(j, 3)):" << endl;
    S.startStop();
    jpower3();
    S.startStop();
    S.print();
    S.reset();
    cout << "sum( j * j * j)" << endl;
    S.startStop();
    jpower3noPow();
    S.startStop();
    S.print();
}