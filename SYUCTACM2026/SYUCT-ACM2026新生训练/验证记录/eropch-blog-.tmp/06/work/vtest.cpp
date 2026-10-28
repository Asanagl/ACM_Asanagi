#include "testlib.h"
#include <string>
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    const std::string s = inf.readToken();
    ensuref(!s.empty() && s.size() <= 1000000, "bad");
    inf.seekEof();
    inf.readEof();
    return 0;
}
