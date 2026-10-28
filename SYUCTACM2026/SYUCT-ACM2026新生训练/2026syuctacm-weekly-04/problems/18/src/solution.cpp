#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) {
        return 0;
    }

    vector<long long> a(static_cast<size_t>(n) * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[static_cast<size_t>(i) * m + j];
        }
    }

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                cout << ' ';
            }
            cout << a[static_cast<size_t>(i) * m + j];
        }
        cout << '\n';
    }
    return 0;
}
