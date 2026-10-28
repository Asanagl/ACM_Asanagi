// 主解：直接用 std::string::substr 截取闭区间 [l, r]。
// 题面的编号从 1 开始，C++ 下标从 0 开始，所以起点是 l - 1；
// substr 的第二个参数是"字符个数"，闭区间 [l, r] 共有 r - l + 1 个字符。
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int l = 0, r = 0;
    cin >> s >> l >> r;

    cout << s.substr(static_cast<size_t>(l - 1), static_cast<size_t>(r - l + 1)) << '\n';
    return 0;
}
