#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto& row : a) {
        for (int& x : row) {
            cin >> x;
        }
    }

    long long answer = 0;
    for (int j = 0; j < m; ++j) {
        answer += a[0][j] + a[n - 1][j];
    }
    for (int i = 0; i < n; ++i) {
        answer += a[i][0] + a[i][m - 1];
    }
    cout << answer << '\n';
    return 0;
}
