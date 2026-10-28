#include <bits/stdc++.h>

using namespace std;

// 思路错误：把"各位数字之和"与"反复压缩到一位的数根"混淆。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    long long answer = 0;
    for (char c : s) {
        answer += c - '0';
    }
    while (answer >= 10) {
        long long t = 0;
        while (answer > 0) {
            t += answer % 10;
            answer /= 10;
        }
        answer = t;
    }
    cout << answer << '\n';
    return 0;
}
