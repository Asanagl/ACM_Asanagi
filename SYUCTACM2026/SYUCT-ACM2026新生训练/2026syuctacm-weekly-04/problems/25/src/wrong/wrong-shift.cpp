#include <bits/stdc++.h>

using namespace std;

// 思路层错解：把"循环单元"误当成"平移周期"。
// 只要求 s[i] == s[i+L]（不整除、允许末尾残缺），
// 例如 "abababa" 会输出 2，但正确答案应为 7。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    const int n = static_cast<int>(s.size());

    for (int len = 1; len <= n; ++len) {
        bool ok = true;
        for (int i = 0; i + len < n; ++i) {
            if (s[i] != s[i + len]) {
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
