#include "testlib.h"

#include <string>

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    std::string s = inf.readLine();
    inf.ensuref(!s.empty(), "s must not be empty");
    inf.ensuref(s.size() <= 100000u, "|s| exceeds 100000: %d",
                static_cast<int>(s.size()));
    for (size_t i = 0; i < s.size(); ++i) {
        inf.ensuref(s[i] >= 'a' && s[i] <= 'z',
                    "s[%d] is not a lowercase letter between 'a' and 'z'",
                    static_cast<int>(i));
    }

    inf.readEof();
    return 0;
}
