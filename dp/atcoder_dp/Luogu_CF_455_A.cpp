#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 2e9+10;

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        vector<int> a(n);
        a[0] = v[0];
        for (int i = 1; i < n; i++)
            a[i] = a[i - 1] + v[i];
        int S = a[n - 1];
        vector<int> sq;
        for (int i = 0; i * i <= S; i++)
        {
            sq.push_back(i * i);
        }

        int m = sq.size();

        vector<vector<int>> dp(S + 1, vector<int>(m, INF));
        for (int j = 0; j < m; j++)
        {
            if (sq[j] <= S)
            {
                int cost = (n == 1) ? 0 : abs(a[0] - sq[j]);
                dp[sq[j]][j] = cost;
            }
        }
        for (int pos = 2; pos <= n; pos++)
        {
            vector<vector<int>> ndp(S + 1, vector<int>(m, INF));
            vector<vector<int>> pdx_min(S + 1, vector<int>(m, INF));
            for (int s = 0; s <= S; s++)
            {
                pdx_min[s][0] = dp[s][0];
                for (int j = 1; j < m; j++)
                {
                    pdx_min[s][j] = min(pdx_min[s][j - 1], dp[s][j]);
                }
            }
            for (int s = 0; s <= S; s++)
            {
                for (int j = 0; j < m; j++)
                {
                    int new_s = s + sq[j];
                    if (new_s > S)
                        break;
                    if (pdx_min[s][j] >= INF)
                        continue;
                    int cost = (pos == n) ? 0 : abs(a[pos - 1] - new_s);
                    ndp[new_s][j] = min(ndp[new_s][j], pdx_min[s][j] + cost);
                }
            }
            dp.swap(ndp);
        }
        int ans = INF;
        for (int j = 0; j < m; j++)
        {
            ans = min(ans, dp[S][j]);
        }

        if (ans >= INF)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}