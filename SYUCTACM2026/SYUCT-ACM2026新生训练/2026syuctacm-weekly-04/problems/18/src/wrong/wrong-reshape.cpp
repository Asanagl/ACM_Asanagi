#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> values(static_cast<size_t>(n) * m);
    for (long long &value : values) {
        cin >> value;
    }

    size_t next = 0;
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                cout << ' ';
            }
            cout << values[next++];
        }
        cout << '\n';
    }
    return 0;
}
