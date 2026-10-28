#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) {
        return 0;
    }

    long long cnt[5] = {};
    const string vowels = "aeiou";

    for (unsigned char raw : s) {
        const char c = char(tolower(raw));
        const size_t pos = vowels.find(c);
        if (pos != string::npos) {
            ++cnt[pos];
        }
    }

    cout << cnt[0] << ' ' << cnt[1] << ' ' << cnt[2] << ' ' << cnt[3] << ' ' << cnt[4] << '\n';
    return 0;
}
