// 实现错误：best 初值取 0，全负矩阵会输出一个矩阵里不存在的值。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    long long best = 0;
    int bestRow = 1;
    int bestCol = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            long long x;
            cin >> x;
            if (x > best) {
                best = x;
                bestRow = i;
                bestCol = j;
            }
        }
    }

    cout << best << ' ' << bestRow << ' ' << bestCol << '\n';
    return 0;
}
