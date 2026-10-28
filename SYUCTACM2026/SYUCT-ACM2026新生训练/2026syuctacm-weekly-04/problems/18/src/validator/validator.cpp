#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    const int n = inf.readInt(1, 100, "n");
    inf.readSpace();
    const int m = inf.readInt(1, 100, "m");
    inf.readEoln();

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            inf.readLong(-1000000000LL, 1000000000LL, "a_ij");
            if (j < m) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
    }

    inf.readEof();
    return 0;
}
