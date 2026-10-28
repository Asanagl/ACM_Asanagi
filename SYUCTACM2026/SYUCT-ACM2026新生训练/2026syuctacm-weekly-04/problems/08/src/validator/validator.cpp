#include "testlib.h"

#include <string>

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    const std::string s = inf.readWord("[a-z]+", "s");
    inf.readEoln();
    const std::string t = inf.readWord("[a-z]+", "t");
    inf.readEoln();

    ensuref(s.length() >= 1 && s.length() <= 10000,
            "|s| must be in [1, 10000], found %d", static_cast<int>(s.length()));
    ensuref(t.length() >= 1 && t.length() <= 10000,
            "|t| must be in [1, 10000], found %d", static_cast<int>(t.length()));
    ensuref(t.length() <= s.length(),
            "|t| must not exceed |s|: |s|=%d, |t|=%d",
            static_cast<int>(s.length()), static_cast<int>(t.length()));

    inf.readEof();
    return 0;
}
