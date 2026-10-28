#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    const int n = static_cast<int>(s.size());
    const int m = static_cast<int>(t.size());

    int answer = -1;
    for (int i = 0; i + m <= n; ++i) {
        bool ok = true;
        for (int j = 0; j + 1 < m; ++j) {
            if (s[i + j] != t[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            answer = i;
            break;
        }
    }

    cout << answer << '\n';
    return 0;
}
