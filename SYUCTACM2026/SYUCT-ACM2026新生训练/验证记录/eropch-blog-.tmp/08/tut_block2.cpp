#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s, t;
    if (!(std::cin >> s >> t)) {
        return 0;
    }

    const int n = static_cast<int>(s.size());
    const int m = static_cast<int>(t.size());

    std::vector<int> pi(m, 0);          // pi[i] = t[0..i] 的最长真前缀 == 后缀 长度
    for (int i = 1; i < m; ++i) {
        int k = pi[i - 1];
        while (k > 0 && t[i] != t[k]) {
            k = pi[k - 1];
        }
        if (t[i] == t[k]) {
            ++k;
        }
        pi[i] = k;
    }

    int matched = 0;                    // 当前已匹配的 t 的前缀长度
    for (int i = 0; i < n; ++i) {
        while (matched > 0 && s[i] != t[matched]) {
            matched = pi[matched - 1];
        }
        if (s[i] == t[matched]) {
            ++matched;
        }
        if (matched == m) {             // t 是 s[0..i] 的后缀 => 起点 i-m+1
            std::cout << (i - m + 1) << '\n';
            return 0;                   // 首次命中即最小起点
        }
    }

    std::cout << -1 << '\n';
    return 0;
}
