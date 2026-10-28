#include <cstdio>
#include <string>
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    long long ans = 0;
    // 逐字符读入，只累加数字字符，忽略空白与可能的 '\r'
    while (std::cin >> s) {
        for (char c : s) {
            if (c >= '0' && c <= '9') ans += (c - '0');
        }
    }
    std::cout << ans << '\n';
    return 0;
}
