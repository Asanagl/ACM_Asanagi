// 思路层错解：把闭区间右端点 r 直接当成 substr 的长度参数。
// substr(pos, len) 的第二个参数是"长度"，本写法只在 r = r-l+1（即 l = 1）时才偶然正确。
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int l = 0, r = 0;
    cin >> s >> l >> r;
    cout << s.substr(l - 1, r) << '\n';
    return 0;
}
