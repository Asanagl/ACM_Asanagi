#include <bits/stdc++.h>
using namespace std ;
#define pb push_back
using ll = long long ;

void Asanagi()
{   
    ll ans = 0;
    ll n;
    cin >> n;
    vector<int> c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    vector<vector<int>> vvi(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        vvi[u].push_back(v);
        vvi[v].push_back(u);
    }
    vector<int> p(n + 1, 0), gunmu;
    gunmu.reserve(n);
    queue<int> q;
    q.push(1);
    p[1] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        gunmu.push_back(u);
        for (int v : vvi[u])
        {
            if (v == p[u])
                continue;
            p[v] = u;
            q.push(v);
        }
    }
    vector<ll> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int u = gunmu[i];
        for (int v : vvi[u])
        {
            if (v == p[u])
                continue;
            if (c[u] == c[v])
            {
                dp[u] += 1 + dp[v];
            }
        }
        ans += dp[u];
    }
    cout << ans << endl;
}

int main ()
{
    int t ;
    cin >> t ;
    while (t--)
    {
        Asanagi();
    }
}




