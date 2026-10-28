#include "testlib.h"
#include <cstdio>
int main(int argc, char* argv[]) {
    fprintf(stderr, "before registerGen\n");
    registerGen(argc, argv, 1);
    fprintf(stderr, "after registerGen argc=%d\n", argc);
    fprintf(stderr, "arg1=%s\n", argc>1?argv[1]:"(null)");
    return 0;
}
