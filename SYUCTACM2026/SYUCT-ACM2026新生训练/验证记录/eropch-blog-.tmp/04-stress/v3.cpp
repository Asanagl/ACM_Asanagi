#include "testlib.h"
#include <string>
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    std::string s = inf.readString();
    std::string d;
    for (char c : s) d += std::to_string((int)(unsigned char)c) + ",";
    quitf(_fail, "len=%d chars=%s", (int)s.size(), d.c_str());
    return 0;
}
