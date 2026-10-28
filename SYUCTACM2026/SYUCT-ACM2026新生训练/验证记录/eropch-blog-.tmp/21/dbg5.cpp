#include "testlib.h"
#include <cstdio>
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 500, "n");
    fprintf(stderr, "n=%d\n", n);
    inf.readSpace();
    int m = inf.readInt(1, 500, "m");
    fprintf(stderr, "m=%d\n", m);
    fprintf(stderr, "curChar=%d eoln=%d eof=%d\n", inf.curChar(), (int)inf.eoln(), (int)inf.eof());
    inf.readEoln();
    fprintf(stderr, "eoln ok\n");
    std::string row = inf.readToken();
    fprintf(stderr, "row=%s\n", row.c_str());
    return 0;
}
