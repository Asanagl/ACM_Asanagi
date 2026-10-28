#include <bits/stdc++.h>

using namespace std;

// 实现层错解：C/C++ 逻辑运算符误用。`c == 'a' || 'e'` 中 'e' 是非零整型常量，
// 整个表达式恒为真，导致每个字符都被当作全部五种元音统计。
static bool isVowel(char c) {
    return c == 'a' || 'e' || 'i' || 'o' || 'u';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) {
        return 0;
    }

    long long cnt[5] = {};
    for (char c : s) {
        if (isVowel(c)) {
            ++cnt[0];
            ++cnt[1];
            ++cnt[2];
            ++cnt[3];
            ++cnt[4];
        }
    }

    cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << ' ' << cnt[4] << '\n';
    return 0;
}
