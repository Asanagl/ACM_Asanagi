#include <bits/stdc++.h>

using namespace std;

// 思路错误：把 '0' 当成结束标志，遇到 0 就停止累加。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    long long answer = 0;
    for (char c : s) {
        if (c == '0') {
            break;
        }
        answer += c - '0';
    }
    cout << answer << '\n';
    return 0;
}
