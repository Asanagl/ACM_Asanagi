#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    inf.readLong(1LL, 1000000LL, "n");
    inf.seekEof();
    inf.readEof();
    return 0;
}
