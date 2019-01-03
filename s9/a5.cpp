#include "a5.hpp"
#include <time.h>
#include <iostream>
#include <math.h>
#include <unistd.h>

Stopwatch::Stopwatch() {
    started = false;
    passedTime = 0;
}

void Stopwatch::startStop() {
    if(started) {
        // stop the clock here, calc time
        clock_gettime(CLOCK_MONOTONIC_RAW, &stop);
        std::cout << CLOCKS_PER_SEC << std::endl;

    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    started = !started;
}

void Stopwatch::reset() {
    started = false;
    passedTime = 0;
}

void Stopwatch::print() {
    uint64_t delta_us = (stop.tv_sec - start.tv_sec) * 1000000 + (stop.tv_nsec - start.tv_nsec) / 1000;
    long millis / 
    long mins, sec, hr;
    long millis = (long)fmodf(passedTime, 1000);
    sec = passedTime / 1000;
    mins = passedTime / 60 / 1000;
    hr = passedTime / 3600 / 1000;
    char buffer[13];
    sprintf(buffer, "%02ld:%02ld:%02ld:%03ld", hr, mins, sec, millis);
    std::cout << "Stopwatch time: " << buffer << " unformated: " << passedTime << std::endl;
}


int main() {
    std::cout << "starting" << std::endl;
    Stopwatch S;
    S.startStop();
    usleep(3000000);
    S.startStop();
    S.print();

    double sum = 0.0;
    S.startStop();
    for(int j=0; j<100*1000*1000; ++j)
    sum += 1./j;
    S.startStop();
    S.print();
    S.reset();
    

}