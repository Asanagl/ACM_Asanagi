#include <bits/stdc++.h>

// 实现错误：把“把 x 换成 y”写反成了“把 y 换成 x”。
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    char x, y;
    std::cin >> s >> x >> y;

    for (char &c : s) {
        if (c == y) {
            c = x;
        }
    }
    std::cout << s << '\n';
    return 0;
}
