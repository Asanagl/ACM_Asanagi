#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    long long expectedYear = ans.readLong();
    long long expectedMonth = ans.readLong();
    long long expectedDay = ans.readLong();
    ans.seekEof();
    ans.readEof();

    long long actualYear = ouf.readLong();
    long long actualMonth = ouf.readLong();
    long long actualDay = ouf.readLong();
    ouf.seekEof();
    ouf.readEof();

    if (expectedYear != actualYear || expectedMonth != actualMonth ||
        expectedDay != actualDay) {
        quitf(_wa, "expected %lld %lld %lld, found %lld %lld %lld",
              expectedYear, expectedMonth, expectedDay, actualYear,
              actualMonth, actualDay);
    }

    quitf(_ok, "accepted");
}
