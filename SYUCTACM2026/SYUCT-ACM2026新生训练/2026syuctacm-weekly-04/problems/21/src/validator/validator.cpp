#include "testlib.h"

#include <string>

// 校验格式：第一行两个整数 n,m（1..500），随后 n 行，每行一个长度恰为 m 的 0/1 串。
int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    const int n = inf.readInt(1, 500, "n");
    inf.readSpace();
    const int m = inf.readInt(1, 500, "m");
    inf.readEoln();

    for (int i = 1; i <= n; ++i) {
        const std::string row = inf.readToken();
        ensuref(static_cast<int>(row.size()) == m,
                "row %d must have exactly %d characters, found %d", i, m,
                static_cast<int>(row.size()));
        for (int j = 0; j < m; ++j) {
            ensuref(row[j] == '0' || row[j] == '1',
                    "row %d position %d must be '0' or '1', found '%c'", i, j + 1, row[j]);
        }
        inf.readEoln();
    }

    inf.readEof();
    return 0;
}
