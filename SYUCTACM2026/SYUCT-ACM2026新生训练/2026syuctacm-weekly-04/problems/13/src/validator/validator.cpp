#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    const int n = inf.readInt(1, 1000, "n");
    inf.readSpace();
    const int m = inf.readInt(1, 1000, "m");
    inf.readEoln();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            inf.readLong(-1000000000LL, 1000000000LL, "a_ij");
            if (j + 1 < m) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
    }
    inf.readEof();
    return 0;
}
