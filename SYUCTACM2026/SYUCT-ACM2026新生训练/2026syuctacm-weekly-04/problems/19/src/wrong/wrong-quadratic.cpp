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

    for (int r = 0; r < m; ++r) {
        for (int c = 0; c < n; ++c) {
            int value = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (i == n - 1 - c && j == r) {
                        value = a[i][j];
                    }
                }
            }
            if (c > 0) {
                cout << ' ';
            }
            cout << value;
        }
        cout << '\n';
    }
    return 0;
}
