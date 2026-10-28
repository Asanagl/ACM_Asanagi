// 实现层错解：循环上界写成 r-1，漏掉第 r 个字符（把闭区间当成右开）。
// 只有 l=r 时才碰巧正确。
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    long long l = 0, r = 0;
    cin >> s >> l >> r;
    string answer;
    for (long long i = l - 1; i < r - 1; ++i) {
        answer += s[i];
    }
    cout << answer << '\n';
    return 0;
}
