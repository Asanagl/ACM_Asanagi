#include <bits/stdc++.h>

using namespace std;

// 实现错误：判定逻辑正确，但输出小写单词，不符合输出格式。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    const int n = static_cast<int>(s.size());
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) {
            cout << "no\n";
            return 0;
        }
    }
    cout << "yes\n";
    return 0;
}
