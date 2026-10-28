#include <bits/stdc++.h>

using namespace std;

// 实现层：混淆“最后一个字符的下标”和“长度”，把 size() - 1 当作长度输出。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    cout << s.size() - 1 << ' ' << s[0] << ' ' << s[s.size() - 1] << '\n';
    return 0;
}
