#include "testlib.h"

#include <string>

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    std::string s = inf.readToken("[0-9]+", "s");
    ensuref(s.size() >= 1 && s.size() <= 100000,
            "|s| must be in [1, 100000], found %d", static_cast<int>(s.size()));
    inf.seekEof();
    inf.readEof();
    return 0;
}
