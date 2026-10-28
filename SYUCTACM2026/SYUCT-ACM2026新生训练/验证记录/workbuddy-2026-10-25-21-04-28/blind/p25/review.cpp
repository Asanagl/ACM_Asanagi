#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) return 0;
    int n = (int)s.size();

    // KMP 前缀函数 pi[i] = s[0..i] 的最长真前缀且同时为其后缀的长度
    vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }

    // 最小周期候选
    int cand = n - pi[n - 1];
    int L = n;
    if (n % cand == 0) {
        // 显式验证，防止边界或实现细节问题
        bool ok = true;
        for (int i = cand; i < n; ++i) {
            if (s[i] != s[i % cand]) { ok = false; break; }
        }
        if (ok) L = cand;
    }
    if (L == n) {
        // 再兜底暴力检查（n <= 3000，最多 9e6 次比较）
        for (int len = 1; len < n; ++len) {
            if (n % len) continue;
            bool ok = true;
            for (int i = len; i < n; ++i) {
                if (s[i] != s[i % len]) { ok = false; break; }
            }
            if (ok) { L = len; break; }
        }
    }

    cout << L << " " << s.substr(0, L) << "\n";
    return 0;
}
