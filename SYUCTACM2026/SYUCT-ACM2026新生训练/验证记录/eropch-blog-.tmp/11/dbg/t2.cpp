#include "testlib.h"
#include <cstdio>
int main(int argc, char* argv[]) {
    fprintf(stderr, "start argc=%d\n", argc); fflush(stderr);
    registerGen(argc, argv, 1);
    fprintf(stderr, "after register\n"); fflush(stderr);
    printf("ok\n");
    return 0;
}
