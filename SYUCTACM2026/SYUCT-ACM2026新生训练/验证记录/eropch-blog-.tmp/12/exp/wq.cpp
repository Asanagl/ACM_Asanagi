#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    for (auto& row : a) {
        for (int& x : row) {
            cin >> x;
        }
    }
    for (auto& row : b) {
        for (int& x : row) {
            cin >> x;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = 0;
            int y = 0;
            for (int p = 0; p < n; ++p) {
                for (int q = 0; q < m; ++q) {
                    if (p == i && q == j) {
                        x = a[p][q];
                    }
                }
            }
            for (int p = 0; p < n; ++p) {
                for (int q = 0; q < m; ++q) {
                    if (p == i && q == j) {
                        y = b[p][q];
                    }
                }
            }
            if (j > 0) {
                cout << ' ';
            }
            cout << x + y;
        }
        cout << '\n';
    }
    return 0;
}
