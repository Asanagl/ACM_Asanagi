#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int n = inf.readInt(1, 100, "n");
    int m = inf.readInt(1, 100, "m");

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int expected = ans.readInt(-1000, 1000, "expected");
            int actual = ouf.readInt(-1000, 1000, "actual");
            if (expected != actual) {
                quitf(_wa, "different value at row %d, column %d: expected %d, found %d", i, j, expected, actual);
            }
        }
    }

    if (!ans.seekEof()) {
        quitf(_fail, "extra token in jury answer");
    }
    if (!ouf.seekEof()) {
        quitf(_wa, "extra output");
    }
    ans.readEof();
    ouf.readEof();
    quitf(_ok, "accepted");
}
