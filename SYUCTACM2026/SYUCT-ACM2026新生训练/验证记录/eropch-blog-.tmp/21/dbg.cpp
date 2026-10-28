#include "testlib.h"
#include <cstdio>
int main(int argc, char* argv[]) {
    fprintf(stderr, "start\n");
    registerValidation(argc, argv);
    fprintf(stderr, "registered\n");
    int n = inf.readInt(1, 500, "n");
    fprintf(stderr, "n=%d\n", n);
    inf.readSpace();
    int m = inf.readInt(1, 500, "m");
    fprintf(stderr, "m=%d\n", m);
    inf.readEoln();
    fprintf(stderr, "eoln ok\n");
    return 0;
}
