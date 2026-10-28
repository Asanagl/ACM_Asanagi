// 截取一段：输出 s 的第 l 个字符到第 r 个字符（闭区间）
#include <cstdio>
#include <string>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    long long l = 0, r = 0;

    // 读取字符串与左右端点。使用 operator>> 自动跳过所有空白，
    // 因此行尾空格、空行、CRLF 换行都不会影响解析。
    if (!(std::cin >> s >> l >> r)) return 0;

    // 防御性处理：即使输入越界也不崩溃（题面保证 1 <= l <= r <= |s|）
    long long n = (long long)s.size();
    if (l < 1) l = 1;
    if (r > n) r = n;
    if (l > r) { std::printf("\n"); return 0; }

    // 第 l 个字符对应下标 l-1，长度是 r-l+1
    std::string ans = s.substr((size_t)(l - 1), (size_t)(r - l + 1));

    std::printf("%s\n", ans.c_str());
    return 0;
}
