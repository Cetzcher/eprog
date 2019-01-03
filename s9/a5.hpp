#ifndef A5
#define A5

#include <time.h>

class Stopwatch {

    private:
        timespec start;
        timespec stop;
        bool started;

    public:
        Stopwatch();
        void startStop();
        void print();
        void reset();

};

#endif
