#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    if (!(cin >> n >> s)) {
        return 0;
    }

    int answer = 0;
    for (int i = 1; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) {
            ++answer;
        }
    }
    cout << answer << '\n';
    return 0;
}
