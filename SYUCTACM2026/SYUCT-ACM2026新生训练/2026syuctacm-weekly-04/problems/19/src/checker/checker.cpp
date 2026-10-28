#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int n = inf.readInt(1, 500, "n");
    inf.readSpace();
    int m = inf.readInt(1, 500, "m");

    for (int r = 1; r <= m; ++r) {
        for (int c = 1; c <= n; ++c) {
            long long expected = ans.readLong(-1000000000LL, 1000000000LL, "expected");
            long long actual = ouf.readLong(-1000000000LL, 1000000000LL, "actual");
            if (expected != actual) {
                quitf(_wa, "element (%d, %d): expected %lld, found %lld", r, c, expected, actual);
            }
        }
    }

    ans.seekEof();
    ans.readEof();
    ouf.seekEof();
    ouf.readEof();
    quitf(_ok, "accepted");
}
