#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    if (!getline(cin, s)) return 0;
    if (!getline(cin, t)) t.clear();

    // 防御式清理行尾可能残留的 CR / LF（Windows 换行）
    auto stripTail = [](string &x) {
        while (!x.empty() && (x.back() == '\r' || x.back() == '\n')) x.pop_back();
    };
    stripTail(s);
    stripTail(t);

    if (t.empty() || t.size() > s.size()) {
        cout << -1 << '\n';
        return 0;
    }

    const int n = (int)s.size();
    const int m = (int)t.size();

    // 计算 t 的前缀函数 pi
    vector<int> pi(m, 0);
    for (int i = 1; i < m; ++i) {
        int j = pi[i - 1];
        while (j > 0 && t[i] != t[j]) j = pi[j - 1];
        if (t[i] == t[j]) ++j;
        pi[i] = j;
    }

    // 在 s 上扫描，首次完整匹配即为最左出现
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j > 0 && s[i] != t[j]) j = pi[j - 1];
        if (s[i] == t[j]) ++j;
        if (j == m) {
            cout << (i - m + 1) << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
    return 0;
}
