#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    const long long expectedValue = ans.readLong();
    const long long expectedRow = ans.readLong();
    const long long expectedCol = ans.readLong();
    ans.seekEof();
    ans.readEof();

    const long long actualValue = ouf.readLong();
    const long long actualRow = ouf.readLong();
    const long long actualCol = ouf.readLong();
    ouf.seekEof();
    ouf.readEof();

    if (actualValue != expectedValue) {
        quitf(_wa, "maximum value: expected %lld, found %lld", expectedValue, actualValue);
    }
    if (actualRow != expectedRow) {
        quitf(_wa, "row of the first occurrence: expected %lld, found %lld",
              expectedRow, actualRow);
    }
    if (actualCol != expectedCol) {
        quitf(_wa, "column of the first occurrence: expected %lld, found %lld",
              expectedCol, actualCol);
    }

    quitf(_ok, "accepted");
}
