#include <bits/stdc++.h>

using namespace std;

// 思路层错解：误认为 y 也是元音，并把 y/Y 的个数计入 i 的槽位。
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
            case 'y': case 'Y': ++cnt[2]; break;
            case 'o': case 'O': ++cnt[3]; break;
            case 'u': case 'U': ++cnt[4]; break;
            default: break;
        }
    }

    cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << ' ' << cnt[4] << '\n';
    return 0;
}
