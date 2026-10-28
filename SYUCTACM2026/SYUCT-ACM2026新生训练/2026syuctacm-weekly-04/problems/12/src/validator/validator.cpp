#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    const int n = inf.readInt(1, 300, "n");
    inf.readSpace();
    const int m = inf.readInt(1, 300, "m");
    inf.readEoln();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            inf.readInt(-1000000, 1000000, "a_ij");
            if (j + 1 < m) {
                inf.readSpace();
            }
        }
        inf.readEoln();
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            inf.readInt(-1000000, 1000000, "b_ij");
            if (j + 1 < m) {
                inf.readSpace();
            }
        }
        inf.readEoln();
    }

    inf.readEof();
    return 0;
}
