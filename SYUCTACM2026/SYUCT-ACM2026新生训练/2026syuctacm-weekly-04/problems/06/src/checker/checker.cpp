#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    std::string expected = ans.readToken();
    ans.seekEof();
    ans.readEof();

    std::string actual = ouf.readToken();
    ouf.seekEof();
    ouf.readEof();

    if (expected != actual) {
        quitf(_wa, "expected \"%s\", found \"%s\"", expected.c_str(), actual.c_str());
    }

    quitf(_ok, "accepted");
}
