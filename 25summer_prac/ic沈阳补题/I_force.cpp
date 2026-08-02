#include <bits/stdc++.h>
using namespace std ;
#define int long long
#define pb push_back
#define IOS ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
const int INF = LLONG_MAX ;
void solve ()
{
    int a , b ;
    cin >> b ;
    a = 1 ;
    int n = 1 + b ;
    vector <int> v  ;
    for (int i = 1 ; i * i <= n ; i++)
    {   
        if (i * i == n) {v.pb (i) ;}
        else if (n % i == 0 ) {v.pb(i) ;v.pb(n/i);}
    }
    sort (v.begin() , v.end()) ;
    if (v.size() == 2)
    {
        cout << b << endl ;
        return ;
    }int l = v.size() ;
    vector <int> dp (l+1 , INF) ;
    dp[0] = 0  ;
    
    for (int i = 1 ; i < l ; i ++)
    {
        for (int j = max (0LL , i - 300LL) ; j < i ;j++)
        {
            int cost = (v[i] - 1) / v[j] ;
            dp[i] = min (dp[i] , dp[j] + cost) ;
        }
    }
    cout << dp[l-1] << endl ;
}
signed main ()
{
    IOS ;
    int t ;
    cin >> t ;
    while (t--) solve(); 
}