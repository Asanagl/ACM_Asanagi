#include <bits/stdc++.h>

using namespace std;

// 复杂度错误：判定逻辑正确（s[i] 与反转串的第 i 个字符相同，等价于 s[i] == s[n-1-i]），
// 但每检查一个位置都重新逐字符构造一次完整反转串，
// 复杂度从 O(n) 退化到 O(n^2)，在长度上限的回文数据上稳定超时。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    const size_t n = s.size();
    for (size_t i = 0; i < n; ++i) {
        string reversed;
        reversed.reserve(n);
        for (size_t j = n; j-- > 0;) {
            reversed.push_back(s[j]);
        }
        if (s[i] != reversed[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
