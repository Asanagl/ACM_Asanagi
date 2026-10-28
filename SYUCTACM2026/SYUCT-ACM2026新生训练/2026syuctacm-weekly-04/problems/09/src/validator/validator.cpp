#include "testlib.h"

#include <string>

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    // 第一行：字符串 s，仅含小写字母，长度在 [1, 1000]
    const std::string s = inf.readToken("[a-z]{1,1000}", "s");
    ensuref(s.size() >= 1 && s.size() <= 1000,
            "length of s must be in [1, 1000], found %d", (int)s.size());
    inf.readEoln();

    // 第二行：两个正整数 l, r，满足 1 <= l <= r <= |s|
    const long long l = inf.readLong(1LL, (long long)s.size(), "l");
    inf.readSpace();
    const long long r = inf.readLong(1LL, (long long)s.size(), "r");
    ensuref(l <= r, "must have l <= r, found l=%lld r=%lld", l, r);
    inf.readEoln();

    inf.readEof();
    return 0;
}
