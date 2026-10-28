#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    const long long expected = ans.readLong(0LL, 100000LL, "expected answer");
    ans.seekEof();
    ans.readEof();

    const long long actual = ouf.readLong(0LL, 100000LL, "contestant answer");
    ouf.seekEof();
    ouf.readEof();

    if (actual != expected) {
        quitf(_wa, "expected %lld, found %lld", expected, actual);
    }
    quitf(_ok, "accepted");
}
