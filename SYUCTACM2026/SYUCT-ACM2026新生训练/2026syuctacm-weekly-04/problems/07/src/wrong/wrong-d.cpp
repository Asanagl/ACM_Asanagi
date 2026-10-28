#include <bits/stdc++.h>

using namespace std;

// 思路错误：只比较首尾一对字符，内部的错配全部漏判。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    const int n = static_cast<int>(s.size());
    if (s[0] != s[n - 1]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}
