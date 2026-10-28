#include "testlib.h"

#include <string>

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    const long long expectedLen = ans.readLong();
    const std::string expectedFirst = ans.readWord();
    const std::string expectedLast = ans.readWord();
    ans.seekEof();
    ans.readEof();

    const long long actualLen = ouf.readLong();
    const std::string actualFirst = ouf.readWord();
    const std::string actualLast = ouf.readWord();
    ouf.seekEof();
    ouf.readEof();

    if (actualLen != expectedLen) {
        quitf(_wa, "length: expected %lld, found %lld", expectedLen, actualLen);
    }
    if (actualFirst != expectedFirst) {
        quitf(_wa, "first character: expected \"%s\", found \"%s\"",
              expectedFirst.c_str(), actualFirst.c_str());
    }
    if (actualLast != expectedLast) {
        quitf(_wa, "last character: expected \"%s\", found \"%s\"",
              expectedLast.c_str(), actualLast.c_str());
    }

    quitf(_ok, "accepted");
}
