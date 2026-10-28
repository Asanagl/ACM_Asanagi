#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }

    vector<vector<int>> a(n, vector<int>(m));
    for (auto& row : a) {
        for (int& x : row) {
            cin >> x;
        }
    }

    long long answer = 0;
    for (int j = 0; j < m; ++j) {
        answer += a[0][j];
    }
    if (n > 1) {
        for (int j = 0; j < m; ++j) {
            answer += a[n - 1][j];
        }
    }
    for (int i = 1; i + 1 < n; ++i) {
        answer += a[i][0];
        if (m > 1) {
            answer += a[i][m - 1];
        }
    }

    cout << answer << '\n';
    return 0;
}
