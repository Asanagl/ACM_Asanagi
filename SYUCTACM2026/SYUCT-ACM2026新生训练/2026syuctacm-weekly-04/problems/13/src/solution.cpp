#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        long long sum = 0;
        for (int j = 0; j < m; ++j) {
            long long x = 0;
            cin >> x;
            sum += x;
        }
        cout << sum << '\n';
    }
    return 0;
}
