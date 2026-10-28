#include <bits/stdc++.h>

using namespace std;

// 实现层：把两条对角线上的元素按"行列下标之和相等"来筛选，
// 误用主对角线条件 j - i == 0 时正确，但把副对角线写成 j - i == n - 1，
// 只取到了最右上角的元素，其余副对角线元素全部漏掉。
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
        for (int j = 0; j < n; ++j) {
            if (j - i == 0) {
                mainSum += a[i][j];
            }
            if (j - i == n - 1) {
                antiSum += a[i][j];
            }
        }
    }

    cout << mainSum << '\n' << antiSum << '\n';
    return 0;
}
