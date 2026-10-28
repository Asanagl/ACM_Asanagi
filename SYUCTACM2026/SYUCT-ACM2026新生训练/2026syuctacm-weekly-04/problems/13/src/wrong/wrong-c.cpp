#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    int m = 0;
    cin >> n >> m;

    long long sum = 0; // 错误：只初始化一次，没有逐行重置
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            long long x = 0;
            cin >> x;
            sum += x;
        }
        cout << sum << '\n'; // 输出的是跨行前缀和，不是当前行的和
    }
    return 0;
}
