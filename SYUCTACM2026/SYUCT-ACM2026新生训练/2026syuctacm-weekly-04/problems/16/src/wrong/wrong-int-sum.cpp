#include <bits/stdc++.h>

using namespace std;

// 实现层：用 32 位 int 累加。单个元素不超过 1e9，int 读入没问题，
// 但满规模时和不小于 200 * 1e9 = 2e14，早已溢出，主、副对角线之和都会出错。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int mainSum = 0;
    int antiSum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x;
            cin >> x;
            if (j == i) {
                mainSum += x;
            }
            if (j == n + 1 - i) {
                antiSum += x;
            }
        }
    }

    cout << mainSum << '\n' << antiSum << '\n';
    return 0;
}
