#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 500, "n");
    inf.readSpace();
    int m = inf.readInt(1, 500, "m");
    inf.readEoln();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            inf.readInt(-10000000, 10000000, "a_ij");
            if (j + 1 <= m) {
                inf.readSpace();
            }
        }
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}
