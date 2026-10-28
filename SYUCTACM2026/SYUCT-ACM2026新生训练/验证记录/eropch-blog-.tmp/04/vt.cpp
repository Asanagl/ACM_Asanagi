#include "testlib.h"
#include <string>
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    inf.strict = false;
    std::string s = inf.readLine();
    inf.ensuref(!s.empty() && s.size() <= 1000, "len %d", (int)s.size());
    for (size_t i = 0; i < s.size(); ++i) {
        unsigned char c = (unsigned char)s[i];
        inf.ensuref(c >= 32 && c <= 126, "bad %d at %d", (int)c, (int)i);
    }
    inf.readEof();
    return 0;
}
