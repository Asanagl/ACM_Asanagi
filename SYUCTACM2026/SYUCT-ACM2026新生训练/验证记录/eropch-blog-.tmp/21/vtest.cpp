#include "testlib.h"
#include <string>
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int n = inf.readInt(1, 500, "n");
    inf.readSpace();
    int m = inf.readInt(1, 500, "m");
    for (int i = 1; i <= n; ++i) {
        std::string row = inf.readToken();
        ensuref((int)row.size() == m, "row %d len %d != %d", i, (int)row.size(), m);
    }
    inf.readEof();
    return 0;
}
