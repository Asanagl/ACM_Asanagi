#include <bits/stdc++.h>
using namespace std ;
#define int long long 
#define pb push_back
const int MOD = 998244353 ;
vector <int> g[25] ;
vector <int> dp (20000007) ;
int n ;
int dfs (int k)
{
    int res = 0 ;
    if (dp[k] != -1) return dp[k] ;
    vector <int> p ;
    vector <int> du (n+1) ;
    bitset<25> bt (k) ;
    for (int i = 0 ; i < n ; i ++)
    {
        if (bt[i]) p.pb(i) ;
    }
    for (auto &it : p)
    {
        for (auto &j : g[it])
        {
            du[j]++ ;
        }
    }
    for (auto &it : p)
    {
        if (du[it] != 0) continue ;
        res += dfs(k - (1 << it)) ;
        res %= MOD ;
    }
    dp[k] = res ;
    return res ;
}
int topu()
{
    dp[0] = 1 ;
    for (int i = 1; i < (1 << n) ; i++)
    dp[i] = -1 ;
    int res = dfs ((1 << n) - 1) ;
    return res;
}
void solve ()
{
    cin >> n ;
    vector <int> p (n+1) ;
    for (int i =0 ; i < n ; i++ ) cin >> p[i] ;
    bool flag = true ;
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = i+1 ; j < n ; j++)
        {
            if (p[i] > p[j])
            {
                g[i].pb(j) ;
                flag = false ;
            }
        }
    }
    int ans = 1 ;
    if (flag)
    {
        for (int i = 2 ;i <= n ; i++)
        {
            ans *= i;
            ans %= MOD;
        }
        cout << ans << endl ;
        return;
    }
    ans = 2 * topu() ;
    ans %= MOD ;
    cout << ans << endl ;
}
signed main ()
{
    int t = 1 ;
    // cin >> t ;
    while (t--) solve() ;
}