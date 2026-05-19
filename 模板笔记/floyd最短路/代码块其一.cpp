#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
int main()
{
    int n, m;
    cin >> n >> m;
    int dp[105][105];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = INF;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, j;
        cin >> u >> v >> j;
        dp[u][v] = min(dp[u][v], j);
        dp[v][u] = min(dp[v][u], j);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}
