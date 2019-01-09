#ifndef A5
#define A5

#include <ctime>

class Stopwatch {

    private:
        clock_t start;
        clock_t end;
        bool started;

    public:
        Stopwatch();
        void startStop();
        void print();
        void reset();

};

#endif
