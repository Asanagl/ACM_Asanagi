#include <bits/stdc++.h>
using namespace std  ;
#define int long long 
int dp[200005][35];
inline void solve()
{
    int n, k;
    cin >> n >> k, k *= 2;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j <= k; j++)
        {
            if (j & 1)
                ans = max(ans, dp[i][j] = max(dp[i - 1][j] + b, (j != 0 ? dp[i - 1][j - 1] + b : 0)));
            else
                ans = max(ans, dp[i][j] = max(dp[i - 1][j] + a, (j != 0 ? dp[i - 1][j - 1] + a : 0)));
        }
    }
    cout << ans;
}
signed main ()
{
    int t = 1;
    // cin >> t;
    while (t--)
    solve() ;
}