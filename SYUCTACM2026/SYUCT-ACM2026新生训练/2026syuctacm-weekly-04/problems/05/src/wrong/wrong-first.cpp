#include <bits/stdc++.h>

// 思路错误：题意是“替换所有”，这里只替换了第一个出现的 x。
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    char x, y;
    std::cin >> s >> x >> y;

    std::size_t pos = s.find(x);
    if (pos != std::string::npos) {
        s[pos] = y;
    }
    std::cout << s << '\n';
    return 0;
}
