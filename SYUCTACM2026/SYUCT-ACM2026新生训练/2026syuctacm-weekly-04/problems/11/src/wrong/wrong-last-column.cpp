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
        for (int& value : row) {
            cin >> value;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            if (j > 0) {
                cout << ' ';
            }
            cout << a[i][j];
        }
        cout << '\n';
    }
    return 0;
}
