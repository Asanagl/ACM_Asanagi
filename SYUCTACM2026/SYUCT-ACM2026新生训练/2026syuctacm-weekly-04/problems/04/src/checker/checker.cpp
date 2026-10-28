#include "testlib.h"
#include <string>

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    const std::string expected = ans.readLine();
    ans.readEof();
    const std::string actual = ouf.readLine();

    if (actual != expected) {
        quitf(_wa, "output line differs from the unique answer");
    }
    ouf.readEof();
    quitf(_ok, "accepted");
}
