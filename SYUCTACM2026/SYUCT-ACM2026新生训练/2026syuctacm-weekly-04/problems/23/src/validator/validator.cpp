#include "testlib.h"

#include <string>

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    const int n = inf.readInt(1, 200000, "n");
    inf.readEoln();

    const std::string s = inf.readToken("[a-z]{1,200000}", "s");
    inf.readEoln();

    ensuref(static_cast<int>(s.size()) == n,
            "length of s must equal n=%d, found %d", n, static_cast<int>(s.size()));

    inf.readEof();
    return 0;
}
