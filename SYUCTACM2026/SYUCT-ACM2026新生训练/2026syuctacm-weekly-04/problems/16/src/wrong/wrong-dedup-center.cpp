#include <bits/stdc++.h>

using namespace std;

// 思路层：把中心元素理解成"两条对角线共享，只应算一次"，
// 于是用"主 + 副 - 中心"或等价做法把中心从总数里扣掉一次。
// 表现为：n 为奇数且中心非零时，主对角线之和与副对角线之和都被少加了中心。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<long long>> a(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    long long mainSum = 0;
    long long antiSum = 0;
    for (int i = 0; i < n; ++i) {
        mainSum += a[i][i];
        antiSum += a[i][n - 1 - i];
    }

    if (n % 2 == 1) {
        const long long center = a[n / 2][n / 2];
        mainSum -= center;
        antiSum -= center;
    }

    cout << mainSum << '\n' << antiSum << '\n';
    return 0;
}
