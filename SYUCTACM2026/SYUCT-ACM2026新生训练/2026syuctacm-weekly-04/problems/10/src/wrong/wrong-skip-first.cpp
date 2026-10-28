#include <bits/stdc++.h>

using namespace std;

// 实现错误：循环从 1 开始，漏掉第一个字符。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    long long answer = 0;
    for (size_t i = 1; i < s.size(); ++i) {
        answer += s[i] - '0';
    }
    cout << answer << '\n';
    return 0;
}
