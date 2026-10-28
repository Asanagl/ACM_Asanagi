// 错解 A（思路层：起点约束反了）：知道"相邻异色"，但把 (1,1) 染成 B 而不是 A，
// 整张棋盘相对正确答案整体平移一位。
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << (((i + j) % 2 == 0) ? 'B' : 'A');
        }
        cout << '\n';
    }
    return 0;
}
