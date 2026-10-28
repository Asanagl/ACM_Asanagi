// 错解 C（思路层：只保证列间交替）：颜色只由行号决定，整行同色，
// 上下相邻异色成立，但行内相邻的格子同色。
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        const char c = (i % 2 == 1) ? 'A' : 'B';
        for (int j = 1; j <= m; ++j) {
            cout << c;
        }
        cout << '\n';
    }
    return 0;
}
