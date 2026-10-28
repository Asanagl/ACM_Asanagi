#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) {
        return 0;
    }
    const int n = static_cast<int>(s.size());

    // 从短到长枚举候选长度 len：只有 len 整除 n 时才可能是整次重复，
    // 再逐字符验证 s[i] 是否等于循环单元中的对应字符 s[i % len]。
    for (int len = 1; len <= n; ++len) {
        if (n % len != 0) {
            continue;
        }
        bool ok = true;
        for (int i = len; i < n; ++i) {
            if (s[i] != s[i % len]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << len << ' ' << s.substr(0, len) << '\n';
            return 0;
        }
    }

    return 0;
}
