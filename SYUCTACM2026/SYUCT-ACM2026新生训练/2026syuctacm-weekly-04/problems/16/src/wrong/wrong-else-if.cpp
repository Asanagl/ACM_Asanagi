#include <bits/stdc++.h>

using namespace std;

// 实现层：用 else if 判断，n 为奇数时中心位置只进第一个分支，
// 导致副对角线之和漏掉中心元素。
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
            } else if (j == n + 1 - i) {
                antiSum += x;
            }
        }
    }

    cout << mainSum << '\n' << antiSum << '\n';
    return 0;
}
