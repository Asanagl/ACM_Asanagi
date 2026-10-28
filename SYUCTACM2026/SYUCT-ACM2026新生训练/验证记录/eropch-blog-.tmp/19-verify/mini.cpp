#include "testlib.h"
#include <cstdio>
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    printf("%d\n", rnd.next(1, 10));
    return 0;
}
