#include <bits/stdc++.h>
using namespace std;

/*
 * 回文修补
 * 统计满足 i < j 且 s[i] != s[j] 的对称位置对数（j = n-1-i 固定）。
 */
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n = 0;
    if (!(cin >> n)) return 0;

    string s;
    cin >> s;

    long long len = (long long)s.size();
    long long half = len / 2;
    long long ans = 0;
    for (long long i = 0; i < half; ++i) {
        if (s[(size_t)i] != s[(size_t)(len - 1 - i)]) ++ans;
    }

    cout << ans << '\n';
    return 0;
}
