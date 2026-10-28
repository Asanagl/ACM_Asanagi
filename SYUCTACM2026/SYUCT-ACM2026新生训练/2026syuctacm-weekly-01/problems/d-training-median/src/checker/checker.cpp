#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    long long expectedMedian = ans.readLong();
    long long expectedDistance = ans.readLong();
    ans.seekEof();
    ans.readEof();

    long long actualMedian = ouf.readLong();
    long long actualDistance = ouf.readLong();
    ouf.seekEof();
    ouf.readEof();

    if (expectedMedian != actualMedian || expectedDistance != actualDistance) {
        quitf(_wa, "expected %lld %lld, found %lld %lld", expectedMedian,
              expectedDistance, actualMedian, actualDistance);
    }

    quitf(_ok, "accepted");
}
