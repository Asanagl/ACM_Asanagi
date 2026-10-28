#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    const int n = inf.readInt();
    inf.readSpace();
    const int m = inf.readInt();

    const long long total = 1LL * n * m;
    for (long long k = 0; k < total; ++k) {
        const long long expected = ans.readLong();
        long long actual = 0;
        if (ouf.curChar() == EOFC) {
            quitf(_wa, "missing element at row %lld, column %lld: expected %lld, found end of output",
                  k / m + 1, k % m + 1, expected);
        }
        actual = ouf.readLong();
        if (expected != actual) {
            quitf(_wa, "row %lld, column %lld: expected %lld, found %lld",
                  k / m + 1, k % m + 1, expected, actual);
        }
    }

    ans.seekEof();
    ans.readEof();
    ouf.seekEof();
    ouf.readEof();

    quitf(_ok, "accepted: all %lld elements match", total);
}
