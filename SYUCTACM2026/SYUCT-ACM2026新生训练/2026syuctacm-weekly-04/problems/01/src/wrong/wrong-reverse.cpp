#include <bits/stdc++.h>

using namespace std;

// 思路层：读错题意，把“首字符、尾字符”的顺序颠倒输出。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    cout << s.size() << ' ' << s[s.size() - 1] << ' ' << s[0] << '\n';
    return 0;
}
