#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    char x, y;
    std::cin >> s >> x >> y;

    for (std::size_t i = 0; i < s.size(); ++i) {
        if (s[i] == x) {
            s[i] = y;
        }
    }

    std::cout << s << '\n';
    return 0;
}
