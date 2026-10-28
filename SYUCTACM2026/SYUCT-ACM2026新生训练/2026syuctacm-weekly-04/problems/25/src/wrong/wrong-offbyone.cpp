#include <bits/stdc++.h>

using namespace std;

// 实现层错解：验证循环时循环上界写错（i <= n 而不是 i < n）。
// 1-indexed 思路写成 0-indexed 代码时下意识多走一格，
// s[n] 读到的是字符串末尾的 '\0'，导致所有真正循环的串
// （答案 < n）都被判为不匹配，只能输出 n。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    const int n = static_cast<int>(s.size());

    for (int len = 1; len <= n; ++len) {
        if (n % len != 0) {
            continue;
        }
        bool ok = true;
        for (int i = 0; i <= n; ++i) {
            if (s[i] != s[i % len]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << len << ' ' << s.substr(0, len) << '\n';
            return 0;
        }
    }

    return 0;
}
