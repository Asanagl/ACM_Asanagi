#include "testlib.h"

#include <string>

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int n = inf.readInt(1, 100, "n");
    inf.readSpace();
    int m = inf.readInt(1, 100, "m");
    inf.readEoln();

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            inf.readInt(-1000, 1000, "a[" + std::to_string(i) + "][" + std::to_string(j) + "]");
            if (j == m) {
                inf.readEoln();
            } else {
                inf.readSpace();
            }
        }
    }
    inf.readEof();
    return 0;
}
