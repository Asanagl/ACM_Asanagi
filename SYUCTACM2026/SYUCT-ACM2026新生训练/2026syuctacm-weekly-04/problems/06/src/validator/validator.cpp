#include "testlib.h"

#include <string>

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    const std::string s = inf.readToken();
    inf.ensuref(!s.empty() && s.size() <= 1000000,
                "|s| must be in [1, 1000000], found %d", static_cast<int>(s.size()));
    for (size_t i = 0; i < s.size(); ++i) {
        const unsigned char c = static_cast<unsigned char>(s[i]);
        inf.ensuref((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'),
                    "s[%d] must be a lowercase English letter or a digit, found character code %d",
                    static_cast<int>(i + 1), static_cast<int>(c));
    }

    inf.seekEof();
    inf.readEof();
    return 0;
}
