#include "testlib.h"
#include <string>

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    // The whole input is one raw line of printable ASCII, so tolerate both LF
    // and CRLF line endings: strict mode only accepts CRLF when testlib is
    // built for Windows, and on LF-only data eoln() never becomes true.
    inf.strict = false;

    const std::string s = inf.readLine();

    inf.ensuref(!s.empty(), "s must contain at least 1 character, found 0");
    inf.ensuref(s.size() <= 1000, "s must contain at most 1000 characters, found %d",
                static_cast<int>(s.size()));
    for (size_t i = 0; i < s.size(); ++i) {
        const unsigned char c = static_cast<unsigned char>(s[i]);
        inf.ensuref(c >= 32 && c <= 126, "s[%d] must be a printable ASCII character in [32, 126], found %d",
                    static_cast<int>(i + 1), static_cast<int>(c));
    }

    inf.readEof();
    return 0;
}
