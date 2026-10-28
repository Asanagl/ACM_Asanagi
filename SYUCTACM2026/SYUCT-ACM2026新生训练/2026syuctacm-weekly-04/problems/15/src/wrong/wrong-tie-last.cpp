// 思路错误：把"第一次出现"理解成"最后一次出现"，用 >= 更新。
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
            if (i == 1 && j == 1) {
                best = x;
            } else if (x >= best) {
                best = x;
                bestRow = i;
                bestCol = j;
            }
        }
    }

    cout << best << ' ' << bestRow << ' ' << bestCol << '\n';
    return 0;
}
