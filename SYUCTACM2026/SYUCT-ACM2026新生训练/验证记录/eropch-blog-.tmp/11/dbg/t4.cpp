#include "testlib.h"
#include <cstdio>
int main(int argc, char* argv[]) {
    (void)argc; (void)argv;
    fprintf(stderr, "A\n");
    fflush(stderr);
    __testlib_ensuresPreconditions();
    fprintf(stderr, "B\n");
    fflush(stderr);
    return 0;
}
