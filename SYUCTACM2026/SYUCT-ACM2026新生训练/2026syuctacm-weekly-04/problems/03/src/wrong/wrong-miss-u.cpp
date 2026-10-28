#include <bits/stdc++.h>

using namespace std;

// 实现层错解：枚举元音集合时漏掉了 u，u/U 永不被统计（第五个输出恒为 0）。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) {
        return 0;
    }

    long long cnt[5] = {};
    for (char c : s) {
        switch (c) {
            case 'a': case 'A': ++cnt[0]; break;
            case 'e': case 'E': ++cnt[1]; break;
            case 'i': case 'I': ++cnt[2]; break;
            case 'o': case 'O': ++cnt[3]; break;
            default: break;
        }
    }

    cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << ' ' << 0 << '\n';
    return 0;
}
