#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> a(static_cast<size_t>(n) * m);
    for (long long &value : a) {
        cin >> value;
    }

    if (n == m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                swap(a[static_cast<size_t>(i) * m + j],
                     a[static_cast<size_t>(j) * m + i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j > 0) {
                    cout << ' ';
                }
                cout << a[static_cast<size_t>(i) * m + j];
            }
            cout << '\n';
        }
    } else {
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if (i > 0) {
                    cout << ' ';
                }
                cout << a[static_cast<size_t>(i) * m + j];
            }
            cout << '\n';
        }
    }
    return 0;
}
