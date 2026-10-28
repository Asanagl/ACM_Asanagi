// 实现层错解：忘记把题面的 1 起始编号转成 C++ 的 0 起始下标，
// substr 的起点整体右移了一位，并且会越界抛出 std::out_of_range。
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int l = 0, r = 0;
    cin >> s >> l >> r;
    cout << s.substr(l, r - l + 1) << '\n';
    return 0;
}
