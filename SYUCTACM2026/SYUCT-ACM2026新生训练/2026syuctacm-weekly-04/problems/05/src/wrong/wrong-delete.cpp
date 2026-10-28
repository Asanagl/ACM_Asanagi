#include <bits/stdc++.h>

// 思路错误：把“替换”理解成了“删除”，丢掉了所有 x。
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    char x, y;
    std::cin >> s >> x >> y;

    std::string t;
    for (char c : s) {
        if (c != x) {
            t.push_back(c);
        }
    }
    std::cout << t << '\n';
    return 0;
}
