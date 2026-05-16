#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl '\n'
#define int long long
#define ld long double
const int INF = 1e9;
const int LINF = 1e18;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

void Asanagi()
{
        int n;
        string s;
        cin >> n >> s;
        int O = n / 2;
        int index = n;
        vector<vector<int>> dp(n + 1, vector<int>(2 * n + 1, -INF));
        dp[0][index] = 0;
        for (char c : s) {
            int val = (c == '(') ? 1 : -1;
            for (int j = n - 1; j >= 0; j--) {
                for (int d = -j; d <= j; d++) {
                    if (dp[j][d + index] > -INF) {
                        int nd = d + val;
                        int nmin = min(dp[j][d + index], d + val);
                        if (nmin > dp[j + 1][nd + index])
                            dp[j + 1][nd + index] = nmin;
                    }
                }
            }
        }
        int ans = n;
        for (int j = n; j >= 0; j--) {
            for (int d = -j; d <= j; d++) {
                if (dp[j][d + index] > -INF) {
                    if (j - d <= n) {
                        int x = (j + d) / 2;
                        if (x <= O + dp[j][d + index]) {
                            ans = n - j;
                            j = -1;
                            break;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
}

signed main()
{
    IOS;
    int t  ;
    cin >> t;
    while (t--)
    {
            Asanagi();
        }
    return 0;
}


