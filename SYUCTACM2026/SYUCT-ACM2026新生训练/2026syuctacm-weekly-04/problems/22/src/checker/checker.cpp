// 子矩阵求和 —— checker：输出唯一，按顺序比较 q 个整数，忽略 token 间空白差异。
#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    long long n = inf.readLong(1LL, 100LL, "n");
    long long m = inf.readLong(1LL, 100LL, "m");
    long long q = inf.readLong(1LL, 1000LL, "q");
    for (long long i = 0; i < n * m; ++i) {
        inf.readLong(-1000000000LL, 1000000000LL);
    }
    for (long long k = 0; k < q; ++k) {
        inf.readLong(1LL, n);
        inf.readLong(1LL, m);
        inf.readLong(1LL, n);
        inf.readLong(1LL, m);
    }

    for (long long k = 1; k <= q; ++k) {
        long long expected = ans.readLong();
        long long actual = ouf.readLong();
        if (expected != actual) {
            quitf(_wa, "query %lld: expected %lld, found %lld", k, expected, actual);
        }
    }

    if (!ans.seekEof()) {
        quitf(_fail, "reference answer has extra tokens after query %lld", q);
    }
    if (!ouf.seekEof()) {
        quitf(_wa, "extra output after query %lld", q);
    }

    quitf(_ok, "accepted: %lld queries matched", q);
}
