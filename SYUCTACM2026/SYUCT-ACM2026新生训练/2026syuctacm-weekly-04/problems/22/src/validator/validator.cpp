#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    const long long MAXV = 1000000000LL;

    long long n = inf.readLong(1LL, 100LL, "n");
    inf.skipBlanks();
    long long m = inf.readLong(1LL, 100LL, "m");
    inf.skipBlanks();
    long long q = inf.readLong(1LL, 1000LL, "q");
    inf.skipBlanks();

    for (long long i = 1; i <= n; ++i) {
        for (long long j = 1; j <= m; ++j) {
            inf.readLong(-MAXV, MAXV, format("a_%lld_%lld", i, j));
            inf.skipBlanks();
        }
    }

    for (long long k = 1; k <= q; ++k) {
        long long r1 = inf.readLong(1LL, n, format("r1_%lld", k));
        inf.skipBlanks();
        long long c1 = inf.readLong(1LL, m, format("c1_%lld", k));
        inf.skipBlanks();
        long long r2 = inf.readLong(1LL, n, format("r2_%lld", k));
        inf.skipBlanks();
        long long c2 = inf.readLong(1LL, m, format("c2_%lld", k));
        inf.skipBlanks();

        ensuref(r1 <= r2, "query %lld: r1 (%lld) must be <= r2 (%lld)", k, r1, r2);
        ensuref(c1 <= c2, "query %lld: c1 (%lld) must be <= c2 (%lld)", k, c1, c2);
    }

    inf.seekEof();
    inf.readEof();
    return 0;
}
