#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int sum = 0; // 错误：行和可达 1e12，int 会溢出
        for (int j = 0; j < m; ++j) {
            int x = 0;
            cin >> x;
            sum += x;
        }
        cout << sum << '\n';
    }
    return 0;
}
