#include <bits/stdc++.h>

using namespace std;

// 实现错误：右下标写成 n - 1，但循环在 l + 1 < r 时就停止，
// 漏掉长度 2 与偶数长度最中心的那一对字符。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int l = 0;
    int r = static_cast<int>(s.size()) - 1;
    while (l + 1 < r) {
        if (s[l] != s[r]) {
            cout << "NO\n";
            return 0;
        }
        ++l;
        --r;
    }
    cout << "YES\n";
    return 0;
}
