#include "testlib.h"

#include <string>

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    std::string s = inf.readWord("[a-z]+", "s");
    ensuref(s.length() >= 1 && s.length() <= 1000,
            "|s| must be in [1, 1000], found %d", static_cast<int>(s.length()));
    inf.seekEof();
    inf.readEof();
    return 0;
}
