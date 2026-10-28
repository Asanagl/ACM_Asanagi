// 思路层错解：只截到第 r 个字符之前的"感觉"，把 [l, r] 误读成 [l, n]，
// 也就是只用了左端点，完全忽略右端点 r。
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int l = 0, r = 0;
    cin >> s >> l >> r;
    cout << s.substr(l - 1) << '\n';
    return 0;
}
