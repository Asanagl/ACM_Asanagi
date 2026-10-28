#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        return 0;
    }

    string s;
    cin >> s;

    const int m = static_cast<int>(s.size());
    int answer = 0;
    for (int i = 0; i < m / 2; ++i) {
        if (s[i] != s[m - 1 - i]) {
            ++answer;
        }
    }

    cout << answer << '\n';
    return 0;
}
