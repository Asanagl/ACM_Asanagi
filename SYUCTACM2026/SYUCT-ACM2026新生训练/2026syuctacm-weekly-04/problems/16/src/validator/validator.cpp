#include "testlib.h"

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    // 第一行：方阵阶数 n
    const int n = inf.readInt(1, 200, "n");
    inf.readEoln();

    // 接下来 n 行，每行恰好 n 个整数，行内用一个空格分隔
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inf.readLong(-1000000000LL, 1000000000LL, "a_ij");
            if (j + 1 < n) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
    }

    inf.readEof();
    return 0;
}
