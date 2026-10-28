#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    std::string s = inf.readToken();
    ensuref(s.length() >= 1 && s.length() <= 1000000,
            "|s| must be in [1, 1000000], got %zu", s.length());
    for (size_t i = 0; i < s.length(); ++i) {
        unsigned char c = static_cast<unsigned char>(s[i]);
        ensuref((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'),
                "s must consist of English letters only, found byte %u at position %zu",
                static_cast<unsigned>(c), i);
    }
    inf.seekEof();
    inf.readEof();
    return 0;
}
