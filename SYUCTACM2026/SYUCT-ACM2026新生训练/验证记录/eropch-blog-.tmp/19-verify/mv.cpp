#include "testlib.h"
#include <string>
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 500, "n");
    inf.readSpace();
    int m = inf.readInt(1, 500, "m");
    inf.readEoln();
    inf.readEof();
    return 0;
}
