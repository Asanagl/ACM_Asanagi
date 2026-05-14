#include <bits/stdc++.h>
using namespace std ;

#define int long long 
const int MOD = 998244353 ;
const int col = 26 ;

int power (int a , int b)
{
    int res = 1 ;
    a %= MOD ;
    while (b > 0)
    {
        if (b & 1) res = res * a % MOD ;
        a = a * a % MOD ;
        b >>= 1 ; 
    }
    return res ;
}

signed main ()
{
    int n ;
    cin >> n ;
    vector <int> v (n) ;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> v[i] ;
        v[i]-- ;
    }
    vector <int> ing (n , 0 ) ;
    for (int i = 0 ; i < n ; i++)
    ing[v[i]]++ ;
    // dp :prod[p] = prod[p] * ((COLORS - 1) * dp[u] % MOD) % MOD;
    vector <int> dp(n ,  1) , prod(n , 1);
    //tuo pu 
    queue<int> qe ;
    for (int i = 0 ; i < n ; i ++)
        if (ing[i]==0) qe.push(i) ;
    while (!qe.empty())
    {
        int u = qe.front() ; qe.pop() ;
        int p = v[u] ;
        prod[p] = prod[p] * ((col - 1) * dp[u] % MOD) % MOD ;
        ing[p]-- ;
        if (ing[p] == 0 )
        {
            dp[p] = prod[p] ;
            qe.push(p) ;
        }
    }
    for (int i = 0 ; i < n ; i++)
    {
        if (ing[i] > 0 )
        {
            dp[i] = prod[i];
        }
    }
    vector <bool> vis ( n , false) ;
    int ans = 1 ;
    for (int i = 0 ; i < n ; i++)
    {
        if (ing[i] > 0 && !vis[i])
        {
            vector <int> huan ;
            int cur = i ;
            while (!vis[cur])
            {
                vis[cur] = true ;
                huan.push_back(cur) ;
                cur = v[cur] ;
            }
            int k = huan.size() ;
            int huan_luxian = (power(col - 1 , k) + (k%2==0 ? (col-1):MOD - (col - 1) )) % MOD ;
            int tree_way = 1 ;
            for (auto &it : huan)
            tree_way = tree_way * dp[it] % MOD ;
            ans = ans * huan_luxian % MOD * tree_way % MOD ;
        }
        
    }
    cout << ans << endl ;
    
}