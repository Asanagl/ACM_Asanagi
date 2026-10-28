#include <cstdio>
#include <cctype>
#include <string>
#include <algorithm>

int main() {
    // 读入全部标准输入
    static char inbuf[1 << 21];
    size_t len = std::fread(inbuf, 1, sizeof(inbuf), stdin);

    // 过滤掉一切空白字符（行末 LF / CRLF、可能的行首尾空白、EOF 前后空行）
    std::string s;
    s.reserve(len);
    for (size_t i = 0; i < len; ++i) {
        unsigned char c = (unsigned char)inbuf[i];
        if (c == ' ' || c == '\t' || c == '\n' || c == '\r' ||
            c == '\v' || c == '\f') {
            continue;
        }
        s.push_back((char)c);
    }

    // 原地反转
    std::reverse(s.begin(), s.end());

    // 输出答案 + 换行
    std::fwrite(s.data(), 1, s.size(), stdout);
    std::fputc('\n', stdout);
    return 0;
}
