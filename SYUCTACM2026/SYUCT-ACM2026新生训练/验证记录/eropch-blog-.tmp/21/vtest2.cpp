#include "testlib.h"
#include <string>
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 500, "n");
    inf.readSpace();
    int m = inf.readInt(1, 500, "m");
    fprintf(stderr, "after m curChar=%d (%c)\n", inf.curChar(), (char)inf.curChar());
    std::string row = inf.readToken();
    fprintf(stderr, "row=%s\n", row.c_str());
    inf.readEof();
    return 0;
}
