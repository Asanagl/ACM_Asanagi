// 思路层错解：把闭区间 [l,r] 误当成半开区间 [l,r)，长度少取 1。
// 只要区间内字符数大于 1（l<r）就会少输出最后一个字符。
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int l = 0, r = 0;
    cin >> s >> l >> r;
    cout << s.substr(l - 1, r - l) << '\n';
    return 0;
}
