// 错解 B（思路层：只保证行内交替）：每一行都从 A 开始往后交替，
// 行内相邻异色成立，但上下相邻的两行完全相同，违反"上下相邻异色"。
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << ((j % 2 == 1) ? 'A' : 'B');
        }
        cout << '\n';
    }
    return 0;
}
