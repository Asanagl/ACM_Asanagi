#include "testlib.h"
#include <string>
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    std::string s = inf.readLine();
    fprintf(stderr, "[dbg] len=%d last=%d\n", (int)s.size(), s.empty()?-1:(int)s.back());
    inf.readEof();
    return 0;
}
