#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s)) {
        return 0;
    }

    long long answer = 0;
    for (char c : s) {
        answer += c - '0';
    }
    cout << answer << '\n';
    return 0;
}
