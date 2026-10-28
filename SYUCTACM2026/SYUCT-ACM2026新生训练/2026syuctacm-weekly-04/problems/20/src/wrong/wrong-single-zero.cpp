#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    long long answer = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            if (n == 1 || m == 1) {
                continue;
            }
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                answer += x;
            }
        }
    }
    cout << answer << '\n';
    return 0;
}
