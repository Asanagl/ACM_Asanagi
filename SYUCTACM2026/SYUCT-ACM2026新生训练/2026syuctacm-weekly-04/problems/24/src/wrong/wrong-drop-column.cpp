// 错解 D（实现层：循环上界少一）：行内循环写 j < m 而列号从 1 开始，
// 每行少输出最后一个字符，整份输出长度不足。
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < m; ++j) {  // 少输出第 m 列
            cout << (((i + j) % 2 == 0) ? 'A' : 'B');
        }
        cout << '\n';
    }
    return 0;
}
