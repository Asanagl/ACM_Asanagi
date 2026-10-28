#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    inf.readToken("[a-z]{1,3000}", "s");
    inf.readEoln();
    inf.readEof();
    return 0;
}
