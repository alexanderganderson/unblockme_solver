#include "solver.h"
#include <time.h>

int main() {
    clock_t tStart = clock();
    Solver s;
    s.run();
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}