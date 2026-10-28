#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    int m = 0;
    cin >> n >> m;

    vector<vector<long long>> a(n, vector<long long>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int j = 0; j < m; ++j) { // 错误：按列求和并输出 m 个列和
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i][j];
        }
        cout << sum << '\n';
    }
    return 0;
}
