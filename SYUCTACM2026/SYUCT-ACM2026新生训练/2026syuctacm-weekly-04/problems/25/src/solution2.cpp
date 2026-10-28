#include <bits/stdc++.h>

using namespace std;

// 独立参考解：只枚举 n 的约数作为候选长度。
// t 整次重复 k 次得到 s，则 |s| = k * |t|，所以候选长度一定是 n 的约数。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) {
        return 0;
    }
    const int n = static_cast<int>(s.size());

    // 收集 n 的所有约数并升序排列。
    vector<int> divisors;
    for (int d = 1; d <= n / d; ++d) {
        if (n % d == 0) {
            divisors.push_back(d);
            if (d != n / d) {
                divisors.push_back(n / d);
            }
        }
    }
    sort(divisors.begin(), divisors.end());

    for (const int len : divisors) {
        // s 能由前 len 个字符整次重复得到，当且仅当
        // 每个位置 i 的字符都与向前 len 位的字符相同。
        bool ok = true;
        for (int i = len; i < n; ++i) {
            if (s[i] != s[i - len]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << len << ' ' << s.substr(0, len) << '\n';
            return 0;
        }
    }

    // n 本身一定是约数，循环必然结束。
    return 0;
}
