#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    long long n = inf.readLong(1LL, 200001LL, "n");
    inf.skipBlanks();
    ensuref(n % 2 == 1, "n must be odd, found %lld", n);
    for (long long i = 0; i < n; ++i) {
        inf.readLong(-1000000000LL, 1000000000LL, "a");
        inf.skipBlanks();
    }

    inf.seekEof();
    inf.readEof();
    return 0;
}
