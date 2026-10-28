#include "testlib.h"

#include <string>

// 唯一输出题：选手输出忽略整体首尾空白后，必须恰好是一个 token（子串本身），
// 且与参考答案逐字符相同；任何额外内容都判 WA。
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    const std::string expected = ans.readToken();
    ans.seekEof();
    ans.readEof();

    const std::string actual = ouf.readToken();
    if (actual != expected) {
        quitf(_wa, "expected \"%s\", found \"%s\"", expected.c_str(), actual.c_str());
    }
    ouf.seekEof();
    ouf.readEof();

    quitf(_ok, "accepted");
    return 0;
}
