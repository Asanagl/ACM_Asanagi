#include <bits/stdc++.h>

using namespace std;

// 思路层：漏读输出要求，只输出长度，缺少首字符和尾字符。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    cout << s.size() << '\n';
    return 0;
}
