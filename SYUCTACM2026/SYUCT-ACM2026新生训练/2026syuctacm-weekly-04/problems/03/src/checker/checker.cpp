#include "testlib.h"

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    for (int i = 0; i < 5; ++i) {
        long long expected = ans.readLong(0LL, 1000000LL);
        long long actual = ouf.readLong(0LL, 1000000LL);
        if (expected != actual) {
            quitf(_wa, "第 %d 个数不匹配：期望 %lld，得到 %lld", i + 1, expected, actual);
        }
    }
    ans.seekEof();
    ans.readEof();
    ouf.seekEof();
    ouf.readEof();

    quitf(_ok, "accepted");
}
