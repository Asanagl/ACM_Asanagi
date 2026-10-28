#include "testlib.h"

#include <string>

// 输出唯一：恰好 n 行、每行恰好 m 个 0..4 的整数，顺序与网格一致；不允许多余或缺失的整数。
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    const int n = inf.readInt();
    const int m = inf.readInt();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            const int expected = ans.readInt(0, 4);
            const int actual = ouf.readInt(0, 4);
            if (expected != actual) {
                quitf(_wa, "cell (%d, %d): expected %d, found %d", i + 1, j + 1, expected, actual);
            }
        }
    }

    if (!ans.seekEof()) {
        quitf(_fail, "jury answer has extra data");
    }
    if (!ouf.seekEof()) {
        quitf(_wa, "participant output has extra data");
    }

    quitf(_ok, "accepted");
}
