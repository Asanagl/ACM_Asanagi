#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int L = 2 * n - 1;
        vector<char> forced(L + 1, 0);
        bool tri = false;
        for (int i = 0; i < m; i++) {
            long long x;
            cin >> x;
            if (x > L)
                tri = true;
            else
                forced[(int)x] = 1;
        }
        if (tri) {
            cout << 0 << endl;
            continue;
        }
        vector<int> dp(n + 2, 0);
        dp[0] = 1;
        int cur = 0;
        for (int v = 1; v <= L; v++) {
            if (forced[v]) {
                for (int j = cur; j >= 0; j--) {
                    if (j < n && v <= 2 * (j + 1) - 1) {
                        dp[j + 1] = dp[j];
                    } else {
                        dp[j + 1] = 0;
                    }
                }
                dp[0] = 0;
                if (cur < n)
                    cur++;
            } else {
                for (int j = cur; j >= 0; j--) {
                    if (j < n && v <= 2 * (j + 1) - 1) {
                        dp[j + 1] += dp[j];
                        if (dp[j + 1] >= MOD)
                            dp[j + 1] -= MOD;
                    }
                }
                if (cur < n)
                    cur++;
            }
        }

        cout << dp[n] % MOD << endl;
    }
}
