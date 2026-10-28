// 棋盘染色 —— 主解：直接用 (i+j) 的奇偶写出闭式答案。
// 由 (1,1)=A 且相邻异色可推出 (i,j) 的颜色只取决于 i+j 的奇偶：
// i+j 为偶数（含 (1,1)）染 A，为奇数染 B。
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0;
    if (!(cin >> n >> m)) {
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << (((i + j) % 2 == 0) ? 'A' : 'B');
        }
        cout << '\n';
    }
    return 0;
}
