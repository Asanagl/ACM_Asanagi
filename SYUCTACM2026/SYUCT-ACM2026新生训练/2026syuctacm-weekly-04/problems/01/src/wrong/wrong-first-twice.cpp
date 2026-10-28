#include <bits/stdc++.h>

using namespace std;

// 实现层：首尾都取 s[0]，误以为最后一个字符也是 s[0]。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    cout << s.size() << ' ' << s[0] << ' ' << s[0] << '\n';
    return 0;
}
