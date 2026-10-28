#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    inf.readInt(1, 1000, "n");
    inf.readSpace();
    inf.readInt(1, 1000, "m");
    inf.seekEof();
    inf.readEof();
    return 0;
}
