#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n * m);
    for (int i = 0; i < n * m; ++i) {
        cin >> a[i];
    }

    for (int j = 0; j < m; ++j) {
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            int target = i * m + j;
            for (int k = 0; k < n * m; ++k) {
                if (k == target) {
                    sum += a[k];
                    break;
                }
            }
        }
        if (j > 0) {
            cout << ' ';
        }
        cout << sum;
    }
    cout << '\n';
    return 0;
}
