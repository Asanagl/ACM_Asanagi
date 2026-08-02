#include <bits/stdc++.h>
using namespace std ;
#define int long long 
#define ld long double 
void solve ()
{
    int n ;
    cin >> n ;
    vector <ld> v (n+1) ;
    ld ans = LDBL_MAX ;
    v[0] = ans ;
    if (n == 1)
    {
        ld it ;
        cin >> it ;
        cout << fixed << setprecision(1) << it ;
        return ;
    }
    for (int i = 1 ; i <= n ; i ++)
    {
        cin >> v[i] ;
    } 
    sort (v.begin() , v.end() , greater<ld>()) ;
    for (ld k = 1 ; k < n ; k++)
    {
        vector <ld> cur (n+1) ;
        ld cnt = 0.0 ;
        for (ld i = 1 ; i <= n ; i ++)
        {
            if (i <= k)
            {
                cur[i] = (k - i + 1) + ( n - k ) / 2 ;
            } else cur[i] = n - i + 1 ;
            // cout << cur [i] << " cur " ;
        }
        sort(cur.begin() , cur.end()) ;
        for (int i = 1 ; i <= n ; i ++)
        {
            cnt += cur[i] * v[i] ;
        }
        ans = min (ans , cnt) ;
    }
    cout << fixed << setprecision(1) << ans << endl ; 
}
    

signed main ()
{
    int t = 1;
    // cin >> t ;
    while (t--) solve () ;
}