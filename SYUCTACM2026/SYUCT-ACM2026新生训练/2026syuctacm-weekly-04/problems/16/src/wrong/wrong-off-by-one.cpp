#include <bits/stdc++.h>

using namespace std;

// 实现层：副对角线的列号写成 n - i（1 基），少加了 1，
// 于是整体错位一列，并且第 n 行没有任何元素被计入副对角线。
// 注意该写法下标始终落在 1..n 内，不会越界，失败原因是答案错误而非 RE。
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long mainSum = 0;
    long long antiSum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            long long x;
            cin >> x;
            if (j == i) {
                mainSum += x;
            }
            if (j == n - i) {  // 错误：应为 n + 1 - i
                antiSum += x;
            }
        }
    }

    cout << mainSum << '\n' << antiSum << '\n';
    return 0;
}
