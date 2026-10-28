#include <bits/stdc++.h>

using namespace std;

// 思路正确但实现错误：直接累加字符编码，忘记做 -'0' 转换。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    long long answer = 0;
    for (char c : s) {
        answer += c;
    }
    cout << answer << '\n';
    return 0;
}
