#include <bits/stdc++.h>

using namespace std;

// 思路层错解：误解“不区分大小写”，只统计小写元音，漏掉 A/E/I/O/U。
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
            case 'a': ++cnt[0]; break;
            case 'e': ++cnt[1]; break;
            case 'i': ++cnt[2]; break;
            case 'o': ++cnt[3]; break;
            case 'u': ++cnt[4]; break;
            default: break;
        }
    }

    cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << ' ' << cnt[4] << '\n';
    return 0;
}
