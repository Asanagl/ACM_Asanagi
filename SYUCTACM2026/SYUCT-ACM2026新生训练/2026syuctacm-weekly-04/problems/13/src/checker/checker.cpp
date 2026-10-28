#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    const int n = inf.readInt(1, 1000);
    inf.readInt(1, 1000);

    for (int i = 1; i <= n; ++i) {
        const long long expected = ans.readLong();
        const long long actual = ouf.readLong();
        if (expected != actual) {
            quitf(_wa, "line %d: expected %lld, found %lld", i, expected, actual);
        }
    }

    if (!ouf.seekEof()) {
        quitf(_wa, "expected exactly %d integers, found extra output", n);
    }
    if (!ans.seekEof()) {
        quitf(_fail, "official answer contains extra output");
    }

    quitf(_ok, "accepted");
}
