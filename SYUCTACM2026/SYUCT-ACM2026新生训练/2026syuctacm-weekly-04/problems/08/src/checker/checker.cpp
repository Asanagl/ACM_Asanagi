#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    const long long expected = ans.readLong();
    ans.seekEof();
    ans.readEof();

    const long long actual = ouf.readLong();
    ouf.seekEof();
    ouf.readEof();

    if (actual != expected) {
        quitf(_wa, "expected %lld, found %lld", expected, actual);
    }

    quitf(_ok, "accepted");
}
