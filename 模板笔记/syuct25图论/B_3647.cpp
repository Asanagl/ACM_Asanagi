#include <bits/stdc++.h>
using namespace std ;
const int N = 105 ;
const int INF = 1e9 + 10 ;
int main ()
{
    int n , m ;
    cin >> n >> m ;
    int dp[N][N] ;
    for (int i = 1 ; i <= n  ;i++)
    {
        for (int j = 1 ; j <= n ; j ++)
        {
            if (i == j ) dp[i][j] = 0 ;
            else dp[i][j] = INF ;
        }
    }
    for (int i = 1 ; i <= m ; i++)
    {
        int u , v , w ;
        cin >> u >> v >> w ;
        dp[u][v] = min(w,dp[u][v]) ;
        dp[v][u] = min(w,dp[v][u]) ;
    }
    for (int k = 1 ; k <= n ; k++)
    {
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = 1 ; j <= n ;j++)
            {
                dp[i][j] = min (dp[i][j],dp[i][k]+dp[k][j]) ;
            }
        }
    }
    for (int i = 1 ; i <= n ; i++)
    {
        for (int j = 1 ; j <= n ; j++)
        cout << dp[i][j] << " " ;
        cout << endl ;
    }
}