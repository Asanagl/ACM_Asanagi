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
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int j = 0; j < m; ++j) {
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i][j];
        }
        if (j > 0) {
            cout << ' ';
        }
        cout << sum;
    }
    cout << '\n';
    return 0;
}
