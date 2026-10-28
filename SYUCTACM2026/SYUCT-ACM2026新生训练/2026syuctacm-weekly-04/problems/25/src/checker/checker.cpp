#include "testlib.h"

#include <string>

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    const std::string s = inf.readToken();
    const int n = static_cast<int>(s.size());

    const long long expectedLen = ans.readLong(1LL, static_cast<long long>(n));
    const std::string expectedT = ans.readToken();
    ans.seekEof();
    ans.readEof();

    const long long gotLen = ouf.readLong(1LL, static_cast<long long>(n), "L");
    const std::string gotT = ouf.readToken();
    ouf.seekEof();
    ouf.readEof();

    if (static_cast<int>(gotT.size()) != gotLen) {
        quitf(_wa, "the period string has length %d, which does not match the reported length L = %d",
              static_cast<int>(gotT.size()), static_cast<int>(gotLen));
    }

    if (n % gotLen != 0) {
        quitf(_wa, "the reported length L = %lld does not divide n = %d", gotLen, n);
    }

    // t 必须能把 s 完整重复出来。
    for (int i = 0; i < n; ++i) {
        if (s[i] != gotT[i % gotLen]) {
            quitf(_wa, "s is not made of whole repetitions of the reported period (first mismatch at position %d)", i);
        }
    }

    // L 必须最短：任何更小的可行长度都说明答案不是最短循环节。
    for (int len = 1; len < gotLen; ++len) {
        if (n % len != 0) {
            continue;
        }
        bool ok = true;
        for (int i = len; i < n; ++i) {
            if (s[i] != s[i % len]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            quitf(_wa, "a shorter period of length %d exists", len);
        }
    }

    if (gotLen != expectedLen || gotT != expectedT) {
        quitf(_fail, "contestant output passed the semantic check but differs from the jury answer (%lld %s)",
              expectedLen, expectedT.c_str());
    }

    quitf(_ok, "accepted");
}
