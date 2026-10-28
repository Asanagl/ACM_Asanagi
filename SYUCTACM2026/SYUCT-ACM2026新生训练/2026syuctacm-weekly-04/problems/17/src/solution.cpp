#include <algorithm>
#include <iostream>
#include <vector>

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

    for (int i = 0; i < n; ++i) {
        reverse(a[i].begin(), a[i].end());
        for (int j = 0; j < m; ++j) {
            if (j != 0) {
                cout << ' ';
            }
            cout << a[i][j];
        }
        cout << '\n';
    }

    return 0;
}
