#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    inf.readInt();
    int m = inf.readInt();
    for (int j = 0; j < m; ++j) {
        long long expected = ans.readLong();
        long long actual = ouf.readLong();
        if (expected != actual) {
            quitf(_wa, "column %d: expected %lld, found %lld", j + 1, expected, actual);
        }
    }

    ans.seekEof();
    ans.readEof();
    ouf.seekEof();
    ouf.readEof();
    quitf(_ok, "accepted");
}
