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

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j > 0) {
                cout << ' ';
            }
            cout << a[static_cast<size_t>(i) * m + j];
        }
        cout << '\n';
    }
    return 0;
}
