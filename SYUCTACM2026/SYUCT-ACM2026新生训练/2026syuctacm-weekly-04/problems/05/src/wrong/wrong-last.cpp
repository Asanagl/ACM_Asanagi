#include <bits/stdc++.h>

// 实现错误：循环上界差一，最后一个字符永远不会被检查/替换。
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    char x, y;
    std::cin >> s >> x >> y;

    for (int i = 0; i + 1 < (int)s.size(); ++i) {
        if (s[i] == x) {
            s[i] = y;
        }
    }
    std::cout << s << '\n';
    return 0;
}
