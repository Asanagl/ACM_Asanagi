#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        long long sum = 0;
        for (int j = 0; j < m; ++j) {
            sum += a[i][j];
        }
        if (i > 0) {
            cout << ' ';
        }
        cout << sum;
    }
    cout << '\n';
    return 0;
}
