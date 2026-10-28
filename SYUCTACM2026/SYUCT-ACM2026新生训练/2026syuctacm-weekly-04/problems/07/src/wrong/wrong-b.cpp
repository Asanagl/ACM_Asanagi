#include <bits/stdc++.h>

using namespace std;

// 思路错误：把「回文」误解成「偶数长度的镜像」，
// 认为奇数长度的字符串一律不是回文串。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    const int n = static_cast<int>(s.size());
    if (n % 2 == 1) {
        cout << "NO\n";
        return 0;
    }

    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
