#include "testlib.h"

#include <cstddef>
#include <string>

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    const std::string s = inf.readLine();
    ensuref(s.size() <= 100000, "line length must not exceed 100000");
    for (std::size_t i = 0; i < s.size(); ++i) {
        const unsigned char c = static_cast<unsigned char>(s[i]);
        ensuref(c >= 32 && c <= 126,
                "character at zero-based position %d must be printable ASCII", i);
    }
    inf.readEof();
    return 0;
}
