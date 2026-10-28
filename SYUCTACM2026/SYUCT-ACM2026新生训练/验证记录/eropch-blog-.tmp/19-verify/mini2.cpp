#include "testlib.h"
#include <cstdio>
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n = rnd.next(1, 5);
    long long s = 0;
    for (int i = 0; i < n; ++i) s += rnd.next(1, 100);
    printf("%d %lld\n", n, s);
    return 0;
}
