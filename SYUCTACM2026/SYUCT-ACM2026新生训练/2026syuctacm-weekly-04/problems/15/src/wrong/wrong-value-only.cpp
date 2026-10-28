// 思路错误：只输出最大值，忽略题目要求的位置。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    long long best = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            long long x;
            cin >> x;
            if (i == 0 && j == 0) {
                best = x;
            } else {
                best = max(best, x);
            }
        }
    }

    cout << best << '\n';
    return 0;
}
